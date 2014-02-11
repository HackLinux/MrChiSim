package chibi.comm

import Chisel._
import Node._
import scala.collection.mutable.HashMap
import util.Random

class StringBlockTests(c: StringTest) extends Tester(c, Array(c.io)) {
  defTests {
    var allGood = true
    val vars = new HashMap[Node, Node]()
    for (i <- 0 to 100) {
   		val num = Random.nextInt(10000)
   		val avroResult = Integer.parseInt(new StringBuilder(num.toHexString.length.toString).append(num.toHexString).toString, 16)
   		// Combined Test
    	vars(c.io.inCombined) = UInt(num)
    	vars(c.io.outCombined) = UInt(num)

    	// Decode Test
    	vars(c.io.inEncode) = UInt(num)
    	vars(c.io.outEncode) = UInt(avroResult)

    	// Encode Test
    	vars(c.io.inDecode) = UInt(avroResult)
    	vars(c.io.outDecode) = UInt(num)
    	allGood = step(vars) && allGood
	}
    allGood
	}
}	

class ZigZagBlockTests(c: ZigZagTest) extends Tester(c, Array(c.io)) {
  defTests {
    var allGood = true
    val vars = new HashMap[Node, Node]()
    for (i <- 0 to 100) {
   		val num = Random.nextInt(10000)
   		val avroResult = num*2
    	vars(c.io.inCombined) = UInt(num)
    	vars(c.io.outCombined) = UInt(num)

    	// Decode Test
    	vars(c.io.inEncode) = UInt(num)
    	vars(c.io.outEncode) = UInt(avroResult)

    	// Encode Test
    	vars(c.io.inDecode) = UInt(avroResult)
    	vars(c.io.outDecode) = UInt(num)
    	allGood = step(vars) && allGood
	}
    allGood
	}
}

class VarintBlockTests(c: VarintTest) extends Tester(c, Array(c.io)) {
  defTests {
    var allGood = true
    val vars = new HashMap[Node, Node]()
    for (i <- 0 to 100) {
   		val num = Random.nextInt(10000)
    	vars(c.io.inCombined) = UInt(num)
    	vars(c.io.outCombined) = UInt(num)
    	allGood = step(vars) && allGood
	}
    allGood
	}
}