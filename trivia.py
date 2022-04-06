import random
from re import I
from unicodedata import category
import time

categoryFileDictionary = {"movies": "TriviaGame/moviequestions.csv", "sports": "TriviaGame/sportsquestions.csv"}


def GameRules():
    # Outputs Rules of the game and categories
    print("Welcome to Team 21's Trivia Game! \n")
    print("You will be asked to choose a category from Sports or Movies ")
    print("You will have three lives, each wrong answer loses a life each right answer gives you one point!")
    print("At the end of the game we will compare you score to the current high score to see if you have achieved a new high score!\n")
    print("Have fun and good luck!\n")

def GameType():
    gtype = input("Please Select enter 'Single' for one player or 'Multi' for two players: \n ")
    return gtype

def ChooseCategories():
    #this function will ask the user which categories the user wants added to the game and return a list of them
    choosenCategories = input("Please Select The Categories you want (seperate by commas: i.e. sports,movies): ")
    categoryList = choosenCategories.lower().split(",")
    return categoryList

def PullRandomQuestion(categoryList, repeatedQuestionsList):
    #this function will randomly pick a question and return it from the txt files and categories chosen by the user (will have to use the categories
    # chosen from the 'ChooseCategories' function)
        #additionally this function will have to scramble the answers and display them in a different order than they come in the txt file
        #also it should save any already asked questions to make sure there are no duplicate questions being asked

        randomElement = random.randrange(0, len(categoryList))
        randomCategory = categoryList[randomElement - 1]
        f = open(categoryFileDictionary[randomCategory], "r")
        questions = f.readlines()
        keepGoing = True
        while(keepGoing):
            randomDigit = random.randrange(0, 10)
            randomQuestion = questions[randomDigit]
            if (randomQuestion not in repeatedQuestionsList):
                keepGoing = False
        repeatedQuestionsList.append(randomQuestion)
        return randomQuestion

def DisplayQuestion(questionLine):
    #this function will handle the logic of displaying the question/answers and then checking if the user got the question correct
    #if the answer is correct it will return true and return false if wrong
    #this function also shuffles the answer order each time
    split = questionLine.split(",")
    question = split[0]
    print(question)
    answerList = [split[1], split[2], split[3], split[4]]
    correctAnswer = split[1]
    correctAnswerNum = 0
    random.shuffle(answerList)
    i = 0
    for answer in answerList:
        i+=1
        if (answer == correctAnswer):
            correctAnswerNum = i 
        print(str(i) + ". " + answer)
    userAnswer = input("Enter the number corresponding to your desired answer: ")
    answerIsCorrect = False
    if (userAnswer == str(correctAnswerNum)):
        answerIsCorrect = True
        return answerIsCorrect
    return answerIsCorrect


#def CheckIfHighScoreIsBeaten(endGameScore):
    #this function will open and read the highscore.txt file and see if the score at the end of the game is higher than it if it is go to the 
    #'SaveHighScore' Function

#def SaveHighScore(newHighScore):
    #this function will take a new high score and replace the highscore in the highscore.txt file 

def SinglePlayerMain():
    # this function will put it all together to make the trivia game work
    # variables that will need to be tracked: 
    #     lives - 3 lives, every time a question is answered incorrectly a life is lost
    #     score - how many questions have been answered right, at the end of the game this is compared to the current high score to see if it will be
    #     a new high score
    print("Got to Single Player")
    repeatedQuestionsList = []
    lives = 3
    score = 0
    categoryList = ChooseCategories()
    while (lives != 0):
        randomQuestion = PullRandomQuestion(categoryList, repeatedQuestionsList)
        answerIsCorrect = DisplayQuestion(randomQuestion)
        if (answerIsCorrect):
            score += 1
            print("Score: " + str(score))
            time.sleep(2)
            pass
        else: 
            lives = lives - 1
            print("You have " + str(lives) + " lives left...")
            time.sleep(2)
    print("Your final score is " + str(score))
    #add logic for the high score checker
SinglePlayerMain()



def MultiPlayerMain():
    # this function will put everything together similarly to the singleplayermainfunction
    # however it will run once with the first player with one life, and then player 2, if player 2 exceeds player one's score they win
    # vars to be tracked: 
    # player 1 score
    # player 2 score
    # if player 2 score > player 1 score: player 2 wins
    # elif player2 gets one wrong and p2 score < p1 score: p1 wins
    print("Got to Multi Player")

def PlayGame():
    # Explains Game
    # Has user choose game type
    # Initializes Single or Multi Player functin above
    GameRules()
    
    if(GameType() == "Single"): 
        SinglePlayerMain()
    else: 
        MultiPlayerMain()
    


#PlayGame()
    
