//
// Created by gupta on 25-04-2020.
//

#ifndef ASSIGNMENT4_SSTF_H
#define ASSIGNMENT4_SSTF_H

#include "IOScheduler.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class SSTF : public IOScheduler{
private:
    deque<IOInput*> *currentQueue;
    int *track;
public:
    SSTF(deque<IOInput*> *currentQueue, int *track);
    SSTF();
    IOInput* getNextInput() override;
};


#endif //ASSIGNMENT4_SSTF_H
