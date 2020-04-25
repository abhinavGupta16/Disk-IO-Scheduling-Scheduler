//
// Created by gupta on 25-04-2020.
//

#ifndef ASSIGNMENT4_CLOOK_H
#define ASSIGNMENT4_CLOOK_H

#include "IOScheduler.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class CLOOK : public IOScheduler {
private:
    deque<IOInput*> *currentQueue;
    int *track;
    int *direction;
    IOInput* searchSmallest();
    IOInput* searchInDirectionRight();
public:
    CLOOK(deque<IOInput*> *currentQueue, int *track, int *direction);
    CLOOK();
    IOInput* getNextInput() override;
};


#endif //ASSIGNMENT4_CLOOK_H
