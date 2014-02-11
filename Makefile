# Target Compiler
SBT = sbt

# Make Commands
default: makeFastHardware makeFastJNI ScriptSetup

test: testFastHardware clean testRobustHardware clean testFastJNI clean testRobustJNI clean testFastScoobi clean testRobustScoobi clean


# Test Make Commands
testFastJNI: makeFastHardware makeFastJNI ScriptSetup
	/tmp/start-sim.sh
	cd jni; make run
	/tmp/stop-sim.sh

testRobustJNI: makeRobustHardware makeRobustJNI ScriptSetup
	/tmp/start-sim.sh
	cd jni; make run
	/tmp/stop-sim.sh

testHardware:
	cd hardware; make test

testFastScoobi: makeFastJNI makeFastHardware ScriptSetup
	cd examples/scoobi; make test

testRobustScoobi: makeRobustJNI makeRobustHardware ScriptSetup
	cd examples/scoobi; make test

#Hardware Make Command
makeFastHardware:
	cd hardware; make

makeRobustHardware:
	cd hardware; make robustCSim

#JNI Make Command
makeFastJNI:
	cd jni; make

makeRobustJNI:
	cd jni; make robustJNI

#SCOOBI Make Command
makeScoobi:
	cd examples/scoobi; make

ScriptSetup:
	cp ./scripts/*-sim.sh /tmp/.

# Clean Up	
clean:
	$(SBT) clean
	cd jni; make clean
	cd hardware; make clean
	cd examples/scoobi; make clean
	$(RM) /tmp/*sim.sh
	$(RM) -r project
