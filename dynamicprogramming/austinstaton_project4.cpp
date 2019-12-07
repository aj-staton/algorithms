/*#########################################################
Project 4 for CSCE 350 uses dynamic programming to find
palindromes within all substrings of a word.

Copyright: Austin Staton
Date: December 3rd, 2019

I will be using resources from cplusplus.com.
#########################################################*/
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*********************************************************
 * PrintVector() is a helper function to print the content
 * of a vector to standard output.
 * Param:
 *     theVector -- the vector to be printed.
 ********************************************************/
template <class T>
void PrintVector(vector<T> const &theVector) {
  cout << "[";
  for (unsigned int i = 0; i < theVector.size(); ++i) {
    cout << theVector.at(i);
    if (i != theVector.size()-1) {
      cout << ",";
    }
  }
  cout << "]";
}
/******************************************************
 * isPalindrome() will check to see if a word is a
 * Palindrome. Meaning, are the letters in the word 
 * a "mirror".
 * e.g. -- "abbblbbba", "a", "aa" == True
 *         "abcblbcsj", "bd" == False
 * Param:
 *     word -- the string to check whether or not is a
 *             palindrome.
 *   indent -- only used to track recursion depth for
 *             output formatting.
 *****************************************************/
bool isPalindrome(string word) {
  if (word.length() == 1 || word.length() == 0) {
    return true;
  } else if (word.length() == 2) {
    if (word.at(0) == word.at(1)) {
      return true;
    }   
  } else {
  // Check to see if the first and last charaters are the same.
  // if they aren't, we know the word isn't a palindrome.
    // cout << word << endl; 
    if (word.at(0) == word.at(word.length()-1)){
      // TODO: make this faster
      return isPalindrome(word.substr(1, word.length()-2));
    } else {
      return false;
    }
  }
}

int numCuts(string word) {
  if (word.length() == 1) {
    return 0;
  } else if (word.length() == 2 && word.at(0) == word.at(1)) {
    return 0;
  } else {
    return 1 + numCuts(word.substr(1));
  }
}
/**********************EXECUTION**********************/
int main(int argc, char *argv[]) {
  string line;
  while (getline(cin, line) && cin.eof() != true) {
    // 1. Read the input.
    string input = line;
    cout << "INPUT: " << input << endl;
    // 2. Create a solution table so we can easily lookup our
    //    pre-computed values.
    vector<int> num_cuts(input.length()); // The number of cuts it takes create a palidrome
    vector<string> solution_strings(input.length()); // Potential substrings
    vector<int> index_of_last_cut(input.length()); // The index of the last cut in the substr.
  
    for (int i = 1; i < input.length()+1; ++i) {
      string temp = input.substr(0, i);
      solution_strings[temp.length()] = temp;
      cout << "OUTSIDE: " << temp << endl;
      // Pre-Compute Early table lookup values.
      if (temp.length() == 1 || temp.length() == 0) {
        num_cuts[temp.length()] = 0;
        index_of_last_cut[temp.length()-1] = 0;
      } else if (temp.length() == 2 && temp.at(0) == temp.at(1)) {
        num_cuts[temp.length()] = 0;
        index_of_last_cut[temp.length()] = 0;
      } else if (temp.length() == 2 && temp.at(0) != temp.at(1)){
        num_cuts[temp.length()] = 1;
      }
      // Loop to find the last cut in the string.
      for (int j = 0; j < temp.length(); ++j) {
        int minimum_cuts;
        string temp2 = temp.substr(j, temp.length());
        cout << "  IN: "  << temp2; 
        if (isPalindrome(temp2)) {
          cout << " PALINDROME and the cost to cut '";
          string temp3 = input.substr(0, j);
          cout << temp3 << "' is ";
          cout << num_cuts[temp3.length()];
         // We know for 'ab|b', that 'b' is a palindrome. Lookup cuts for 'ab'.
        }
        cout << endl;
      }
      cout << "\n\n";
    }

    //PrintVector(num_cuts);
    cout << "\n";
    //PrintVector(solution_strings);
    cout << "\n\n";
  }
  return 0;
}
