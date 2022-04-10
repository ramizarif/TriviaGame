//
//  TriviaHeader.hpp
//  TriviaGame
//
//  Created by Andrea Hall on 4/10/22.
//

#ifndef TriviaHeader_hpp
#define TriviaHeader_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
// Globals
vector<string> cats;

void AddCategories(){
    cats.push_back("Music");
    cats.push_back("Sports");
}

class Game {
public:
    int number_of_players;
    int total_questions;
    
    Game(int n){
        number_of_players = n;
        total_questions = 5;
    }
    Game(){
        
    }
};

class Question {
public:
    string category_name;
    string file_name;
    string question;
    string answer1;
    string answewr2;
    string answer3;
    string answer4;
    bool asked;
};

class Categories {
public:
    string category;
    vector<Game> game;
    vector<Question> questions;
    void addToCategory(Question q){
        questions.push_back(q);
    }
};

class Player {
private:
    static vector<Player*> plyrList;
public:
    string name;
    float total_score = 0;
    Game current_game;
  
    void question_correct(){
        total_score += 1;
    }
    void question_incorrect(){
        total_score -= 1;
    }
    static vector<Player*> getAllPlayers(){
      return plyrList;
     }
    Player(string n, Game g ) {
      name = n;
     current_game = g;
     }
    Player(){
        
    }
};




#endif /* TriviaHeader_hpp */
