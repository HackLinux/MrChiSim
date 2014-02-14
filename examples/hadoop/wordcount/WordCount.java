import java.io.IOException;
import java.util.*;
import java.math.*;
import org.apache.commons.logging.*;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapred.*;
import org.apache.hadoop.util.*;

class MrChiSim {		
	public native String doFPGA(String in, String index);
	public native int create();
	public native int destroy();
	
}

public class WordCount {

	public static class Map extends MapReduceBase implements Mapper<LongWritable, Text, Text, IntWritable> {
		private final static IntWritable one = new IntWritable(1);
		private Text word = new Text();
		public static final Log LOG = LogFactory.getLog(Map.class);
		MrChiSim jni;

		@Override
		public void configure(JobConf job) {
			LOG.info("Starting Mapper");
			System.loadLibrary("MrChiSim");
			MrChiSim jni = new MrChiSim();
			int in = jni.create();
		}

		@Override
		public void close() {
			LOG.info("Finish Mapper");
			// int out = jni.destroy();
		}

		public String hexToASCII(String hex){       
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
	
		public String asciiToHex(String ascii){
	        StringBuilder hex = new StringBuilder();
	       
	        for (int i=0; i < ascii.length(); i++) {
	            hex.append(Integer.toHexString(ascii.charAt(i)));
	        }      
	        return hex.toString();
	    }

		public void map(LongWritable key, Text value, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException {
			String line = value.toString();
			StringTokenizer tokenizer = new StringTokenizer(line);
			Random randomGenerator = new Random();
			while (tokenizer.hasMoreTokens()) {
				long r = randomGenerator.nextLong();
				String index = Long.toString(Math.abs(r));
				String id = index.substring(0, 8);
				String res = jni.doFPGA(asciiToHex(tokenizer.nextToken()), id);
				LOG.info(res);
				word.set(hexToASCII(res.split(" ")[1].split("x")[1]));
				// output.collect(word, new IntWritable(Integer.parseInt(res.split(" ")[2].split("x")[1])));
				// word.set(tokenizer.nextToken());
				output.collect(word, one);
			}
			// int out = jni.destroy();
		}
	}

	public static class Reduce extends MapReduceBase implements Reducer<Text, IntWritable, Text, IntWritable> {
		public void reduce(Text key, Iterator<IntWritable> values, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException {
			int sum = 0;
			while (values.hasNext()) {
				sum += values.next().get();
			}
			output.collect(key, new IntWritable(sum));
		}
	}

	public static void main(String[] args) throws Exception {
		JobConf conf = new JobConf(WordCount.class);
		conf.setJobName("wordcount");

		conf.setOutputKeyClass(Text.class);
		conf.setOutputValueClass(IntWritable.class);

		conf.setMapperClass(Map.class);
		conf.setCombinerClass(Reduce.class);
		conf.setReducerClass(Reduce.class);

		conf.setInputFormat(TextInputFormat.class);
		conf.setOutputFormat(TextOutputFormat.class);

		FileInputFormat.setInputPaths(conf, new Path(args[0]));
		FileOutputFormat.setOutputPath(conf, new Path(args[1]));

		JobClient.runJob(conf);
	}
}