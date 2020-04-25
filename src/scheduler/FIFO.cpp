//
// Created by gupta on 24-04-2020.
//

#include "FIFO.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

FIFO::FIFO(deque<IOInput*> *currentQueue){
    this->currentQueue = currentQueue;
}

IOInput* FIFO::getNextInput(){
    IOInput *ioInput = nullptr;
    if(currentQueue->size()>0) {
        ioInput = currentQueue->front();
        currentQueue->pop_front();
    }

    return ioInput;
}