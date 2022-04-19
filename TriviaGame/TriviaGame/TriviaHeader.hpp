//
//  TriviaHeader.hpp
//  TriviaGame
//
// This file declares the High Score, Game, Questions, Categories and Player classes for our Trivia Game.

#ifndef TriviaHeader_hpp
#define TriviaHeader_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void NewGame(); // Declaring here so that where it is located in the Trivia game does not matter
class Player;
class Categories;

class HighScore {
    // Records current high score in this game
public:
    int high_score = 0;
    string player_name;
};

class Game {
    // Creates instance of trivia game
public:
    int number_of_players;
    int total_questions;
    vector<Player> players; // Collection of current players for easier access of players
    vector<Categories> cats; // Collection of current categories for easy access to questions by category
    Game(int n){
        number_of_players = n; // Use number of players to loop through current players for question asking and scoring
    }
    Game(){
        
    }
};

class Question {
    // Filled from our csv files, this creates question objects with categories, correct answers and wrong answers.
public:
    string category_name;
    string question;
    string correct_answer;
    string answer2;
    string answer3;
    string answer4;
    bool asked;
    Question(){
        
    }
};

class Categories {
    // Creates our categories that our questions fall into
public:
    string category;
    string file_location;
    Game game;
    vector<Question> questions; // Creates a collection of questions that are in this category
 
    void addToCategory(Question q){
        questions.push_back(q);
    }
    int random(){
        return 0;
    }
    Categories(string c, Game g, string f){
        category = c; // Category Name
        game = g; // Current Game
        file_location = f; // Location of the file in our code base
    }
    
};

class Player {
public:
    string name;
    float total_score = 0;
    int lives;
    Game current_game;
  
    void question_correct(){
        // When anwering correctly adds one point to score
        total_score += 1;
    }
    void question_incorrect(){
        lives -= 1; // Loses a life for each incorrect answer
    }
    Player(string n, Game g ) {
      name = n;
      current_game = g;
      lives = 3; // All Players start with three lives
     }
    Player(){
        
    }
};

#endif /* TriviaHeader_hpp */
