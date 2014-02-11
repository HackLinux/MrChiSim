# Target Compiler
SBT = sbt

# Library Targets
JNILIB = LD_LIBRARY_PATH=/tmp/.

# Make Commands
default: makeWordCount

test: runWordCount

#WordCount Make Command
makeWordCount:
	cd wordcount; $(JNILIB) $(SBT) compile

runWordCount: makeWordCount
	/tmp/start-sim.sh
	cd wordcount; $(JNILIB) $(SBT) "run-main WordCount pnp-austen.txt output"
	/tmp/stop-sim.sh

# Clean Up	
clean:
	cd wordcount; $(SBT) clean && rm -rf output project
