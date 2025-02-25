#pragma once
#include "block.h"

namespace Crypto{
    int generateMerkleRoot(std::vector <Transaction> txns);
}