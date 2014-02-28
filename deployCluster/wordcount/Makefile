main:
	start-sim.sh
	hadoop jar WordCount-assembly-1.0.jar books output1 scoobi
	sudo stop-sim.sh

setupEnv:
	sudo cp ChibiSimulation /usr/bin/.
	sudo cp libMrChiSim.so /usr/lib/.
	sudo cp start-sim.sh /usr/bin/.
	sudo cp stop-sim.sh /usr/bin/.
	mkdir /tmp/fifo

setupHadoop:
	hadoop dfs -mkdir books &>/dev/null
	hadoop dfs -copyFromLocal pnp-austen.txt books &>/dev/null

clean:
	sudo $(RM) /usr/bin/ChibiSimulation
	sudo $(RM) /usr/lib/libMrChiSim.so
	sudo $(RM) /usr/bin/start-sim.sh
	sudo $(RM) /usr/bin/stop-sim.sh
	$(RM) -rf /tmp/fifo /tmp/flag* &>/dev/null
	hadoop dfs -rmr output1 &>/dev/null

