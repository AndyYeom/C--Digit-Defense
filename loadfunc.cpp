#include <iostream>
#include "ActualGame.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// This function loads the user's current level and returns the next level.
int loadfunc(){
  ifstream fin1, fin2;
  fin2.open("Level_2_Results.txt");
  fin1.open("Level_1_Results.txt");
  int returnval=0;
  if (fin1.fail()) //check if the record is there using .fail();
  {
    cout<<"Error! No records found. Please play the game first."<<endl; //if user has no record, 
  }
  else if (fin2.fail())
  {
    cout<<"You are currently at level 1."<<endl; 
    returnval=2;
    return returnval; //set return value to 2
  }
  else
  {
    cout<<"You are currently at level 2."<<endl;
    returnval=3; 
    return returnval;//set return value to 3
  }
  return 0;
}