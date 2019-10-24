/*#########################################################
Project 2 for CSCE350 solves a cryptartihmetic puzzle.
Meaning, two english words are added to produce a sum. Each
letter in the word correlates to a single digit number.
These numbers do not have to be in the order of [A=0, B=1,
C=2,D=3,...Z=25]. This ordering is arbitrary. 

The goal is to SOLVE this puzzle, by computing the value
for each letter.

Project 2 requires a _Brute-Force_ approach. We know of
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
#include <typeinfo>

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
  for (auto const pair: theMap) {
    cout << "{" << pair.first << ": " << pair.second << "}" << endl;
  }
}

void PrintSolutions(map<char, int> const &theMap, vector<map<char, int>> &sol) {

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
/*
string ValueToWord(int value, map<char, int> &lookup) {
  // Find the length of the value.
  int length = 1;
  int temp_val = value;
  string word = "";
  while (temp_val > 0) {
    length = length + 1;
    temp_val =temp_val/10;
  }
  // Compute the value's string equivalent.
  for (int i = 0; i < length; ++i) {
    int to_add = value % 10;
    value = value / 10;
    for (map<char, int>::iterator it = lookup.begin();
            it != lookup.end(); ++it){
      //TODO: see why errors are occuring below. 
      cout << "it->first " << it->first << "  it->second: " <<
           it->second << " | val: " << to_add << endl;
      if (it->second == to_add) {
        //const char * one_char = it->first;
        //cout << typeid(it->first).name() <<endl;
        //word.insert(0, one_char);
      }
    }
  } 
  return word;
}
*/

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
  int addend_sum = WordToValue(addend, lookup) +
                       WordToValue(addend2, lookup);
  int sum = WordToValue(end, lookup);
  // We know this is a bogus solution.
  if (addend_sum == 0 && sum == 0) {
    return false;
  }
  return (addend_sum == sum);
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
*       iter -- an iterator object to move thorugh the
*                map
*  solutions -- a vector of possible solutions for use
*                during the checking. This is passed by
*                reference, as we will need to modify
*                the original values.
*****************************************************/
void Permute (const map<char, int> &lookup, auto &iter, const string &addend1,
        const string &addend2, const string &sum) {
  // Base Case--we've iterated through the whole map.
  if (iter == lookup.end()) {
    PrintMap(lookup);
    /*if (IsValid(addend1, addend2, sum, lookup)){
    cout << "CORRECT" << endl;
    }*/
    return;
  }
  // For each letter's possibility
  for (int i = 0; i < 10; ++i) {
    lookup[iter->first] = i;
    //cout << iter->first << " : " << iter->second << endl; 
    Permute(lookup, ++iter, solutions, addend1, addend2, sum);
  }
}

/***************************EXECUTION FUNCTION***********************/

/******************************************************
* The Cryptarithmetic Brute-Force Idea:
*   Read the input, then put all of its digits into a 
*   map. Test all value of this map for equality.
******************************************************/
int main(int argc, char *argv[]) {
  string line;
  while (getline(cin, line)) {
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
  
    // TODO: Test ValuetoWord()
    //string test = ValueToWord(45, digits);
    //cout << test << endl;
  
    /* 3. Exhaust all possibilites of digits for the words.
     * For each key in the map, i.e.--each digit.
     * THE IDEA:
     *   - Permute the map by checking each digit
     *   - Store map possibilites in a vector.
     */
    vector<map<char, int>> candidate_solutions;
    int counter=0; 
    // Begin at the first value of the map. 
    for (map<char, int>::iterator it = digits.begin();
              it != digits.end(); ++it) {
      // Give it all possibilities of [0,9].
      for (int i = 0; i < 10; ++i) {
        digits[it->first] = i;
        // Cycle through the remainder of the map.
        for (map<char, int>::reverse_iterator rit = digits.rbegin(); 
            rit!=digits.rend(); ++rit){
          //Assign the remainder all possible values.
          for (int j = 0; j < 10; ++j) {
            digits[rit->first] = j;
            PrintMap(digits);
            ++counter;
            cout << endl;
            if(IsValid(addend1, addend2, sum, digits)){
              cout<<"**********CORRECT************"<<endl;
              //TODO : dont' add duplicates
              candidate_solutions.push_back(digits);
            }
          }
        }    
      }
    }

    cout << counter << endl;
    cout << endl;
    cout << "SOLUTIONS" << endl;
    for (auto &it : candidate_solutions) {
      PrintMap(it);
      cout << endl;
    }
    // Print solutions
    if (candidate_solutions.empty() == true) {
      cout << "no solution" << endl; 
    } else {
      for (unsigned int i = 0; i < input.length(); ++i) {
        char x = input.at(i);
        if (x == '=' || x == '+') {
          cout << x;
        } else {
    
        }
      }
      cout << endl;
    }

    
  } // ENDWHILE
  return 0;
}