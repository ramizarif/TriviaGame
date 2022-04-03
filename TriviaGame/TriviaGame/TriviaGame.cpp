//
//  main.cpp
//  TriviaGame
//
//  Created by Andrea Hall on 4/3/22.
//

#include <iostream>
#include <vector>

using namespace std;

void GameRules(){
// Outputs Rules of the game and categories
    cout <<"Welcome to Team 21's Trivia Game!" << endl;
    cout << endl;
    cout <<"You will be asked to choose a category from Sports or Movies " << endl;
    cout <<"You will have three lives, each wrong answer loses a life each right answer gives you one point!" << endl;
    cout <<"At the end of the game we will compare you score to the current high score to see if you have achieved a new high score!" << endl;
    cout << endl;
    cout <<"Have fun and good luck!" << endl;
    cout << endl;
}

string GameType(){
    string gtype;
    cout << "Please Select enter 'Single' for one player or 'Multi' for two players: ";
    cin >> gtype;
    return gtype;
};

string ChooseCategories(){
    string choosenCategory;
    cout << "Please Select A Category: ";
    cin >> choosenCategory;
    return choosenCategory;
};

vector<string> PullRandomQuestion(vector<string>categories){
//this function will randomly pick a question and return it from the txt files and categories chosen by the user (will have to use the categories
//     chosen from the 'ChooseCategories' function)
//        #additionally this function will have to scramble the answers and display them in a different order than they come in the txt file
//        also it should save any already asked questions to make sure there are no duplicate questions being asked


    vector<string> question;
    
    return question;
};

void CheckIFHighScoreIsBeaten(int end_game_score){
//this function will open and read the highscore.txt file and see if the score at the end of the game is higher than it if it is go to the
// 'SaveHighScore' Function
};

void SaveHighScore(int new_high_score){
//this function will take a new high score and replace the highscore in the highscore.txt file
};

void SinglePlayerMain(){
    cout << "Got to Single Player" << endl;
};

void MultiPlayerMain(){
    cout << "Got to Multiple Player" << endl;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    GameRules();
        
    if(GameType() == "Single"){
        SinglePlayerMain();
    } else {
        MultiPlayerMain();
    }
    
    return 0;
}
