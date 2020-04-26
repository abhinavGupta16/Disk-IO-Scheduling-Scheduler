iosched_abhinav_gupta: src/main.cpp
	g++ -g -std=c++11 src/utils/Helper.cpp src/scheduler/FIFO.cpp src/scheduler/LOOK.cpp src/scheduler/SSTF.cpp src/scheduler/CLOOK.cpp src/scheduler/FLOOK.cpp src/IOInput.cpp src/main.cpp -o iosched_abhinav_gupta
clean:
	rm -f iosched_abhinav_gupta *~
