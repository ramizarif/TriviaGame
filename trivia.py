# def GameRules();
    # Outputs Rules of the game and categories

def ChooseCategories():
    #this function will ask the user which categories the user wants added to the game and return a list of them
    choosenCategory = input("Please Select A Category: ")
    return choosenCategory

#def PullRandomQuestion(categoryList):
    #this function will randomly pick a question and return it from the txt files and categories chosen by the user (will have to use the categories
    # chosen from the 'ChooseCategories' function)
        #additionally this function will have to scramble the answers and display them in a different order than they come in the txt file
        #also it should save any already asked questions to make sure there are no duplicate questions being asked

#def CheckIfHighScoreIsBeaten(endGameScore):
    #this function will open and read the highscore.txt file and see if the score at the end of the game is higher than it if it is go to the 
    #'SaveHighScore' Function

#def SaveHighScore(newHighScore):
    #this function will take a new high score and replace the highscore in the highscore.txt file 

#def SinglePlayerMain():
    #this function will put it all together to make the trivia game work
    #variables that will need to be tracked: 
        #lives - 3 lives, every time a question is answered incorrectly a life is lost
        #score - how many questions have been answered right, at the end of the game this is compared to the current high score to see if it will be
        #a new high score

#def MultiPlayerMain():
    #this function will put everything together similarly to the singleplayermainfunction
    #however it will run once with the first player with one life, and then player 2, if player 2 exceeds player one's score they win
    #vars to be tracked: 
    #player 1 score
    #player 2 score
    #if player 2 score > player 1 score: player 2 wins
    #elif player2 gets one wrong and p2 score < p1 score: p1 wins
    
