/*#########################################################
Project 2 for CSCE350 solves a cryptartihmetic puzzle.
Meaning, two english words are added to produce a sum. Each
Letter in the word correlates to a single digit number.
These numbers do not have to be in the order of [A=0, B=1,
C=2,D=3,...Z=25]. This ordering is arbitrary. 

The goal is to SOLVE this puzzle, by computing the value
for each letter.

Project 2 requires a _Brute-Force_ approach. We know of
better ways to solve this problem; however, as a learning
exercise, we must use an exhaustive approach.

Copyright Holder: Austin Staton
Date: October 9th, 2019

I will be using resources from cplusplus.com.
#########################################################*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

/********************************************
 * PrintMap() prints the keys and values in a
 * map to standard output.
 * Param: 
 * 	theMap -- The map for printing. This
 * 	          is passed by reference for
 * 	          efficiency's sake, but it
 * 	          is not modified.
 *******************************************/
void PrintMap(map<char, int> const &theMap) {
  for (auto const pair: theMap) {
    cout << "{" << pair.first << ": " << pair.second << "}" << endl;
  }
}

/****************************************************
 * WordToValue() computes the numerical value of a
 * word. This will be used to support testing each
 * case of the cryptarithmetic puzzle. The word must
 * have all of its digits within the passed table.
 * Params: 
 *       	word -- the combination of letters to find
 *                 thier integer value.
 *      lookup -- a map to lookup digit values.
 ***************************************************/
int WordToValue(string const &word, map<char, int> const &lookup) {
  int value = 0;
  for (unsigned int i = 0; i < word.length(); ++i) {
    int letter_value = lookup.at(word.at(i));
    value = value*10 + letter_value;
  }
  return value;
}

/********************************************************
 * IsValid() checks a candidate solution to the crypt-
 * arithmetic for correctness.
 * Params: 
 * 	 addend -- the first word to "add"
 * 	addend2 -- the second word t0 "add"
 *      end -- the two addends percieved sum
 *   theMap -- a map to support the use of WordToValue()
 *******************************************************/
bool IsValid(string const &addend, string const &addend2,
               string const &end, map<char, int> const &lookup) {
  int addend_sum = WordToValue(addend, lookup) + WordToValue(addend2, lookup);
  int sum = WordToValue(end, lookup);
  return (addend_sum == sum);
}

/******************************************************
* The Cryptarithmetic Brute-Force Idea:
*   Read the input, then put all of its digits into a 
*   map. Test all value of this map for equality.
******************************************************/
int main(int argc, char *argv[]) {
  // 1. Read the input.
  string input;
  cin >> input;
  // 1(a). Parse the input for addends and sum. This is done
  // for sufficient error checks.
  int delim1 = input.find('+'); // We assume identical inputs
  int delim2 = input.find('=');
  //*Note: substr(x,y) gets Y number of characters after X.
  string addend1 = input.substr(0, delim1);
  string addend2 = input.substr(delim1+1, delim2-delim1-1);
  string sum = input.substr(delim2+1, input.length());

  cout << "Addend1 is: " << addend1 << endl;
  cout << "Addend2 is: " << addend2 << endl;
  cout << "The sum is: " << sum << endl;
  cout << "Adding these characters to a map..." << endl;
  cout << endl;
  
  // 2. Create Table of all letters.
  map<char, int> digits;
  for (unsigned int i = 0; i < input.length(); ++i) {
    if (input.at(i) != '+' && input.at(i) != '=') {
      if (digits.find(input.at(i)) == digits.end()){
        // Give the map key an initial value.
        digits[input.at(i)] = 0;
      }
    }
  }
  // 2a. Print the map for error checking.
  cout << "MAP INITIALIZATION..." << endl;
  PrintMap(digits);
  cout << endl;
  
  // TODO: For candidate solutions, push_back() values into
  //       a vector of maps if criteria is met.
  /*
    vector<map<char, int>> candidate_solutions;
    if (IsValid())...){
      candidate_solutions.push_back(the current map)
    }
  */
  
  // 3. Exhaust all possibilites of digits for the words.
  // For each key in the map, i.e.--each digit.
  for (const auto& pair : digits) {
    // For each digit value in the map
    for (const auto& value : digits.second){
      for (int i = 0; i < 9; ++i) {

      }
    }
  }
  return 0;
}

int permute (map<char, int> Map, int count) {
  for (int i = 0; i < Map.size(); ++i) {

  }
}

