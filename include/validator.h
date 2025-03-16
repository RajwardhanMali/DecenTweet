#pragma once
#include <vector>
#include <string>
// here the logic for choosing the validator will be defined
// validator = choose(x) where x is some metric that is influenced as : x = W.Nc where W is reputation weight and N sub c is number of coins staked

struct ValidatorInfo{
    uint32_t user_id;
    int coins_staked;
    int reputation_metric;
};

namespace Validator{
    bool compare_validators(const ValidatorInfo& a, const ValidatorInfo& b);
    uint32_t choose_a_validator(std::vector<ValidatorInfo> validators);
}