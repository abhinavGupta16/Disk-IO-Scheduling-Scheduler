//
// Created by gupta on 25-04-2020.
//

#ifndef ASSIGNMENT4_LOOK_H
#define ASSIGNMENT4_LOOK_H

#include "IOScheduler.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class LOOK : public IOScheduler {
private:
    deque<IOInput*> *currentQueue;
    int *track;
    int *direction;
    IOInput* searchInDirectionLeft();
    IOInput* searchInDirectionRight();
public:
    LOOK(deque<IOInput*> *currentQueue, int *track, int *direction);
    LOOK();
    IOInput* getNextInput() override;
};


#endif //ASSIGNMENT4_LOOK_H
