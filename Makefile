# Target Compiler
SBT = sbt

# Make Commands
default: makeHardware makeJNI ScriptSetup

test: testHardware clean testJNI clean testScoobi clean


# Test Make Commands
testJNI: makeHardware makeJNI ScriptSetup
	/tmp/start-sim.sh
	cd jni; make run
	/tmp/stop-sim.sh

testHardware:
	cd hardware; make test

testScoobi: makeJNI makeHardware ScriptSetup
	cd examples/scoobi; make test

testHadoopWordCount: makeJNI makeHardware ScriptSetup
	/tmp/start-sim.sh
	cd examples/hadoop/wordcount; make run
	/tmp/stop-sim.sh

#Hardware Make Command
makeHardware:
	cd hardware; make

#JNI Make Command
makeJNI:
	cd jni; make


#SCOOBI Make Command
makeScoobi:
	cd examples/scoobi; make

ScriptSetup:
	cp ./scripts/*-sim.sh /tmp/.

# Clean Up	
clean:
	/tmp/stop-sim.sh
	$(SBT) clean
	cd jni; make clean
	cd hardware; make clean
	cd examples/scoobi; make clean
	cd examples/hadoop/wordcount; make clean
	$(RM) /tmp/*sim.sh
	$(RM) -r project
