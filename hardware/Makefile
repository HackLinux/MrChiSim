# Target Compiler
CC = g++
SBT = sbt

# Compiler Flags:
HARDFLAGS = --backend v --genHarness
SSIMFLAGS = --backend c --genHarness
CSIMFLAGS = -std=c++11
SIMTESTFLAGS = --backend c --genHarness --compile --test

# Make Commands
default: CSim

test: testSim testCon testAvro

run:
	../scripts/start-sim.sh

# Test Hardware Design
testSim: SBTCompile
	$(SBT) "run-main chibi.sim.ChibiSimulation $(SIMTESTFLAGS)"

testCon: SBTCompile
	$(SBT) "run-main chibi.controller.Controller $(SIMTESTFLAGS)"

testAvro: SBTCompile
	$(SBT) "run-main chibi.test.AvroTest $(SIMTESTFLAGS)"

# Chisel Make Commands

CSim:
	cp ChibiSimulation /usr/bin/.

SimScript: SSim
	../scripts/SimulationScript.py

SSim: SBTCompile
	$(SBT) "run-main chibi.sim.ChibiSimulation $(SSIMFLAGS)"

SBTCompile:
	$(SBT) compile

# Clean Up	
clean:
	$(SBT) clean
	$(RM) -r project
	$(RM) *.cpp *.o *.h
	$(RM) ChibiSimulation*
	$(RM) /tmp/ChibiSimulation
	$(RM) Controller*
	$(RM) *Test*
