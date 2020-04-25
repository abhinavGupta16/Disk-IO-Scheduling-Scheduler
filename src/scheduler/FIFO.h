//
// Created by gupta on 24-04-2020.
//

#ifndef ASSIGNMENT4_FIFO_H
#define ASSIGNMENT4_FIFO_H

#include "IOScheduler.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class FIFO : public IOScheduler{
private:
    deque<IOInput*> *currentQueue;
public:
    FIFO(deque<IOInput*> *currentQueue);
    IOInput* getNextInput() override;
};


#endif //ASSIGNMENT4_FIFO_H
