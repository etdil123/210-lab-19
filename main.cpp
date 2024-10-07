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
    RatingsNode *ratingsHead = nullptr;
    CommentsNode *commentsHead = nullptr;

    public:
        // method to insert a rating to the front of the linked list
        void insertRatingsNode(float rating) {

            RatingsNode* newRating = new RatingsNode;
            // make the newRating the head if only 1 item
            if (!ratingsHead) {
                ratingsHead = newRating;
                // make sure newRating points to nullptr
                newRating = nullptr;
            }

            else {
                // else assign newRating head to what the head is pointing to
                newRating->nextRating = ratingsHead;
                // make the head point to the new rating
                ratingsHead = newRating;
            }

        }

        // method to insert comments to the front of the linked list
        void insertCommentsNode(float rating) {

            CommentsNode* newComment = new CommentsNode;
            // make the newComment the head if only 1 item
            if (!commentsHead) {
                commentsHead = newComment;
                // make sure newComment points to nullptr
                newComment = nullptr;
            }

            else {
                // else assign comments head to what the head is pointing to
                newComment->nextComment = commentsHead;
                // make the head point to the new rating
                commentsHead = newComment;
            }

        }


};



int main() {




    return 0;
}