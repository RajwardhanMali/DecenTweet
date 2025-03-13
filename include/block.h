#pragma once

// a block in the chain will have the following data:
// metadata - block id, transaction(s), previous hash, block hash
#include "transaction.h"

class Block{
    int blockId;
    std::vector <Transaction> transactions;
    std::string previousHash;
    std::string currentHash;

    Block(std::vector <Transaction> transactions);
    // some helper fns to access the instance variables
    std::vector<Transaction> getTransactions();
    std::string getPreviousHash();
    std::string getCurrentHash();
};