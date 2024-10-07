#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
        // parameter constructor - user will enter the movie title when initializing Movie objects
        Movie(string title) {movieTitle = title;}

        // method to insert a rating to the front of the linked list
        void insertRatingsNode(float rating) {

            RatingsNode* newRating = new RatingsNode;
            // assign rating input into RatingsNode
            newRating->movieRating = rating;
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
        void insertCommentsNode(string comment) {

            CommentsNode* newComment = new CommentsNode;
            // Assign method input comment into CommentsNode
            newComment->movieComments = comment;
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

        void displayMovieInfo() {
            int ratingsCount = 1, reviewCount = 1;

            cout << "\nMovie Title: " << movieTitle << endl;
            cout << "-------------------------" << endl;

            cout << "Ratings for " << movieTitle << endl;

            RatingsNode * RatingCurr = ratingsHead;
            while (RatingCurr) {
                // display data
                cout << "   >Rating #" << ratingsCount << ": " << RatingCurr->movieRating << endl;
                ratingsCount++;
                // assing curr pointer to next memory location
                RatingCurr = RatingCurr->nextRating;
            }
            
            cout << "\nReviews for " << movieTitle << endl;

            CommentsNode * commentsCurr = commentsHead;
            while (commentsCurr) {
                // display data
                cout << "   >Review #" << reviewCount << ": " << commentsCurr->movieComments << endl;
                reviewCount++;
                // assing curr pointer to next memory location
                commentsCurr = commentsCurr->nextComment;
            }
            cout << endl;
       }
};



int main() {
    vector<Movie> movieVec;

    ifstream movieComments("/Users/ethandilk/Desktop/Computer Science/COMSC 210 - Program Design & Data Structures/Lab_19_Abstract_Automate/movie_input.txt");

    if (!movieComments){
        cout << "Error opening file - please try again!" << endl;
        exit(1);
    }
    // initializing 2 Movie objects
    Movie m1("The Hunger Games"), m2("Saving Private Ryan");
    


    // Movie m1("Hunger Games");
    // m1.insertRatingsNode(3.6);
    // m1.insertRatingsNode(5.0);
    // m1.insertCommentsNode("This is good!");

    // m1.displayMovieInfo();

    return 0;
}