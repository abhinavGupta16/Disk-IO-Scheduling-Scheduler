iosched_abhinav_gupta: src/main.cpp
	g++ -g -std=c++11 src/utils/Helper.cpp src/scheduler/FIFO.cpp src/scheduler/SSTF.cpp src/IOInput.cpp -o iosched_abhinav_gupta
clean:
	rm -f iosched_abhinav_gupta *~