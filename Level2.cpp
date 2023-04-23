#include "ActualGame.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int Level2() {

  struct question {
    string quest;
    question *next;
  };

  srand(time(0));

  question *head = new question();
  head->quest = "Level 2";
  head->next = NULL;

  int howmany = 0;
  int howmanycor = 0;

  long long start;
  long long end;
  int diff;

  start = std::time(0);



  int flag = 0;

  while (flag == 0) {

    int N = 10;
    int first = rand() % N;
    int second = rand() % N;
    ostringstream str1;
    ostringstream str2;
    ostringstream str3;

    str1 << first;
    str2 << second;

    string firsts = str1.str();
    string seconds = str2.str();

    cout << first << " - " << second << " = ";
    int tempinput;
    cin >> tempinput;

    if (first - second == tempinput) {
      howmanycor = howmanycor + 1;
    }

    howmany = howmany + 1;

    str3 << tempinput;

    string save = firsts + " - " + seconds + " = " + str3.str();
    string newstr = save;

    question *newquestion = new question();
    newquestion->quest = newstr;
    newquestion->next = NULL;

    question *last = head;
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = newquestion;

    end = std::time(0);

    diff = end - start;

    int display = 10 - diff;
    if (10 - diff < 0) {
      display = 0;
    }

    cout << "Time Remaining: " << display;
    cout << endl;

    if (diff >= 10)
      flag = 1;

  }

  float correctper = float(howmanycor) / float(howmany);
  correctper = correctper * 100;
  int finalper = correctper;

  cout << setprecision(2);
  cout << "You have answered to " << howmany << " questions in 10 seconds" << endl;//output the number of questions answered in 10 seconds
  cout << "The number of correct answers: " << howmanycor << endl;//output the number of correct answers
  cout << "Your Percentage Correct is " << finalper << "%" << endl;
  cout << endl;

  ofstream read;
  read.open("Level_2_Results.txt");
  read << "Level 2 Results:" << endl;
  read << "Your Percentage Correct for level 2 is " << finalper << "%" << endl;
  read << "Your Total Number of Questions Answered for Level 2 are " << howmany << endl;
  read << "Your Questions and Answers are shown below: " << endl;
  question *trav = head;
  while (trav != NULL) {
    read << trav->quest << endl;
    trav = trav->next;
  }

  read.close();
  return 0;
}