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
    string question;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    bool asked;
    Question(){
        
    }
};

class Categories {
public:
    string category;
    string file_location;
    Game game;
    vector<Question> questions;
    vector<Question> unpicked_questions;
    void addToCategory(Question q){
        questions.push_back(q);
    }
    Categories(string c, Game g, string f){
        category = c;
        game = g;
        file_location = f;
    }
    
};

class Player {
private:
    static vector<Player*> plyrList;
public:
    string name;
    float total_score = 0;
    int lives;
    Game current_game;
  
    void question_correct(){
        total_score += 1;
    }
    void question_incorrect(){
        lives -= 1;
    }
    static vector<Player*> getAllPlayers(){
      return plyrList;
     }
    Player(string n, Game g ) {
      name = n;
     current_game = g;
        lives = 3;
     }
    Player(){
        
    }
};




#endif /* TriviaHeader_hpp */
