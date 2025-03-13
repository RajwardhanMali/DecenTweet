#ifndef CONSENSUS_H
#define CONSENSUS_H

#include<iostream>
#include <unordered_map>

class Consensus {
public:
    static int getReputation(std::string validator);
    static bool validateBlock(std::string validator, int difficulty);
};

#endif
