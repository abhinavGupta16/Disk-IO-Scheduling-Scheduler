//
// Created by gupta on 25-04-2020.
//

#include "SSTF.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

SSTF::SSTF(){};

SSTF::SSTF(deque<IOInput*> *currentQueue, int *track){
    this->currentQueue = currentQueue;
    this->track = track;
}

IOInput* SSTF::getNextInput(){
    IOInput* newIO = nullptr;
    int minDist = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < currentQueue->size(); i++){
        if(minDist > abs((*track) - currentQueue->at(i)->destTrack)){
            newIO = currentQueue->at(i);
            minDist = abs((*track) - currentQueue->at(i)->destTrack);
            minIndex = i;
        }
    }
    if(currentQueue->size() > 0)
        currentQueue->erase(currentQueue->begin() + minIndex);

    return newIO;
}