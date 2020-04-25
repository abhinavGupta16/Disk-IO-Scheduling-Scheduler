//
// Created by gupta on 25-04-2020.
//

#include "CLOOK.h"
#include <bits/stdc++.h>
#include <string>

using namespace std;

CLOOK::CLOOK(){};

CLOOK::CLOOK(deque<IOInput*> *currentQueue, int *track, int *direction){
    this->currentQueue = currentQueue;
    this->track = track;
    this->direction = direction;
}

IOInput* CLOOK::getNextInput(){
    if(currentQueue->size()==0)
        return nullptr;

    IOInput *nextIO = nullptr;

    nextIO = searchInDirectionRight();

    if(nextIO == nullptr){
        nextIO = searchSmallest();
    }

//    if(nextIO == nullptr && (*direction)==1){
//        nextIO = searchInDirectionLeft();
//    } else if(nextIO == nullptr && (*direction)==-1){
//        nextIO = searchInDirectionRight();
//    }

    return nextIO;
}

IOInput* CLOOK::searchInDirectionRight(){
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

IOInput* CLOOK::searchSmallest(){
    IOInput* newIO = new IOInput(-1, 0);
    int minDest = INT_MAX;
    for(int i = 0; i < currentQueue->size(); i++){
        if(minDest > currentQueue->at(i)->destTrack){
            newIO->destTrack = currentQueue->at(i)->destTrack;
            minDest = currentQueue->at(i)->destTrack;
        }
    }

    return newIO;
}
