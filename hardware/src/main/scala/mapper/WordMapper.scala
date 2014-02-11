package chibi.mapper

import Chisel._

/**
 * Mapper
 * 
 * This Mapper take the a word input and takes two cycles to produce
 * a Word and Integer(val = 1) output. This represents a poorly implemented
 * WordCount Mapper however it is used to test the Chibi Controller. 	 			
 *
 * @param 	inAvroBundle 	$inAvro		Input IO for the Mappers
 * @param 	outAvroBunde 	$outAvro 	Output IO for the Mappers 
 */
 
class WordMapper[T <: Data, S <: Data](inAvro : T, outAvro : S) extends Module {
	def counter(max : UInt) = {
		val x = Reg(init = UInt(0, max.getWidth))
		x := Mux(x === max, UInt(0), x + UInt(1))
		x
	}
	
	val io = new Bundle {
		val rx_dat = inAvro.clone.asInput
		val rx_rdy = Bool(OUTPUT)
		val rx_val = Bool(INPUT)
		val tx_dat = outAvro.clone.asOutput
		val tx_val = Bool(OUTPUT)
	}

	val outNullBundle = outAvro.clone
	outNullBundle("id") := UInt(0)
	outNullBundle("str") := UInt(0)
	outNullBundle("int") := UInt(0)
	io.tx_dat := outNullBundle

	val res = Mem(inAvro, 1)
	io.tx_val := Bool(false)
	val is_full = Reg(init = Bool(false))

	when(io.rx_val) {
		res(0) := io.rx_dat
		is_full := Bool(true)
	}

	when ((UInt(1) === counter(UInt(1))) && is_full) {
		io.tx_dat("id") := res(0)("id")
		io.tx_dat("str") := res(0)("str")
		io.tx_dat("int") := UInt(1)
		io.tx_val := Bool(true)
		is_full := Bool(false)
	}
	io.rx_rdy := !is_full
}