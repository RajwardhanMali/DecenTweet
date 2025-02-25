#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    std::string type; // Post, Like, Tip, Comment
    std::string metadata; // IPFS hash of post
    std::string signature;

    // Constructor
    Transaction(std::string sender, std::string receiver, std::string type, std::string metadata);

    // Generate transaction hash
    std::string calculateHash() const;
};

#endif
