import com.nicta.scoobi.Scoobi._
import Reduction._

import scala.util.Random
import scala.sys.process._

class ChibiJNI {
  // --- Native Send Methods
  @native def hexSend(hex : String, index : Int) : Int

  // --- Native Read Methods
  @native def hexRead(index : Int) : String

}

object WordCount extends ScoobiApp {
	def run() {
		val lines = fromTextFile(args(0))

		val counts = lines.mapFlatten(_.split(" ").filter(_.length() > 1))
		  .map(WordMapper(_))
		  // .map(word => (word, 1))
		  .groupByKey
		  .combine(Sum.int)
		counts.toTextFile(args(1)).persist
	}

	def WordMapper(w : String) : (String, Int) = {

		// val startSim = Process("/tmp/start-sim.sh")
		// startSim.run

		System.loadLibrary("ChibiJNI")
		val chi = new ChibiJNI

		val index = Random.nextInt(100)
    
	    // THIS IS NOT FAST BUT ENSURE CORRECT OPERATION
	    // val i = Random.nextInt()
	    // Create Unique Filename
	    // val md = time{java.security.MessageDigest.getInstance("SHA-1")}
	    // val filename = time{md.digest((i.toString+"OMGHAXLOL").getBytes("UTF-8")).map("%02x".format(_)).mkString.take(8)}

	   	chi.hexSend(index + " " + asciiToHex(w), index)
	    val res = chi.hexRead(index)


		val word = hexToAscii(res.split(" ")(1).split("x")(1)).trim
		val num = hexToInt(res.split(" ")(2).split("x")(1))

		if(word.diff(w) != "") {
			println("Org: " + w + "\t" + "FPGA: " + word)
		}

		(word, num)
	}

	def asciiToHex(in : String) : String = {
		in.toList.map(a => a.toByte).map("%02x".format(_)).mkString
	}

	def hexToAscii(in: String) : String = {
		require(in.size % 2 == 0, "Odd hex length")
		val out = new StringBuilder
		for (i <- 0 until in.size by 2) {
		  val str = in.substring(i, i + 2)
		  out.append(Integer.parseInt(str, 16).toChar)
		}
		out.toString
	}

	def hexToInt(in : String) : Int = {
	    Integer.parseInt(in, 16)
	}

}
