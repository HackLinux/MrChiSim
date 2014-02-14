# Target Compiler
JAVA = javac
JAR = jar
HADOOP = hadoop

# Target Name
NAME = WordCount

# Paths
HADOOP_LIB = /usr/local/hadoop

# HDFS IO
HDFS_IN = wordcount/input
HDFS_OUT = wordcount/output

# Hadoop Libraries
HADOOP_COMMON = $(HADOOP_LIB)/share/hadoop/common/hadoop-common-2.2.0.jar
HADOOP_MAPCLIENT = $(HADOOP_LIB)/share/hadoop/mapreduce/hadoop-mapreduce-client-core-2.2.0.jar
COMMON_CIL = $(HADOOP_LIB)/share/hadoop/common/lib/commons-cli-1.2.jar
COMMON_LOG = $(HADOOP_LIB)/share/hadoop/common/lib/commons-logging-1.1.1.jar

#FLAGS
JAR_FLAGS = -cvf
JAVA_FLAGS = -classpath $(HADOOP_COMMON):$(HADOOP_MAPCLIENT):$(COMMON_CIL):$(COMMON_LOG) -d

# Make Commands
default: makeJar

run: makeJar
	$(HADOOP) $(JAR) $(NAME).jar $(NAME) $(HDFS_IN) $(HDFS_OUT)


makeJar: makeClass
	$(JAR) $(JAR_FLAGS) $(NAME).jar -C $(NAME)_classes/ .

makeClass:
	mkdir -p $(NAME)_classes
	$(JAVA) $(JAVA_FLAGS) $(NAME)_classes $(NAME).java 

clean:
	$(HADOOP) fs -rmr $(HDFS_OUT)
	$(RM) -r $(NAME)_classes
	$(RM) $(NAME).jar

