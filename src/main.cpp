#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include "utils/Helper.h"
#include "IOInput.h"
#include "scheduler/FIFO.h"
#include "scheduler/SSTF.h"
#include "scheduler/LOOK.h"
#include "scheduler/CLOOK.h"
#include "scheduler/IOScheduler.h"
#include "scheduler/FLOOK.h"
#include <getopt.h>

using namespace std;

bool verbose = false;
IOScheduler *scheduler;
deque<IOInput*> currentQueue;
deque<IOInput*> *currentQueuePtr = &currentQueue;
int track;
int direction;

void parseArguments(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    parseArguments(argc, argv);
    string inputFilename = argv[optind];

    deque<IOInput*> ioRequests;
    deque<IOInput*> outputs;

    readInputFile(inputFilename, &ioRequests, &outputs);

    direction = 1;
    track = 0;
    int currentTime = 0;
    int trackMovement = 0;
    int prevStartTime = -1;
    IOInput *currentInput = nullptr;

    while(ioRequests.size() > 0 || currentQueuePtr->size() > 0 || currentInput != nullptr || !scheduler->isActiveQueueEmpty()){
        for(int i = 0; i < ioRequests.size(); i++) {
            if (ioRequests.at(i)->arrivalTime == currentTime) {
                currentQueuePtr->push_back(ioRequests.at(i));
                ioRequests.pop_front();
            } else {
                break;
            }
        }

        if(currentQueuePtr->size()==0 && currentInput == nullptr && scheduler->isActiveQueueEmpty()){
            currentTime++;
            continue;
        }

        if(currentInput == nullptr){
            currentInput = scheduler->getNextInput();
            if(currentInput->arrivalTime == -1){
                prevStartTime = currentTime;
            } else if(prevStartTime != -1) {
                currentInput->startTime = prevStartTime;
                prevStartTime = -1;
            } else {
                currentInput->startTime = currentTime;
            }
        }

        if(currentInput->destTrack < track){
            direction = -1;
            track--;
            currentTime++;
            trackMovement++;
        } else if(currentInput->destTrack > track) {
            direction = 1;
            track++;
            currentTime++;
            trackMovement++;
        } else {
            currentInput->endTime = currentTime;
            currentInput = nullptr;
        }
    }
    printOutput(&outputs, currentTime, trackMovement);
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
                        scheduler = new FIFO(currentQueuePtr);
                        break;
                    case 'j':  scheduler = new SSTF(currentQueuePtr, &track);
                        break;
                    case 's':  scheduler = new LOOK(currentQueuePtr, &track, &direction);
                        break;
                    case 'c':  scheduler = new CLOOK(currentQueuePtr, &track, &direction);
                        break;
                    case 'f':  scheduler = new FLOOK(&currentQueuePtr, &track, &direction);
                        break;
                }
                break;
            default:
                abort ();
        }

//    if(!schedulerInitialized)
//        pager = new FIFO(&frameTable);
}