//
// Created by gupta on 24-04-2020.
//

#ifndef ASSIGNMENT4_IOINPUT_H
#define ASSIGNMENT4_IOINPUT_H

#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

class IOInput {
public:
    int arrivalTime;
    int destTrack;
    int startTime;
    int endTime;
    IOInput(int arrivalTime, int destTrack);
    IOInput();
    int trackMovement;
    int waitTime;
};


#endif //ASSIGNMENT4_IOINPUT_H
