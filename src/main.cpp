#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "utils/Helper.h"
#include "IOInput.h"
#include "scheduler/FIFO.h"
#include "scheduler/SSTF.h"
#include "scheduler/IOScheduler.h"
#include <getopt.h>

using namespace std;

bool verbose = false;
IOScheduler *scheduler;
deque<IOInput*> currentQueue;
int track;

void parseArguments(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    parseArguments(argc, argv);
    string inputFilename = argv[optind];

    deque<IOInput*> ioRequests;
    deque<IOInput*> outputs;

    readInputFile(inputFilename, &ioRequests, &outputs);

    int direction = 1;
    track = 0;
    int currentTime = 0;
    IOInput *currentInput = nullptr;

    while(ioRequests.size() > 0 || currentQueue.size() > 0 || currentInput != nullptr){
        for(int i = 0; i < ioRequests.size(); i++) {
            if (ioRequests.at(i)->arrivalTime == currentTime) {
                currentQueue.push_back(ioRequests.at(i));
                ioRequests.pop_front();
            } else {
                break;
            }
        }

        if(currentQueue.size()==0 && currentInput == nullptr){
            currentTime++;
            continue;
        }

        if(currentInput == nullptr){
            currentInput = scheduler->getNextInput();
            currentInput->startTime = currentTime;
        }

        if(currentInput->destTrack < track){
            direction = -1;
            track--;
            currentTime++;
        } else if(currentInput->destTrack > track) {
            direction = 1;
            track++;
            currentTime++;
        } else {
            currentInput->endTime = currentTime;
            currentInput = nullptr;
        }
    }
    printOutput(&outputs);
    return 0;
}

void parseArguments(int argc, char *argv[]){
    int c;
    bool schedulerInitialized = false;
    while ((c = getopt (argc, argv, "vqfs:")) != -1)
        switch (c)
        {
            case 'v':
                verbose = true;
                break;
            case 's':
                switch(optarg[0]) {
                    case 'i':
                        scheduler = new FIFO(&currentQueue);
                        break;
                    case 'j':  scheduler = new SSTF(&currentQueue, &track);
                        break;
                }
                break;
            default:
                abort ();
        }

//    if(!schedulerInitialized)
//        pager = new FIFO(&frameTable);
}