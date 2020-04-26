//
// Created by gupta on 25-04-2020.
//

#include "FLOOK.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

FLOOK::FLOOK(){};

FLOOK::FLOOK(deque<IOInput*> **currentQueue, int *track, int *direction){
    this->currentQueue = currentQueue;
    this->track = track;
    this->direction = direction;
    this->activeQueue = &activeQ;
}

IOInput* FLOOK::getNextInput(){

    if((*currentQueue)->size()==0 && activeQueue->size() == 0)
        return nullptr;

    IOInput *nextIO = nullptr;

    if(activeQueue->size() == 0)
        swap();

    if((*direction) == 1){
        nextIO = searchInDirectionRight();
    } else {
        nextIO = searchInDirectionLeft();
    }

    if(nextIO == nullptr && (*direction)==1){
        nextIO = searchInDirectionLeft();
    } else if(nextIO == nullptr && (*direction)==-1){
        nextIO = searchInDirectionRight();
    }

    return nextIO;
}

IOInput* FLOOK::searchInDirectionRight(){
    IOInput* newIO = nullptr;
    int minDist = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < activeQueue->size(); i++){
        if(minDist > abs((*track) - activeQueue->at(i)->destTrack) &&
           ((*track) <= activeQueue->at(i)->destTrack)){

            newIO = activeQueue->at(i);
            minDist = abs((*track) - activeQueue->at(i)->destTrack);
            minIndex = i;
        }
    }
    if(newIO!= nullptr)
        activeQueue->erase(activeQueue->begin() + minIndex);

    return newIO;
}

IOInput* FLOOK::searchInDirectionLeft(){
    IOInput* newIO = nullptr;
    int minDist = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < activeQueue->size(); i++){
        if(minDist > abs((*track) - activeQueue->at(i)->destTrack) &&
           ((*track) >= activeQueue->at(i)->destTrack)){

            newIO = activeQueue->at(i);
            minDist = abs((*track) - activeQueue->at(i)->destTrack);
            minIndex = i;
        }
    }
    if(newIO!= nullptr)
        activeQueue->erase(activeQueue->begin() + minIndex);

    return newIO;
}

void FLOOK::swap(){
    deque<IOInput*> *temp = *currentQueue;
    *currentQueue = activeQueue;
    activeQueue = temp;
}

bool FLOOK::isActiveQueueEmpty(){
    return activeQueue->size() == 0;
}