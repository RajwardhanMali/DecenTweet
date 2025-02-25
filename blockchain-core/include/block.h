#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include "transaction.h"

class Block {
public:
    int index;
    std::string prevHash;
    std::string timestamp;
    std::vector<Transaction> transactions;
    std::string merkleRoot;
    std::string blockHash;
    std::string validatorSignature;

    // Constructor
    Block(int idx, std::string prev, std::vector<Transaction> txns);

    // Generate block hash
    std::string calculateHash() const;
};

#endif
