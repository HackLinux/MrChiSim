import java.lang.*;
import java.util.*;
import java.math.*;

public class MrChiSim {
	static {
		System.loadLibrary("MrChiSim");
		}
		
	public static native String doFPGA(String in, String index);
	public static native int create();
	public static native int destroy();

	public static void main( String[] args ){
		int done = create();
		Random randomGenerator = new Random();
		for(int i = 0; i < 10000; i++) {
			long r = randomGenerator.nextLong();
			String index = Long.toString(Math.abs(r));
			String id = index.substring(0, 8);
			String res = doFPGA(asciiToHex("Hello"), id);
			System.out.print(".");
		}
		done = destroy();
		System.exit(0);
	}

	public static String hexToASCII(String hex){       
          if(hex.length()%2 != 0){
             System.err.println("requires EVEN number of chars");
             return null;
          }
          StringBuilder sb = new StringBuilder();               
          //Convert Hex 0232343536AB into two characters stream.
          for( int i=0; i < hex.length()-1; i+=2 ){
               /*
                * Grab the hex in pairs
                */
              String output = hex.substring(i, (i + 2));
              /*
               * Convert Hex to Decimal
               */
              int decimal = Integer.parseInt(output, 16);                 
              sb.append((char)decimal);             
          }           
          return sb.toString();
    } 
	
	public static String asciiToHex(String ascii){
        StringBuilder hex = new StringBuilder();
       
        for (int i=0; i < ascii.length(); i++) {
            hex.append(Integer.toHexString(ascii.charAt(i)));
        }      
        return hex.toString();
    }
}
