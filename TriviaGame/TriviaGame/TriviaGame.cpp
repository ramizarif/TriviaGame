//
//  main.cpp
//  TriviaGame
//
//  Created by Andrea Hall on 4/3/22.
//

#include <iostream>
#include <vector>
#include "TriviaHeader.hpp"

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

int GameType(){
    int players;
    cout << "Please Select enter the number of players: ";
    cin >> players;
    return players;
};

void CreateCategoriesAndQuestions(){
    // TODO: Add Categories to class
    // TODO: Loop through csvs and create new Question from Question class and add it to category
}
void PrintCategories(){
    cout << "The Categories are: " << endl;
    for (int i = 0; i < cats.size(); i++) {
        cout << to_string(i) << ": " << cats.at(i) << endl;
    }
}

int ChooseCategories(){
    int choosenCategory;
    cout << "Please Select A Category: ";
    cin >> choosenCategory;
    return choosenCategory;
};

vector<string> PullRandomQuestion(int cat_number){
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

void StartGame(int players) {
    AddCategories();
    Game g;
    g.number_of_players = players;
    vector<Player> game_players;
    
    game_players.resize(g.number_of_players);
    for(int i = 0; i < players; i++) {
    //Create each player for the game
        string p_name = "Player " + to_string(i + 1);
        game_players[i].name = p_name;
        game_players[i].current_game = g;
    }
    
    PrintCategories();
    
    for(int i = 0; i < game_players.size(); i++){
        // Goes through each player and asks question
        cout << game_players.at(i).name << " please choose a category by number: " << endl;
        vector<string> question;
        question = PullRandomQuestion(ChooseCategories()); // Asks Player to choose a category and than pulls a random question
        // TODO: Ask  question with answers shuffled
        // TODO: run game_player.at(i).question_correct or game_player.at(i).question incorrect
    }
     // TODO: End Game, declare winner, state final score, record high score if necessary
}



int main(int argc, const char * argv[]) {
    // insert code here...
    GameRules();
    int players = GameType();
    StartGame(players);
    
    return 0;
}
