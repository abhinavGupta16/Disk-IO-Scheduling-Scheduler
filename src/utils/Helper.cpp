//
// Created by gupta on 24-04-2020.
//

#include "Helper.h"

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <getopt.h>
#include "../IOInput.h"

using namespace std;

void convertStringToTokens(string line, vector<string> *tokens){
    size_t prev = 0, pos;
    while ((pos = line.find_first_of(" ", prev)) != string::npos) {
        if (pos > prev)
            tokens->push_back(line.substr(prev, pos - prev));
        prev = pos + 1;
    }
    if (prev < line.length())
        tokens->push_back(line.substr(prev, string::npos));
}

void readInputFile(string filename, deque<IOInput*> *ioRequests, deque<IOInput*> *output){
    vector<string> tokens;
    ifstream input(filename);
    string line;
    IOInput *ioInput;
    while(getline(input, line)) {
        if(line.at(0) == '#')
            continue;
        convertStringToTokens(line, &tokens);
        ioInput = new IOInput(stoi(tokens[0]), stoi(tokens[1]));
        ioRequests->push_back(ioInput);
        output->push_back(ioInput);
        tokens.clear();
    }
}

void printOutput(deque<IOInput*> *ioRequests, int totalTime, int trackMovement){
    int totalTrackMovement = 0;
    double totalWaitTime = 0.0;
    double totalTurnaroundTime = 0.0;
    int maxWaitTime = 0;
    IOInput *ioInput;

    for(int i = 0; i < ioRequests->size(); i++){
        ioInput = ioRequests->at(i);
//        totalTrackMovement += ioInput->trackMovement;
        totalWaitTime += (ioInput->startTime - ioInput->arrivalTime);
        totalTurnaroundTime += (ioInput->endTime - ioInput->arrivalTime);

        if((ioInput->startTime - ioInput->arrivalTime) > maxWaitTime){
            maxWaitTime = ioInput->startTime - ioInput->arrivalTime;
        }

        printf("%5d: %5d %5d %5d\n", i, ioInput->arrivalTime, ioInput->startTime, ioInput->endTime);
    }

    double ans = totalWaitTime /(double) ioRequests->size();

//    cout << totalWaitTime << " " << ioRequests->size() << endl;

    printf("SUM: %d %d %.2lf %.2lf %d\n",
           totalTime, trackMovement, (totalTurnaroundTime /(double) ioRequests->size()),
           (totalWaitTime /(double) ioRequests->size()), maxWaitTime);
}