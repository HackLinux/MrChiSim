package chibi.sim

import Chisel._
import chibi.controller._
import chibi.util._
import chibi.comm._

import Node._
import scala.collection.mutable.HashMap
import scala.util.Random


class ChibiSimulation[T <: Data, S <: Data](inAvro : T,
	outAvro: S, 
	inNullBundle : T, 
	outNullBundle : S, 
	fifoSizeCtl : Int, 
	numMapper : Int, 
	m : Int) extends Module {
	
	val io = new Bundle {
		val in_dat = inAvro.clone.asInput
		val in_val = Bool(INPUT)
		val out_dat = outAvro.clone.asOutput
		val out_val = Bool(OUTPUT)
	}
	// INPUT & OUTPUT FIFO
	val in_fifo = Module(new Fifo(inAvro, m)).io
	val out_fifo = Module(new Fifo(outAvro, m)).io

	// New Controller
	val crtler = Module(new Controller(inAvro,
		outAvro, 
		inNullBundle, 
		outNullBundle, 
		numMapper, 
		fifoSizeCtl)).io

	// val inBundle = inAvro.clone
	// inBundle("str") := io.in_dat

	// Input into fifo
	in_fifo.enq_dat := io.in_dat
	
	// Input controller from fifo
	crtler.rx_dat := in_fifo.deq_dat
	
	//Output Controller to Fifo
	out_fifo.enq_dat := crtler.tx_dat

	// Output from Fifo
	io.out_dat := out_fifo.deq_dat
	io.out_val := Bool(false)

	// Read in Data From Outside
	when (io.in_val && in_fifo.enq_rdy) {
		in_fifo.enq_val := Bool(true)
	} .otherwise {
		in_fifo.enq_val := Bool(false)
	}

	// Load Controller with Data
	when (in_fifo.deq_val) {
		in_fifo.deq_rdy := Bool(true)
		crtler.rx_val := Bool(true)
		
	} .otherwise {
		in_fifo.deq_rdy := Bool(false)
		crtler.rx_val := Bool(false)
	}

	// Load Output fifo with data from controllers
	when (crtler.tx_val && out_fifo.enq_rdy) {
		out_fifo.enq_val := Bool(true)
	} .otherwise {
		out_fifo.enq_val := Bool(false)
	}


	// Output to Outside	
	when (out_fifo.deq_val) {
		out_fifo.deq_rdy := Bool(true)
		io.out_val := Bool(true)
	} .otherwise {
		out_fifo.deq_rdy := Bool(false)
	}
}

class ChibiSimulationTests(c : ChibiSimulation[inAvroBundle, outAvroBundle]) extends Tester(c, Array(c.io)) {
	defTests {
		var allGood = true
		val vars = new HashMap[Node, Node]()
		for (i <- 1 until 100) {
			val num = i
			val id = Random.nextInt(10000)
			vars(c.io.in_dat.id) = UInt(id)
			vars(c.io.in_dat.str) = UInt(num)
			vars(c.io.in_val) = Bool(true)
			allGood = step(vars) && allGood
		}
		allGood
	}
}

object ChibiSimulation {
	// Create Bundles
	val inAvro = new inAvroBundle(16, 1, 0)
	val outAvro = new outAvroBundle(16, 1, 1)
	val inNullBundle = new inAvroBundle(16, 1, 0)
	val outNullBundle = new outAvroBundle(16, 1, 1)

	// Set Simulation Parameters
	val controlFifoSize = 2
	val numMappers = 2
	val headFifoSize = 2

	// Main
	def main(args: Array[String]) : Unit = {
		chiselMainTest(args,
			() => Module(new ChibiSimulation(inAvro,
				outAvro,
				inNullBundle,
				outNullBundle,
				controlFifoSize,
				numMappers,
				headFifoSize))) {
			c => new ChibiSimulationTests(c)
		}
	}
}