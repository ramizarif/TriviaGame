//
//  TriviaGame.cpp
//  TriviaGame
//
// This File holds all of our functions to play the game as well as main which runs it
// Functions are
    // Game Rules:
        // Lists the rules of the game
    // Game Type:
        // Asks the user how many players are playing the game
        // Returns that number
    // Create Category:
        // Hard coded with our current available categories and location of files
        // Creates with in category class for easy access
        // Adds category to game.cats
    // Create Question:
        // For every category, opens file and creates questions in that category
        // Adds questions to that category for easy accesss
    // Print Categories:
       // Prints the name of the current categores to console
    // Choose Categories:
      // Asks Current Player to choose category for question
      // Returns integer of category location in Categories vector
   // Add Players:
      // Takes game.number_of_players and creates that number of players for the game
      // Adds players to game.players vector for easier access
   // Player Alive:
      // Checks to see if any players are currently alive in the game
   // resetQuestionsAsked:
     // Marks questions as not asked yet
     // Called if all questions have been asked or at beginning of game
   // Ask Qeustion:
     // Finds next unasked question in that category
     // Asks player that question
     // Shuffles available answers using current time as seed
     // Lists Possible answer with number
     // Asks player to choose number of correct answer
     // Checks if its right or wrong sends to HandleAnswer
   // Handle Answer:
     // Lets player know if they got it right or wrong
     // Adds point or subtracts life by calling player class method
   // CheckIFHighScoreIsBeaten:
     // Compares highest player score to high score
     // Lets player know if they beat the score
  // FinalGameCalculations:
    // Lists each player and their score
    // If multiplayer lets them know who the winner is
  // PlayGame:
    // Loops through alive players and ask questions
    // Once no one is alive calls final game calculations
    // Calls NewGame to see if user wants to play again or not
  // StartGame:
    // Fills in classes with initial information so game can be played
    // Ends with play game
  // NewGame:
    // Called at the end of Play Game to see if player wants to play another game or quit


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>
#include "TriviaHeader.hpp"

using namespace std;
// Globals
Game g;
HighScore h;
vector<Categories> cats;

void GameRules(){
// Outputs Rules of the game
    cout <<"Welcome to Team 21's Trivia Game!" << endl;
    cout << endl;
    cout <<"You will have three lives, each wrong answer loses a life each right answer gives you one point!" << endl;
    cout <<"At the end of the game we will compare you score to the current high score to see if you have achieved a new high score!" << endl;
    cout << endl;
    cout <<"Have fun and good luck!" << endl;
    cout << endl;
}

int GameType(){
// Gets the number of players
    int players;
    cout << "Please Select enter the number of players: ";
    cin >> players;
    return players;
};

void CreateCategories(){
    // Creates categories in class and adds them to game cats vector
    Categories music = Categories("Movies", g, "moviequestions.csv");
    Categories sports = Categories("Sports", g, "sportsquestions.csv");
    Categories pop = Categories("Pop Culture", g, "popculturequestions.csv");
    
    cats.push_back(music);
    cats.push_back(sports);
    cats.push_back(pop);
}
void CreateQuestions(){
    // Gets questions from csvs and adds them to the questions class and the appropriate category class
    for (int i = 0; i < cats.size(); i++) {
        vector<vector<string>> qs;
        vector<string> current_row;
        string line;
        string item;
        cats[i].questions = {};
        
        fstream file (cats.at(i).file_location);
        if (file.is_open()) {
            while (getline(file, line)) {
                current_row.clear();
                stringstream str(line);
                
                while (getline(str, item, ',')) {
                    current_row.push_back(item);

                }
                qs.push_back(current_row);
            }
        }
        
        for (int j = 0; j < qs.size(); j++) {
            Question new_q;
            new_q.category_name = cats[i].category;
            new_q.asked = false;
            new_q.question = qs[j][0];
            new_q.correct_answer =qs[j][1];
            new_q.answer2 =qs[j][2];
            new_q.answer3 =qs[j][3];
            new_q.answer4 =qs[j][4];
            cats[i].addToCategory(new_q);
        }
    } // Ends category for loop
}
void PrintCategories(){
    // Print categories for player
    cout << "The Categories are: " << endl;
    for (int i = 0; i < cats.size(); i++) {
        cout << to_string(i) << ": " << cats.at(i).category << endl;
    }
}

int ChooseCategories(){
    // Has Player choose category
    int choosenCategory;
    cout << "Please Select A Category: ";
    cin >> choosenCategory;
    return choosenCategory;
};

void AddPlayers() {
    // Dynamically adds players based on input
    // Default name is Player + number
    g.players = {};
    g.players.resize(g.number_of_players);
    for(int i = 0; i < g.number_of_players; i++) {
    //Create each player for the game
        string p_name = "Player " + to_string(i + 1);
        g.players[i].name = p_name;
        g.players[i].current_game = g;
        g.players[i].lives = 3;
    }
}

bool PlayerAlive () {
    // Checks to see if any players have lives left
    bool alive = false;
    for(int i = 0; i < g.number_of_players; i++){
        if ( g.players.at(i).lives > 0 ) {
            alive = true;
        }
    }
    return alive;
};

void resetQuestionsAsked(int current_cat){
    for (int i = 0; i < cats[current_cat].questions.size(); i++) {
        cats[current_cat].questions[i].asked = false;
    }
}

bool AskQuestion(int current_cat){
    // Asks player question
    int rand = 0;
    bool found_question = false;
    int selected_answer;
    bool correct;
    vector<string> options;
    
    // Get next un-asked question
    for (int i = 0; i < cats[current_cat].questions.size(); i++) {
        if(cats[current_cat].questions[i].asked == false) {
            rand = i;
            found_question = true;
            break;
        }
    }
    
    if (not(found_question)) {
        // Run out of questions so repeating questions
        cout << " This must be your favorite category, now we will be repeating questions!" << endl;
        // Since all have been asked reseting
        resetQuestionsAsked(current_cat);
    }
    options.push_back(cats[current_cat].questions[rand].correct_answer);
    options.push_back(cats[current_cat].questions[rand].answer2);
    options.push_back(cats[current_cat].questions[rand].answer3);
    options.push_back(cats[current_cat].questions[rand].answer4);
    
    // Actually asking question
    cout << cats[current_cat].questions[rand].question << endl;
    
    // Shuffle Answers
    auto random = default_random_engine {};
    random.seed(chrono::system_clock::now().time_since_epoch().count());
    shuffle(begin(options), end(options), random);
    
    // Displaying Options
    for (int i = 0; i < options.size(); i++) {
        cout << to_string(i) << ": " << options[i] << endl;
    };
    cout << "Please select an answer by number: " << endl;
    cin >> selected_answer;
        
    if (options[selected_answer] == cats[current_cat].questions[rand].correct_answer ) {
        correct = true;
    } else {
            correct = false;
    }
        
    cats[current_cat].questions[rand].asked = true;
        
    return correct;
}

void HandleAnswer(bool correct, Player &player) {
    // Adds points if correct or takes a life if wrong
    // Lets player know if they got the queststion right or wrong
    if (correct) {
        player.question_correct();
        cout << "Congrats " << player.name << " you answered correctly" << endl;
    } else {
        player.question_incorrect();
        cout << "I'm sorry " << player.name << " you answered incorrectly" << endl;
    }
}

void CheckIFHighScoreIsBeaten(int winning_player){
    if (h.high_score < g.players.at(winning_player).total_score) {
        h.high_score = g.players.at(winning_player).total_score;
        cout << " You beat the high score!" << endl;
        cout << "Please enter your name: " << endl;
        cin >> h.player_name;
    }
};

void FinalGameCalculations(){
    int highest_score = 0;
    int winning_player = 0;
    for(int i = 0; i < g.number_of_players; i++){
        cout << g.players.at(i).name << "'s final score is " << g.players.at(i).total_score << endl;
        if (g.players.at(i).total_score > highest_score){
            highest_score = g.players.at(i).total_score;
            winning_player = i;
        }
    }
    
    if (g.number_of_players > 1) {
        cout << "Congats " << g.players.at(winning_player).name << " You Won!" << endl;
    }
    
    CheckIFHighScoreIsBeaten(winning_player);
}

void PlayGame() {
    while (PlayerAlive()) {
        for(int i = 0; i < g.number_of_players; i++){
            // Goes through each player and asks question untill they lose 3 lives than goes to next player
            if (g.players.at(i).lives > 0) {
                cout << endl;
                PrintCategories();
                cout << g.players.at(i).name << " please choose a category by number: " << endl;
                bool answered_correct = AskQuestion(ChooseCategories()); // Asks Player to choose a category and than pulls a random question
                HandleAnswer(answered_correct, g.players[i]);
            }
        }
    }
    FinalGameCalculations();
    NewGame();
    
}

void StartGame(int players){
    // Intializes game by filling in classes
    cats = {};

    g.number_of_players = players;
    CreateCategories();
    CreateQuestions();
    AddPlayers();
    PlayGame();
}

void NewGame(){
    string ng;
    cout << "Would you like to start a new game? Y or N " << endl;
    cin >> ng;
    
    if(ng == "Y") {
        int players = GameType();
        StartGame(players);
    } else {
        cout << "Thank you for playing Team 21's Triva Game!" << endl;
    }
}

int main(int argc, const char * argv[]) {
    GameRules();
    int players = GameType();
    StartGame(players);
    
    return 0;
}
