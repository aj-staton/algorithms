/*#########################################################
Project 2 for CSCE 350 solves a cryptartihmetic puzzle.
Meaning, two english words are added to produce a sum. Each
letter in the word correlates to a single digit number.
These numbers do not have to be in the order of [A=0, B=1,
C=2,D=3,...Z=25]. This ordering is arbitrary. 

Example: send+more=money --> 9567=1085=10652

The goal is to SOLVE this puzzle, by computing the value
for each letter.

Project 2 requires a Brute-Force approach. We know of
better ways to solve this problem; however, as a learning
exercise, we must use exhast all options.

Copyright: Austin Staton
Date: October 9th, 2019

I will be using resources from cplusplus.com.
#########################################################*/

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm> //Count()

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
using std::find;

/************************HELPER FUCTIONS************************/

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
  cout << endl;
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
/******************************************************
 * HasDuplicates() will determine if a map has duplicate
 * values to the keys within it.
 * TODO: Find a more efficient way to handle checking
 * for duplicates.
 * Param:
 *   lookup -- a map of with char->int. This function
 *          will check for duplicate values (ints).
 *****************************************************/
bool HasDuplicates(map<char, int> &lookup) {
  vector<int> values;
  int dup = 0;
  for (map<char, int>::iterator it = lookup.begin(); it!= lookup.end(); ++it) {
      dup = count(values.begin(), values.end(), it->second);
      if (dup != 0) {
        return true;
      }
      values.push_back(it->second);
  }
  return false;
}
/********************************************************
 * IsValid() checks a candidate solution to the crypt-
 * arithmetic for correctness.
 * Params: 
 * 	 addend1 -- the first word to "add"
 * 	addend2 -- the second word t0 "add"
 *      end -- the two addends percieved sum
 *   theMap -- a map to support the use of WordToValue()
 *******************************************************/
bool IsValid(string const &addend1, string const &addend2,
               string const &end, map<char, int> &lookup) {
  int addend_sum = WordToValue(addend1, lookup) +
                       WordToValue(addend2, lookup);
  int sum = WordToValue(end, lookup);
  // We know this is a bogus solution.
  if (lookup.at(addend1.at(0)) == 0 || lookup.at(addend2.at(0)) == 0 ||
        lookup.at(end.at(0))==0) {
    return false;
  }
  if (HasDuplicates(lookup)) {
    return false;
  }
  if (addend_sum == 0 && sum == 0) {
    return false;
  }
  return (addend_sum == sum);
}
/******************************************************
 * PrintSolution() will parse the inputted addends and
 * sum, all of which are correct, and print them to 
 * standard output. It will go letter-by-letter in the
 * addends and the sum to create the output string.
 * Params:
 *     addend1 -- the first portion of the std input
 *     addend2 -- the second portion of the std input
 *         sum -- the total sum of the std input
 *      lookup -- a table of values for char->int
 *****************************************************/
void PrintSolution(string const &addend1, string const &addend2,
                string const &sum, map<char, int> const &lookup){
  for (unsigned int i = 0; i < addend1.length(); ++i) {
      char letter = addend1.at(i);
      int letter_value = lookup.at(letter);
      cout << letter_value;
  }
  cout << "+";
  for (unsigned int i = 0; i < addend2.length(); ++i) {
      char letter = addend2.at(i);
      int letter_value = lookup.at(letter);
      cout << letter_value;
  }
  cout << "=";
  for (unsigned int i = 0; i < sum.length(); ++i) {
      char letter = sum.at(i);
      int letter_value = lookup.at(letter);
      cout << letter_value;
  }
}
/*****************************************************
* Permute() is a recursive helper functions for the
* exhaustve search needed to solve this problem.
* For each level of the recursion, a different value
* in the map will be tested. Once we've generated all
* possible solutions, throught the recursion (i.e.--
* once the base case is hit) begin to check these
* possible solutions.
* Params:
*     lookup -- a map storing the digits and values.
*      start -- an iterator object to move thorugh the map
*        end -- the iterative end of the parsed map
*    addend1 -- the first portion of the cryptarithmetic sum
*    addend2 -- the second portion of the cryptarithmetic sum
*        sum -- the intended value for the cryptarithmetic sum
*****************************************************/
void Permute (map<char, int> &lookup, map<char, int>::iterator const &start,
        map<char, int>::iterator const &end, int &num_correct,
         string const &addend1, string const &addend2, string const &sum) {
  // Base Case--we've iterated through the whole map.
  if (start == end) {
    if (IsValid(addend1, addend2, sum, lookup)){
      PrintSolution(addend1, addend2, sum, lookup);
      //PrintMap(lookup);
      ++num_correct;
      cout << endl;
    }
    return;
  }
  // At each layer of recursion, assign a new value to a letter.
  for (int i = 0; i < 10; ++i) {
    start->second = i;
    Permute(lookup, next(start, 1), end, num_correct, addend1, addend2, sum);
  }
}
/**********************EXECUTION**********************/
/******************************************************
* The Cryptarithmetic Brute-Force Idea:
* Read the input, then put all of its digits into a 
* map. Test all value of this map for equality.
******************************************************/
int main(int argc, char *argv[]) {
  string line;
  while (getline(cin, line) && cin.eof() != true) {
    // 1. Read the input.
    string input = line;
    //cin >> input;
    // 1(a). Parse the input for addends and sum. This is done
    // for sufficient error checks.
    int delim1 = input.find('+'); // We assume identical inputs
    int delim2 = input.find('=');
    //*Note: substr(x,y) gets Y number of characters after X.
    string addend1 = input.substr(0, delim1);
    string addend2 = input.substr(delim1+1, delim2-delim1-1);
    string sum = input.substr(delim2+1, input.length());
    /*
    cout << "Addend1 is: " << addend1 << endl;
    cout << "Addend2 is: " << addend2 << endl;
    cout << "The sum is: " << sum << endl;
    cout << "Adding these characters to a map..." << endl;
    cout << endl;
    */
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
    /*
    cout << "MAP INITIALIZATION..." << endl;
    PrintMap(digits);
    cout << endl;
    */
    /* 3. Exhaust all possibilites of digits for the words.
     * For each key in the map, i.e.--each digit.
     * THE IDEA:
     *   - Permute the map by checking each digit
     */
    // The iterator needed by Permute() to traverse the map
    map<char, int>::iterator start = digits.begin();
    map<char, int>::iterator end = digits.end();
    int correct_answers = 0;
    Permute(digits, start, end, correct_answers, addend1, addend2, sum);
    if (correct_answers == 0) {
      cout << "no solution" << endl;
    }
    cout << endl;
  } // ENDWHILE
  return 0;
}
