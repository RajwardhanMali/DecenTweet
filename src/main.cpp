#include "consensus.h"
#include "validator.h"

int main(){
    Blockchain chain(23320215032025);

    std::vector<ValidatorInfo> validators = {
        ValidatorInfo{880837, 100, 0},
        ValidatorInfo{205251, 10, 70},
        ValidatorInfo{569298, 50, 40}
    };

    uint32_t selected_validator_id = Validator::choose_a_validator(validators);

    // std::cout << "Validator chosen: " << selected_validator_id << std::endl;

    std::vector<Transaction> transactions;
    Transaction txn;
    txn.interaction_type = Platform_Interaction_Type::Post;
    txn.post = Post{
                Post_Interaction_Type::Create, 123434, 1, 10, 0, "https://firestore", "https://hiya.jpg", {"https://comment_id1"}
    };
    txn.comment = Comment{
                Comment_Interaction_Type::Create, 0, 0, 0, 0, 0, 0, "", "", {""}
    };
    txn.vote = Vote{false, false, 0, 0, false};
    txn.wallet = Wallet{
                Wallet_Interaction_Type::NA, "wallet_public_key", "wallet_address", 100
    };
    txn.transaction_id = 1;
    txn.transaction_time = 18010214032025; //hr_min_sec_day_month_year
    txn.user_id = 12345;
    txn.mod_stat = Moderation_Status::Review_Needed;
    txn.signature = "wallet_private_key";

    Transaction txn2;
    txn2.interaction_type = Platform_Interaction_Type::Comment;
    txn2.post = Post{
                Post_Interaction_Type::Create, 0, 0, 0, 0, "", "", {""}
    };
    txn2.comment = Comment{
                Comment_Interaction_Type::Create, 59000, 123434, 0, 0, 0, 0,
                "https://firestore.com/comment_content", "https://funny.gif", {""}
    };
    txn2.vote = Vote{false, false, 0, 0, false};
    txn2.wallet = Wallet{
                Wallet_Interaction_Type::NA, "wallet_public_key", "wallet_address", 100
    };
    txn2.transaction_id = 2;
    txn2.transaction_time = 20003014032025;
    txn2.user_id = 58319;
    txn2.mod_stat = Moderation_Status::Rejected;
    txn2.signature = "wallet2_pvt_key";

    transactions.insert(transactions.end(), {txn, txn2});

    Block block(1, 18014914032025, transactions, "");

    if(Consensus::validate_block(block, chain, selected_validator_id, 23370215032025)){
        std::cout << "\nBlock validated and added to the chain!\n";
        std::cout << "Blockchain state:\n";
        std::vector<Block> blocks = chain.get_all_blocks();
        for (Block& blk : blocks) {
            std::cout << "------------------------------------------\n";
            std::cout << "Block ID: " << blk.get_block_id() << std::endl;
            std::cout << "Block Hash: " << blk.get_current_hash() << std::endl;
            std::cout << "Previous Hash: " << blk.get_previous_hash() << std::endl;
            std::cout << "Merkle Root: " << blk.get_merkle_root() << std::endl;
            std::cout << "Validator ID: " << blk.get_validator_id() << std::endl;
            std::cout << "Transactions in Block: \n";
            for (const auto& tx : blk.get_transactions()) {
                std::cout << "  - Transaction ID: " << tx.transaction_id << std::endl;
                std::cout << "    User ID: " << tx.user_id << std::endl;
                std::cout << "    Serialized: " << Crypto::serialize_transaction(tx) << std::endl;
                std::cout << "    Hash: " << Crypto::sha256(Crypto::serialize_transaction(tx)) << std::endl;
            }
        }
        std::cout << "------------------------------------------\n";
    }
    else{
        std::cout << "Failed to validate block and add it" << std::endl; 
    }
}
