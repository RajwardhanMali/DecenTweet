#include "crypto.h"
#include <sstream>

Block::Block(int idx, std::string prev, std::vector<Transaction> txns) {
    index = idx;
    prevHash = prev;
    transactions = txns;
    timestamp = std::to_string(time(0)); // Current timestamp
    merkleRoot = Crypto::generateMerkleRoot(txns);
    blockHash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << prevHash << timestamp << merkleRoot;
    return "1";
}
