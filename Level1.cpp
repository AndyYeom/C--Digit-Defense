#include "ActualGame.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int Level1() {

  struct question {//This is the struct to initialize a linked list so that the random generated questions and the user inputted answers can be stored dynamically.
    string quest;
    question *next;//Link to next chain in Linked list
  };

  srand(time(0));//This function uses a seed to generate random numbers for the game. By passing in the current time, this seed is always changing and thus the rand function will generate psuedorandom code.

  question *head = new question();//Creating a new question struct to store the inputs and questions
  head->quest = "Level 1";
  head->next = NULL;

  int howmany = 0;//Variable to store total number of questions asked
  int howmanycor = 0;//Variable to store total number of correctly answered questions

  long long start;//declare the start time so that a time remaining can be calculated
  long long end;//declare the end time so that a time remaining can be calculated
  int diff;//this is the difference between start and end. This allows become the time elapsed

  start = std::time(0);//Initalized start to become the current time

  int flag = 0;//Initialized a flag so that the game can be ended when time elasped is over 10 seconds

  while (flag == 0) {//this while loop is the main part of the game

    int N = 10;
    int first = rand() % N;//Produces a randomly generated integer between 0 and 10
    int second = rand() % N;
    // These line of code turn the integer data types into string data types for better storage when printed to a file
    ostringstream str1;
    ostringstream str2;
    ostringstream str3;

    str1 << first;
    str2 << second;

    string firsts = str1.str();
    string seconds = str2.str();

    cout << first << " + " << second << " = ";//forms the equation to be shown to the player
    int tempinput;
    cin >> tempinput;//tempinput is the answer inputted by the player

    if (first + second == tempinput) {//checks is the input is correct, if so, increment the howmanycor variable by 1.
      howmanycor = howmanycor + 1;
    }

    howmany = howmany + 1;//increases the number of qustions answered by 1
//converts the user inputted int into a string
    str3 << tempinput;

    string save = firsts + " + " + seconds + " = " + str3.str();//forms the final equation to be saved to file as well as printed when game ends
    string newstr = save;//copy the contents from save into newstr to be added to the linked list

    question *newquestion = new question();//create a new element in the linked list
    newquestion->quest = newstr;//assigning the question "quest" part of the linked list to the contents stored in newstr 
    newquestion->next = NULL;//since we are adding elements to the end of a linked list, the next element in the list is null


    
    question *last = head;//creates a new element in the linked list to traverse to the last element
    while (last->next != NULL) {
      last = last->next;//find the last element in the linked list
    }
    last->next = newquestion;//change the last element in the linked list to point to the newly created element, so that now this element in now the last element

    end = std::time(0);//calls the time now

    diff = end - start;//calculates time elasped.

    int display = 10 - diff;//an integer to display how many seconds left
    if (10 - diff < 0) {
      display = 0;//to prevent negative numbers from showing in the output
    }

    cout << "Time Remaining: " << display;
    cout << endl;//prints the time remaining

    if (diff >= 10)
      flag = 1;//if time elasped is over 10, change the flag to 1, ending the game
  }

  float correctper = float(howmanycor) / float(howmany);//calculates how many correct as a score
  correctper = correctper * 100;//transform into percentage
  int finalper = correctper;

  cout << setprecision(2);
  cout << "You have answered to " << howmany << " questions in 10 seconds" << endl;//output the number of questions answered in 10 seconds
  cout << "The number of correct answers: " << howmanycor << endl;//output the number of correct answers
  cout << "Your Percentage Correct is " << finalper << "%" << endl;//output score as a percentage
  cout << endl;
//saves the questions asked and answered as a file for loading/saving functionality
  ofstream read;
  read.open("Level_1_Results.txt");
  read << "Level 1 Results:" << endl;
  read << "Your Percentage Correct for level 1 is " << finalper << "%" << endl;
  read << "Your Total Number of Questions Answered for Level 1 are " << howmany << endl;
  read << "Your Questions and Answers are shown below: " << endl;
  question *trav = head;
  while (trav != NULL) {
    read << trav->quest << endl;
    trav = trav->next;
  }

// close file and return
  read.close();
  return 0;
}
