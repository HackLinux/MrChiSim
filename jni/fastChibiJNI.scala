import scala.util.Random

class ChibiJNI {
  // --- Native Send Methods
  @native def hexSend(hex : String, index : Int) : Int

  // --- Native Read Methods
  @native def hexRead(index : Int) : String

}

// --- JNI TESTING
object ChibiJNI extends App with hexFunctions {

  // --- Main method to test our native library
  time {doTesting}

}
trait hexFunctions {

def doTesting() {
  System.loadLibrary("ChibiJNI")
  val chi = new ChibiJNI
  var i = 0
  for(z <- 1 to 10000) {
    val index = Random.nextInt(100)
    
    // THIS IS NOT FAST BUT ENSURE CORRECT OPERATION
    // val i = Random.nextInt()
    // Create Unique Filename
    // val md = time{java.security.MessageDigest.getInstance("SHA-1")}
    // val filename = time{md.digest((i.toString+"OMGHAXLOL").getBytes("UTF-8")).map("%02x".format(_)).mkString.take(8)}

    chi.hexSend(index + " " + toHex("OMGHAXLOL" + Random.nextInt(100).toString), index)
    val res = chi.hexRead(index)

    val word = hexToAscii(res.split(" ")(1).split("x")(1)).trim
    // print(".")
  }
}

def time[R](block: => R): R = {
    val t0 = System.nanoTime()
    val result = block    // call-by-name
    val t1 = System.nanoTime()
    println("Elapsed time: " + (t1 - t0) + "ns")
    result
}

  /**
   * Parse hexRead Results
   */
   def parseHexRead(res : String, schema : Array[String]) : Any = {
    // Currently taliored to word count
    val tmp = res.split(" ")
    return fromHex(tmp(0), schema(0))
   }

   /**
    * Convert to HexSend
    */
    // def parseHexSend(in : String, schema : Array[String]) : String = {
    //   // TODO
    // }

  /**
   * Hex Transformation Functions
   */

   // --- To Hex Function
  implicit def toHex(in : Any) = in match {
    case n: Int => intToHex(n)
    case s: String => asciiToHex(s)
    case f: Float => floatToHex(f)
    case d: Double => doubleToHex(d)
  }

  def doubleToHex(in : Double) : String = {
    java.lang.Double.doubleToRawLongBits(in).toHexString
  }

  def floatToHex(in: Float) : String = {
    java.lang.Float.floatToRawIntBits(in).toHexString
  }

  def asciiToHex(in : String) : String = {
    in.toList.map(a => a.toByte).map("%02x".format(_)).mkString
  }

  def intToHex(in : Int) : String = {
    Integer.toHexString(in).toString
  }

  // --- From Hex Functions
  implicit def fromHex(in : String, inType : String) = inType match {
    case "String" => hexToAscii(in)
    case "Int" => hexToInt(in)
    case "Float" => hexToFloat(in)
    case "Double" => hexToDouble(in)
  }

  def hexToDouble(in : String) : Double = {
    java.lang.Double.longBitsToDouble(java.lang.Long.parseLong(in, 16))
  }

  def hexToFloat(in: String) : Float = {
    java.lang.Float.intBitsToFloat(
      Integer.parseInt(
        Integer.toBinaryString(
          Integer.parseInt(in,16)),2))
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