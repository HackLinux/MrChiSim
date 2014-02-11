package chibi.comm

import Chisel._

/**
 * inAvroBundle & inNullBundle
 *
 * This AvroBundle describes the Input
 *
 * @param Int $b_str	Number of String Bytes
 * @param Int $n_str 	Number of Strings
 * @param Int $n_int 	Number of Integers
 * @param Int $n_lng	Number of Longs
 * @param Int $n_flt	Number of Floats
 * @param Int $n_dbl 	Number of Doubles
 * @param Int $n_bol	Number of Bools	
 */
class inAvroBundle(
	b_str: Int, 
	n_str : Int, 
	n_int : Int
	) extends Bundle {

	//Identifer
	val id = UInt(width = 64)

	val str = UInt(width = 8*b_str*n_str)
	// val int = UInt(width = 32*n_int)
	// val lng = UInt(width = 64*n_lng)
	// val flt = UInt(width = 32*n_flt)
	// val dbl = UInt(width = 64*n_dbl)
	// val bol = UInt(width = 1*n_bol)
  	override def clone = { new inAvroBundle(b_str, n_str, n_int).asInstanceOf[this.type]}
}

class inNullBundle(
	b_str : Int,
	n_str : Int,
	n_int : Int
	) extends inAvroBundle(
		b_str : Int,
		n_str : Int,
		n_int : Int) {

	id := UInt(0)
	str := UInt(0)
	// int := UInt(0)
	// lng := UInt(0)
	// flt := UInt(0)
	// dbl := UInt(0)
	// bol := UInt(0)
  	override def clone = { new inNullBundle(b_str, n_str, n_int).asInstanceOf[this.type]}
}


/**
 * outAvroBundle & outNullBundle
 *
 * This AvroBundle describes the Output
 *
 * @param Int $b_str	Number of String Bytes
 * @param Int $n_str 	Number of Strings
 * @param Int $n_int 	Number of Integers
 * @param Int $n_lng	Number of Longs
 * @param Int $n_flt	Number of Floats
 * @param Int $n_dbl 	Number of Doubles
 * @param Int $n_bol	Number of Bools	
 */
class outAvroBundle(
	b_str: Int, 
	n_str : Int, 
	n_int : Int) extends Bundle {

	// Identifer
	val id = UInt(width = 32)

	val str = UInt(width = 8*b_str*n_str)
	val int = UInt(width = 32*n_int)
	// val lng = UInt(width = 64*n_lng)
	// val flt = UInt(width = 32*n_flt)
	// val dbl = UInt(width = 64*n_dbl)
	// val bol = UInt(width = 1*n_bol)
  	override def clone = { new outAvroBundle(b_str, n_str, n_int).asInstanceOf[this.type]}
}

class outNullBundle(
	b_str : Int,
	n_str : Int,
	n_int : Int
	) extends outAvroBundle(
		b_str : Int,
		n_str : Int,
		n_int : Int) {

	id := UInt(0)
	str := UInt(0)
	int := UInt(0)
	// lng := UInt(0)
	// flt := UInt(0)
	// dbl := UInt(0)
	// bol := UInt(0)
  	override def clone = { new outNullBundle(b_str, n_str, n_int).asInstanceOf[this.type]}
}