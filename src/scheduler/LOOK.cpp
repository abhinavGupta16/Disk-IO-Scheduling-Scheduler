//
// Created by gupta on 25-04-2020.
//

#include "LOOK.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

LOOK::LOOK(){};

LOOK::LOOK(deque<IOInput*> *currentQueue, int *track, int *direction){
    this->currentQueue = currentQueue;
    this->track = track;
    this->direction = direction;
}

IOInput* LOOK::getNextInput(){

    if(currentQueue->size()==0)
        return nullptr;

    IOInput *nextIO = nullptr;

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

IOInput* LOOK::searchInDirectionRight(){
    IOInput* newIO = nullptr;
    int minDist = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < currentQueue->size(); i++){
        if(minDist > abs((*track) - currentQueue->at(i)->destTrack) &&
           ((*track) <= currentQueue->at(i)->destTrack)){

            newIO = currentQueue->at(i);
            minDist = abs((*track) - currentQueue->at(i)->destTrack);
            minIndex = i;
        }
    }
    if(newIO!= nullptr)
        currentQueue->erase(currentQueue->begin() + minIndex);

    return newIO;
}

IOInput* LOOK::searchInDirectionLeft(){
    IOInput* newIO = nullptr;
    int minDist = INT_MAX;
    int minIndex = 0;
    for(int i = 0; i < currentQueue->size(); i++){
        if(minDist > abs((*track) - currentQueue->at(i)->destTrack) &&
           ((*track) >= currentQueue->at(i)->destTrack)){

            newIO = currentQueue->at(i);
            minDist = abs((*track) - currentQueue->at(i)->destTrack);
            minIndex = i;
        }
    }
    if(newIO!= nullptr)
        currentQueue->erase(currentQueue->begin() + minIndex);

    return newIO;
}