package chibi.controller

import Chisel._
import chibi.comm._

import Node._
import scala.collection.mutable.HashMap
import scala.util.Random

/**
 * IOController
 *
 * TODO :	*Make Work
 *
 *
 * @param	inAvroBundle	$inAvro 		Input Avro Bundle
 * @param	outAvroBundle	$outAvro 		Output Avro Bundle
 * @param	inAvroBundle	$inNullBundle	Null Input Bundle
 * @param	outAvroBundle	$outNullBundle	Null Output Bundle
 * @param 	Int 			$b_str			Number of String Bytes
 * @param 	Int 			$n_str 			Number of Strings
 * @param 	Int 			$n_int	 		Number of Integers
 * @param 	Int 			$n_lng			Number of Longs
 * @param 	Int 			$n_flt			Number of Floats
 * @param 	Int 			$n_dbl	 		Number of Doubles
 * @param 	Int 			$n_bol			Number of Bools	
 */
class IOController[T <:Data, S <:Data](
	inAvro : T,
	outAvro : S,
	inNullBundle : T,
	outNullBundle : S,
	b_str : Int,
	n_str : Int,
	n_int : Int,
	n_lng : Int,
	n_flt : Int,
	n_dbl : Int,
	n_bol : Int,
	bw : Int
	) extends Module {

	val io = new Bundle {

		// HADOOP FIFO
		val rx_hd_dat = UInt(width = 8*bw)
		val rx_hd_rdy = Bool(OUTPUT)
		val rx_hd_cnt = UInt(OUTPUT, width = log2Up(bw)+1)
		val tx_hd_dat = UInt(OUTPUT, width = b_str*n_str + 40*n_int + 80*n_lng + 32*n_flt + 64*n_dbl + 8*n_bol)
		val tx_hd_rdy = Bool(OUTPUT)

		// MAPPER CONTROLLER
		// OUTPUT
		val res_mp_dat = outAvro.clone.asOutput
		val res_mp_rdy = Bool(OUTPUT)

		// INPUT
		val in_mp_dat = inAvro.clone.asOutput
		val in_mp_val = Bool(OUTPUT)
	}

	val nullUInt = UInt(0)

	// STRING
	if (n_str > 0) {
		// OUTPUT
		val en_str = Vec.fill(n_str){Module(new encodeStringBlock(b_str)).io}
		val out_str = UInt(width = 8*n_str + b_str*n_str)
		
		val str_dat = UInt(width = b_str*n_str)
		str_dat := io.res_mp_dat("str")
		for (i <- 0 until n_str) {
			when (io.res_mp_rdy) {
				en_str(i).in := str_dat(i*b_str + (b_str-1), i*b_str)
				out_str := Cat(out_str(b_str*i, 0), en_str(i).out)
			} .otherwise {
				en_str(i).in := nullUInt
				out_str := nullUInt
			}
		}
		// io.tx_hd_dat := Cat(io.tx_hd_dat, out_str)
		// INPUT
		// val de_str = Vec.fill(n_str){Module(new decodeStringBlock(b_str)).io}
	}

	// INTEGER
	if (n_int > 0) {
		val en_va_int = Vec.fill(n_int){Module (new encodeVarintBlock(1)).io}
		// val de_va_int = Vec.fill(n_int){Module (new decodeVarintBlock(1)).io}
		val en_zg_int = Vec.fill(n_int){Module (new encodeZigZagIntBlock(1)).io}
		// val de_zg_int = Vec.fill(n_int){Module (new decodeZigZagIntBlock(1)).io}
		val out_int = UInt(width = 40*n_int)

		val int_dat = UInt(width = 32*n_int)
		int_dat := io.res_mp_dat("int")
		for (i <- 0 until n_int) {
			when (io.res_mp_rdy) {
				en_zg_int(i).in := int_dat(i*32 + 31, i*32)
				en_va_int(i).in := en_zg_int(i).out
				out_int := Cat(out_int(32*i, 0), en_va_int(i).out)
			} .otherwise {
				en_zg_int(i).in := nullUInt
				en_va_int(i).in := nullUInt
				out_int := nullUInt
			}
		}
		// io.tx_hd_dat := Cat(io.tx_hd_dat, out_int)
	}

	// LONG
	if (n_lng > 0) {
		val en_va_lng = Vec.fill(n_lng){Module (new encodeVarintBlock(2)).io}
		val de_va_lng = Vec.fill(n_lng){Module (new decodeVarintBlock(2)).io}
		val en_zg_lng = Vec.fill(n_lng){Module (new encodeZigZagIntBlock(2)).io}
		val de_zg_lng = Vec.fill(n_lng){Module (new decodeZigZagIntBlock(2)).io}
		val out_lng = UInt(width = 40*n_lng)

		val lng_dat = UInt(width = 64*n_lng)
		lng_dat := io.res_mp_dat("lng")
		when (io.res_mp_rdy) {
			for (i <- 0 until n_lng) {
				en_zg_lng(i).in := lng_dat(i*64 + 63, i*64 )
				en_va_lng(i).in := en_zg_lng(i).out
				out_lng := Cat(out_lng(64*i, 0), en_va_lng(i).out)
			}
		}
		// io.tx_hd_dat := Cat(io.tx_hd_dat, out_lng)	
	}

	// FLOAT
	if (n_flt > 0) {
		val out_float = UInt(width = 32*n_flt)

		val flt_dat = UInt(width = 32*n_flt)
		flt_dat := io.res_mp_dat("flt")
		when (io.res_mp_rdy) {
			for (i <- 0 until n_flt) {
				out_float := Cat(out_float(32*i, 0), flt_dat(32*i+31, 32*i))
			}
		}
		// io.tx_hd_dat := Cat(io.tx_hd_dat, out_float)
	}

	// DOUBLE
	if (n_dbl > 0) {
		val out_double = UInt(width = 64*n_dbl)
		
		val dbl_dat = UInt(width = 64*n_dbl)
		dbl_dat := io.res_mp_dat("dbl")
		when (io.res_mp_rdy) {
			for (i <- 0 until n_dbl) {
				out_double := Cat(out_double(64*i, 0), dbl_dat(64*i+63, 64*i))
			}
		}
		// io.tx_hd_dat := Cat(io.tx_hd_dat, out_double)
	}

	//BOOLEAN
	if(n_bol > 0) {
		val out_bool = UInt(width = 8*n_bol)
		val bool_dat = UInt(width = n_bol)
		bool_dat := io.res_mp_dat("bol")
		when (io.res_mp_rdy) {
			for (i <- 0 until n_bol) {
				out_bool := Cat(out_bool(8*i, 0), bool_dat(i+1, i) & UInt(255))
			}
		}
		// io.tx_hd_dat := Cat(io.tx_hd_dat, out_bool)
	}
	io.tx_hd_dat := nullUInt
}

class IOControllerTests(c : IOController[inAvroBundle, outAvroBundle]) extends Tester(c, Array(c.io)) {
	defTests {
		var allGood = true
		val vars = new HashMap[Node, Node]()
		for (i <- 1 until 10) {
			val num = i
    		allGood = step(vars) && allGood
		}
		allGood
	}
}

object IOController {
  def main(args: Array[String]): Unit = {
    chiselMainTest(args,
      () => Module(new IOController(new inAvroBundle(4, 1, 0),
      								new outAvroBundle(4, 1, 1),
      								new inNullBundle(4, 1, 0),
      								new outNullBundle(4, 1, 1),
      								4,
      								1,
      								1,
      								0,
      								0,
      								0,
      								0,
      								1))) {
    	c => new IOControllerTests(c)
    }
  }
}
