//
// Created by gupta on 25-04-2020.
//

#ifndef ASSIGNMENT4_IOSCHEDULER_H
#define ASSIGNMENT4_IOSCHEDULER_H

#include <bits/stdc++.h>
#include "../IOInput.h"

using namespace std;

class IOScheduler {
public:
    virtual IOInput* getNextInput() = 0;
    virtual bool isActiveQueueEmpty(){
        return true;
    };
};


#endif //ASSIGNMENT4_IOSCHEDULER_H
