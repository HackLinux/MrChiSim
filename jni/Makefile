# Target Compiler
JAVAH = javah
SCALAC = scalac
SCALA = scala
CC = g++

# Libraries
JAVA_HOME=/usr/lib/jvm/java-7-openjdk-amd64
SCALA_CP=/usr/share/java/scala-library.jar

# Compiler Flags:
CFLAGS = -Wall
LIBFLAGS = -std=c++11 -shared -fPIC
INCFLAGS = -I/usr/include -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux
JNILIB = -Djava.library.path=$(shell pwd)

# Make Commands
default: fastJNI

run:
	$(SCALA) $(JNILIB) -cp . ChibiJNI

# Fast JNI Make Commands
fastJNI: fastCPPChibi

fastCPPChibi: fastJHeader
	$(CC) $(LIBFLAGS) $(CFLAGS) $(INCFLAGS) fastChibiJNI.cpp -o libChibiJNI.so
	cp libChibiJNI.so /tmp/.

fastJHeader: fastScalaJNI
	$(JAVAH) -cp $(SCALA_CP):. ChibiJNI

fastScalaJNI: fastChibiJNI.scala
	$(SCALAC) fastChibiJNI.scala

# Robust JNI Make Commands
robustJNI: robustCPPChibi

robustCPPChibi: robustJHeader
	$(CC) $(LIBFLAGS) $(CFLAGS) $(INCFLAGS) robustChibiJNI.cpp -o libChibiJNI.so
	cp libChibiJNI.so /tmp/.
	mkdir /tmp/simIn
	mkdir /tmp/simOut

robustJHeader: robustScalaJNI
	$(JAVAH) -cp $(SCALA_CP):. ChibiJNI

robustScalaJNI: robustChibiJNI.scala
	$(SCALAC) robustChibiJNI.scala

# Clean Up	
clean:
	$(RM) *.class *.so *.h
	$(RM) /tmp/libChibiJNI.so
	$(RM) /tmp/simIn.bin /tmp/simOut.bin
	$(RM) -r /tmp/simIn /tmp/simOut
