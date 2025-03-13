#include "crypto.h"
#include <sstream>
#include <iomanip>

namespace Crypto{
    std::string sha256(const std::string& data) {   // https://terminalroot.com/how-to-generate-sha256-hash-with-cpp-and-openssl
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, data.c_str(), data.size());
        SHA256_Final(hash, &sha256);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
        }
        return ss.str();
    }

    std::string serializeTransaction(const Transaction& txn){ // convert the Transaction struct to a string - that's serialization - basically converting a complex data structure to a simple one
        std::stringstream ss;   
        ss << static_cast<int>(txn.interaction_type)
           << txn.transaction_id
           << txn.transaction_time
           << txn.user_id;

        if(txn.post.post_transaction){
            ss << txn.post.post_id
               << static_cast<int>(txn.post.post_type) 
               << txn.post.like_count << txn.post.dislike_count << txn.post.comment_count
               << txn.post.post_content_id << txn.post.post_media_url;
            for (const auto& comment_id : txn.post.comment_ids) {
                ss << comment_id;
            }
        }

        if(txn.comment.comment_transaction){
            ss << txn.comment.comment_id
               << static_cast<int>(txn.comment.comment_type)
               << txn.comment.like_count << txn.comment.dislike_count << txn.comment.reply_count
               << (txn.comment.parent_post_id ? txn.comment.parent_post_id : 0) << (txn.comment.parent_comment_id ? txn.comment.parent_comment_id : 0)
               << txn.comment.comment_content_id << txn.comment.comment_media_url;
            for (const auto& reply_id : txn.comment.reply_ids) {
                ss << reply_id;
            }
        }

        if(txn.vote.post_voted || txn.vote.comment_voted){
            ss << txn.vote.post_id
               << txn.vote.comment_id
               << txn.vote.vote_type;
        }

        return ss.str();
    }
}