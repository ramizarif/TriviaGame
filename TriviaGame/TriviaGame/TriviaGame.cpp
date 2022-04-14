//
//  TriviaGame.cpp
//  TriviaGame
//
//

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
vector<Categories> cats;
vector<Player> game_players;
Game g;

void GameRules(){
// Outputs Rules of the game and categories
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
    // Creates categories in class and adds them to global vector
    Categories music = Categories("Music", g, "moviequestions.csv");
    Categories sports = Categories("Sports", g, "sportsquestions.csv");
    
    cats.push_back(music);
    cats.push_back(sports);
}
void CreateQuestions(){
    // Gets questions from csvs and adds them to the questions class and the appropriate category class
    for (int i = 0; i < cats.size(); i++) {
        vector<vector<string>> qs;
        vector<string> current_row;
        string line;
        string item;
        
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
    game_players.resize(g.number_of_players);
    for(int i = 0; i < g.number_of_players; i++) {
    //Create each player for the game
        string p_name = "Player " + to_string(i + 1);
        game_players[i].name = p_name;
        game_players[i].current_game = g;
        game_players[i].lives = 3;
    }
}

bool PlayerAlive () {
    // Checkst to see if any players have lives left
    bool alive = false;
    for(int i = 0; i < g.number_of_players; i++){
        if ( game_players.at(i).lives > 0 ) {
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
//    int answer_rand;
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
    random.seed(std::chrono::system_clock::now().time_since_epoch().count());
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
    // Adds points if correct or takes a live if wrong
    // Lets player know if they got the queststion right or wrong
    if (correct) {
        player.question_correct();
        cout << "Congrats " << player.name << " you answered correctly" << endl;
    } else {
        player.question_incorrect();
        cout << "I'm sorry " << player.name << " you answered incorrectly" << endl;
    }
}

void FinalGameCalculations(){
    // TODO: End Game, declare winner, state final score, record high score if necessary
    cout << "End of Game" << endl;
}
void CheckIFHighScoreIsBeaten(int end_game_score){
//this function will open and read the highscore.txt file and see if the score at the end of the game is higher than it if it is go to the
// 'SaveHighScore' Function
    
};

void SaveHighScore(int new_high_score){
//this function will take a new high score and replace the highscore in the highscore.txt file
};

void PlayGame() {
    while (PlayerAlive()) {
        for(int i = 0; i < g.number_of_players; i++){
            // Goes through each player and asks question untill they lose 3 lives than goes to next player
            if (game_players.at(i).lives > 0) {
                cout << endl;
                PrintCategories();
                cout << game_players.at(i).name << " please choose a category by number: " << endl;
                bool answered_correct = AskQuestion(ChooseCategories()); // Asks Player to choose a category and than pulls a random question
                HandleAnswer(answered_correct, game_players[i]);
            }
        }
    }
    FinalGameCalculations();
}

void StartGame(int players){
    // Intializes game by filling in classes
    g.number_of_players = players;
    CreateCategories();
    CreateQuestions();
    AddPlayers();
    PlayGame();
}

int main(int argc, const char * argv[]) {
    GameRules();
    int players = GameType();
    StartGame(players);
    
    return 0;
}
