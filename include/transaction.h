#pragma once
#include <vector>
#include <string>
// holds the transaction that occurred
// stuff like post_author id, current_like count, current_comment count, 
// do we store the comments also in the transaction  - hash em and store em?  

// transaction can be literally anything you do on the social media platform
// so rn let's just keep the scope limited to comments, like, dislike and posts

enum class Platform_Interaction_Type{
    Post,
    Vote,   // upvote downvote like reddit
    Comment
};

enum class Post_Interaction_Type{
    Create, Delete, Edit
};

enum class Comment_Interaction_Type{
    Create, Delete, Edit
};

struct Vote{
    // either of the two are gonna be 1 for a transaction
    bool post_voted;
    bool comment_voted;
    //------------------
    uint32_t post_id;
    uint16_t comment_id;
    bool vote_type;   // upvote is 1 downvote is 0
};

struct Post{
    bool post_transaction;
    Post_Interaction_Type post_type;
    uint32_t post_id;    // max uint32 is gonna be like 1 billion+
    std::string post_author;
    std::string post_time;
    std::string like_count;
    std::string dislike_count;
    std::string comment_count;
    Comment* comments; // an array of comments
    std::string post_content;
};

struct Comment{
    bool comment_transaction;
    Comment_Interaction_Type comment_type;
    uint16_t comment_id;    // max uint16 is gonna have an upper limit of some 60k
    uint32_t parent_post_id; // the root comment has to have a parent_post_id
    std::string comment_author;
    std::string comment_time;
    std::string like_count;
    std::string dislike_count;
    std::string reply_count;    // every reply is gonna be another comment so really a chain of comments
    Comment* comments; // since each reply is another comment, need a linked list of comments
    std::string comment_content;
};

struct Transaction{
    Platform_Interaction_Type interaction_type;
    Post post;  // can check this based on the bool value in each struct to know which interaction
    Comment comment;  
};