# Target Compiler
JAVAH = javah
JAVAC = javac
CC = g++

# Libraries
JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64

# Compiler Flags:
CFLAGS = -Wall
LIBFLAGS = -std=c++11 -shared -fPIC
INCFLAGS = -I/usr/include -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux
JNILIB = -Djava.library.path=$(shell pwd)

# Make Commands
default: jni

run: jni
	java $(JNILIB) -cp . MrChiSim

# Java JNI
jni: header
	$(CC) $(LIBFLAGS) $(CFLAGS) $(INCFLAGS) MrChiSim.cpp -o libMrChiSim.so
	cp libMrChiSim.so /usr/local/hadoop/lib/native/.
	cp libMrChiSim.so /tmp/.
	mkdir -p /tmp/fifo

header: compile
	javah MrChiSim

compile:
	javac MrChiSim.java

# Clean Up	
clean:
	$(RM) *.class *.so *.h
	$(RM) /tmp/libMrChiSim.so /usr/local/hadoop/lib/native/libMrChiSim.so
	$(RM) -rf /tmp/fifo
