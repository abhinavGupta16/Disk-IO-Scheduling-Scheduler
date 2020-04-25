//
// Created by gupta on 24-04-2020.
//

#include "IOInput.h"
#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

IOInput::IOInput(int arrivalTime, int destTrack){
    this->arrivalTime = arrivalTime;
    this->destTrack = destTrack;
    this->startTime = 0;
    this->endTime = 0;
    this->trackMovement = 0;
    this->waitTime = 0;
}