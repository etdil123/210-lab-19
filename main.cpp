#include <iostream>
#include <string>
using namespace std;

class Movie {

    private:
        string movieTitle;
        // two separate structs to store linked lists for ratings and comments
        struct RatingsNode {
            float movieRating;
            RatingsNode * nextRating;
        };

        struct CommentsNode {
            string movieComments;
            CommentsNode * nextComment;
        };

    // head variables to know where to start linked list
    RatingsNode *ratingsHead;
    CommentsNode *commentsHead;


};



int main() {




    return 0;
}