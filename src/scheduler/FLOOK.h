//
// Created by gupta on 25-04-2020.
//

#ifndef ASSIGNMENT4_FLOOK_H
#define ASSIGNMENT4_FLOOK_H

#include "IOScheduler.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class FLOOK : public IOScheduler{
private:
    deque<struct IOInput *> **currentQueue;
    deque<IOInput*> *activeQueue;
    deque<IOInput*> activeQ;
    deque<IOInput*> *addQueue;
    int *track;
    int *direction;
    IOInput* searchInDirectionLeft();
    IOInput* searchInDirectionRight();
    void swap();
public:
    FLOOK(deque<IOInput*> **currentQueue, int *track, int *direction);
    FLOOK();
    IOInput* getNextInput() override;
    bool isActiveQueueEmpty() override;
};


#endif //ASSIGNMENT4_FLOOK_H
