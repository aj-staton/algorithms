/*#########################################################
Project 3 for CSCE 350 

Copyright: Austin Staton
Date: November 21st, 2019

I will be using resources from cplusplus.com.
#########################################################*/

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iterator>

using namespace std;

/**********************EXECUTION**********************/
/******************************************************
* 
******************************************************/
int main(int argc, char *argv[]) {
  string line;
  while (getline(cin, line) && cin.eof() != true) {
    // 1. Read the input.
    string input = line;

    //NOTE: substr(x,y) gets Y number of characters after X.
    string addend1 = input.substr(0, delim1);
  }
  return 0;
}
