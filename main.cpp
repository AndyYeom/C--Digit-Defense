#include "ActualGame.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

struct question {
  string quest;
  question *next;
};
ifstream print;
string line;

int main() {

  cout << "Welcome to Digit Defense" << endl;
  cout << "Please Press 1 to start Level 1 or Press 9 to Load a Game" << endl;//Greeting message and instructions

  int input;
  cin >> input;//Getting input from user
  if (input==9){
    input=loadfunc();//checking to load or to start new game
  }

  if (input == 1) {//As input is 1, the first level is called and thus Level1() is called
    cout << "Level 1 Will now Begin" << endl;
    Level1();
      cout << "If you want to continue to Level 2, Please Press 2, else you may "
          "press 0 to save and use the generated file to load your game later or you may press 9 to end the game and print your records"
       << endl;

  cin >> input;
  }

  if (input == 0) {//checks if the player wants to save or not
    cout << "Thank you for playing" << endl;
    cout << "Your Records are Saved. Reload the Game to Access your Records." << endl;
    return 0;
  }
  if (input == 9) {
    cout << "Thank you for playing" << endl;
    cout << "Below is Questions and Answers" << endl;
    cout << endl;
    print.open("Level_1_Results.txt");
  while (getline(print, line)) {
    cout << line << endl;
  }
  print.close();
  cout << endl;
  int result=remove("Level_1_Results.txt");
  result=remove("Level_2_Results.txt");
  result=remove("Level_3_Results.txt");
    return 0;
  }

  if (input == 2) {//calling of fucniton Level2()
    cout << "Level 2 Will now Begin" << endl;
    Level2();
    cout << "If you want to continue to Level 3, Please Press 3, else you may "
          "press 0 to save and use the generated file to load your game later or you may press 9 to end the game and print your records"
       << endl;
    cin >> input;
  }

  if (input == 0) {
    cout << "Thank you for playing" << endl;
    cout << "Your Records are Saved. Reload the Game to Access your Records." << endl;
    return 0;
  }
  if (input == 9) {
    cout << "Thank you for playing" << endl;
    cout << "Below is Questions and Answers" << endl;
    cout << endl;
    print.open("Level_1_Results.txt");
  while (getline(print, line)) {
    cout << line << endl;
  }
  print.close();
  cout << endl;
  print.open("Level_2_Results.txt");
  while (getline(print, line)) {
    cout << line << endl;
  }
  print.close();
  cout << endl;

  int result=remove("Level_1_Results.txt");
    result=remove("Level_2_Results.txt");
    result=remove("Level_3_Results.txt");
    return 0;
  }
  if (input == 3) {//calling of Llevel3() for last level
    cout << "Level 3 Will now Begin" << endl;
    Level3();
  }  
  //Printing of Ending messages and all questions and answeres
  cout << "You have finished the game" << endl;
  cout << "Thank you for playing" << endl;
  cout << endl;
  cout << "Below is all the questions and answers" << endl;
  cout << endl;
  // Printing the questions and answers for level 1
  print.open("Level_1_Results.txt");
  while (getline(print, line)) {
    cout << line << endl;
  }
  print.close();
  cout << endl;
  // Printing the questions and answers for level 2
  print.open("Level_2_Results.txt");
  while (getline(print, line)) {
    cout << line << endl;
  }
  print.close();
  cout << endl;
  // Printing the questions and answers for level 3
  print.open("Level_3_Results.txt");
  while (getline(print, line)) {
    cout << line << endl;
  }
  print.close();


  //deletes the created files as game is over.
int result=remove("Level_1_Results.txt");
result=remove("Level_2_Results.txt");
result=remove("Level_3_Results.txt");

  
}