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

void printOutput(deque<IOInput*> *ioRequests){
    for(int i = 0; i < ioRequests->size(); i++){
        printf("%5d: %5d %5d %5d\n", i, ioRequests->at(i)->arrivalTime, ioRequests->at(i)->startTime, ioRequests->at(i)->endTime);
    }
}