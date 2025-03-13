#pragma once
#include "transaction.h"
#include <openssl/sha.h>

namespace Crypto{
    std::string sha256(const std::string& data);
    std::string calculateMerkleRoot(const std::vector<Transaction>& transactions);
    std::string serializeTransaction(const Transaction& txn);
}