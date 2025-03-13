#include "crypto.h"

Block::Block(std::vector<Transaction> transactions){
    this->transactions = transactions;
    Crypto::sha256(transactions);
}

std::string Block::getPreviousHash(){
    return previousHash;
}

std::string Block::getCurrentHash(){
    return currentHash;
}

std::vector<Transaction> Block::getTransactions(){
    return transactions;
}

