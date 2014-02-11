package chibi.controller

import Chisel._
import chibi.comm._
import chibi.util._
import chibi.mapper._

import Node._
import scala.collection.mutable.HashMap
import scala.util.Random

/**
 * Controller
 * 
 * This controller is responsible to taking the bundle input from the IOBlock.
 * The controller distribues the data to a free FIFO which is linked to a mapper.
 * Once the mapper requires input it deqs the data from the FIFO and routes it to
 * the mapper. When a mapper finishes its computation it signals the controller
 * which enqs the result to an output FIFO. The controller then selects a FIFO and
 * deqs its data to output back to the IOBlock.
 * 		 			
 *
 * @param	inAvroBundle 	$inAvro			Input IO for the Mappers
 * @param	outAvroBundle 	$outAvro 		Output IO for the Mappers
 * @param	inAvroBundle	$inNullBundle	Null Input Bundle
 * @param	outAvroBundle	$outNullBundle	Null Output Bundle
 * @param	Int 			$n_int 			Number of Mappers/FIFO
 * @param	Int 			$n_lng			Amount of Memory for each FIFO
 */

class Controller[T <: Data, S <: Data](
	inAvro : T, 
	outAvro : S, 
	inNullBundle : T, 
	outNullBundle : S, 
	n : Int, 
	m: Int
	) extends Module {

	val io = new Bundle {
		val rx_dat = inAvro.clone.asInput
		val rx_val = Bool(INPUT)
		val tx_dat = outAvro.clone.asOutput
		val tx_val = Bool(OUTPUT)
	}

	io.tx_dat := outNullBundle
	io.tx_val := Bool(false)

	// COUNTERS
	val inCounter = Reg(init = UInt(0, UInt(n).getWidth))

	// INPUT FIFO
	val f_in = Vec.fill(n){Module(new Fifo(inAvro, m)).io}

	// OUTPUT FIFO
	val f_out = Vec.fill(n){Module(new Fifo(outAvro, m)).io}

	// MAPPERS
	val map = Vec.fill(n){Module(new WordMapper(inAvro, outAvro)).io}

	val f_out_deq_rdy = Vec.fill(n){UInt(width = 1)}
	for (i <- 0 until n) {
		f_out_deq_rdy(i) := f_out(i).deq_val.toBits().toUInt()
	}

	val index : UInt = f_out_deq_rdy.lastIndexWhere((a : UInt) => (a === UInt(1)))


	for (i <- 0 until n) {
		// SET INPUT TO FIFO
		when (UInt(i) === inCounter && io.rx_val && f_in(i).enq_rdy) {
			f_in(i).enq_val := Bool(true)
			f_in(i).enq_dat := io.rx_dat
			inCounter := Mux(inCounter === UInt(n-1), UInt(0), inCounter + UInt(1))
		} .otherwise {
			f_in(i).enq_val := Bool(false)
			f_in(i).enq_dat := inNullBundle
		}

		// LOAD MAP INPUT WITH FIFO VALUE
		when (map(i).rx_rdy && f_in(i).deq_val) {
			f_in(i).deq_rdy := Bool(true) 
			map(i).rx_dat := f_in(i).deq_dat
			map(i).rx_val := Bool(true)
		} .otherwise {
			f_in(i).deq_rdy := Bool(false)
			map(i).rx_val := Bool(false)
			map(i).rx_dat := inNullBundle
		}
	
		// LOAD MAP OUTPUT TO FIFO
		when (map(i).tx_val && f_out(i).enq_rdy) {
			f_out(i).enq_val := Bool(true)
			f_out(i).enq_dat := map(i).tx_dat
		} .otherwise {
			f_out(i).enq_val := Bool(false)
			f_out(i).enq_dat := outNullBundle
		}

		
		// OUTPUT FROM FIFO TO IOBLOCK
		when (UInt(i) === index && (f_out(i).deq_val)){
			f_out(i).deq_rdy := Bool(true)
			io.tx_dat := f_out(i).deq_dat
			io.tx_val := Bool(true)
		} .otherwise {
			f_out(i).deq_rdy := Bool(false)
		}
	}
}


class ControllerTests(c : Controller[inAvroBundle, outAvroBundle]) extends Tester(c, Array(c.io)) {
	defTests {
		var allGood = true
		val vars = new HashMap[Node, Node]()
		for (i <- 1 until 105) {
			val id = Random.nextInt(1000)
			if (i < 100) {
				val num = i
				vars(c.io.rx_dat.id) = UInt(id)
				vars(c.io.rx_dat.str) = UInt(num)
    			vars(c.io.rx_val) = Bool(true)
    		} else {
    			val num = 0
    			vars(c.io.rx_dat.id) = UInt(0)
				vars(c.io.rx_dat.str) = UInt(num)
    			vars(c.io.rx_val) = Bool(false)
    		}
    		allGood = step(vars) && allGood
		}
		allGood
	}
}

object Controller {
  def main(args: Array[String]): Unit = {
    chiselMainTest(args,
      () => Module(new Controller(	new inAvroBundle(4, 1, 0), 
      								new outAvroBundle(4, 1, 1), 
      								new inNullBundle(4, 1, 0), 
      								new outNullBundle(4, 1, 1),
      								2, 
      								2))) {
    	c => new ControllerTests(c)
    }
  }
}
