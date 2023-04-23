# COMP2113

COMP2113 Course Project Name : Digit Defense

Group 170 Members : Liu Ian(3035834931), Gao Kangrui(3035953139), Yeom Dongjun(3035666463), Yang Seunghoon(3035665483)

Description : 
    "Digit Defense" is designed to enhance the player's basic mathematical skills. 
    Players are presented with a series of math problems, including addition, subtraction, and multiplication, depending on their levels.
    Players get 10 seconds per level, and they must solve the problems as accurate and quickly as possible.
    At the end of each stage, the percentage of accuracy is analyzed, to show one's strengths and weaknesses.

Game Rules : 
    1. Player input of two numbers to start a new game ("1") or load a game ("9")
    2. The program performs the requested operation, and shows a series of math problems, depending on the stage, with time remaining.
       ("Stage 1: Addition", "Stage 2: Subtraction", "Stage 3: Multiplication")
    3. The program displays the result of the trial
       (The number of questions answered in 10 seconds, The number of correct answers, The percentage of correctness)
    4. Player decide whether to resume the game or save & exit.

Implemented Features :
    1. For coding element 1, we have used "srand(time(0));" to generate random numbers for the game.
    2. For coding element 2, we use "string save = firsts + " + " + seconds + " = " + str3.str();" to store the game status and print at the end of the     game.
    3. For coding element 3, we have used a linked list to store the randomly generated questions and the user inputted answers which can be seen in Level1.cpp "struct question" part.
    4. For Coding element 4, we have used "ofstream read; read.open("Level_1_Results.txt");" to save the questions and answers as a file for loading/saving functionality
    5. For coding element 5, we are analyzing the program codes in multiple files, including ActualGame.h, Level1.cpp, main.cpp, etc.
    6. For coding element 6, each files are named accordingly based on their roles. each stage of the game has their own code, which are Level1.cpp, Level2.cpp, and Level3.cpp
    7. for coding element 7, there are in-text documentations with the expression "//", for example, "//Link to next chain in Linked list".  The in-code texts for Level2.cppp and Level3.cpp are alike with Level1.cpp

Non-standard C/C++ Libraries Implemantions : 
    None

Compilation and Execution Instructions
    1. Copy and paste the repository to your local environment
    2. Complie the source code via the command : g++ -pedantic-errors -std=c++11 main.cpp Level1.cpp Level2.cpp Level3.cpp loadfunc.cpp  -o main
       , or make main using the Makefile
    3. Run the function via the command : ./main
    4. Follow the instructions given in the game
