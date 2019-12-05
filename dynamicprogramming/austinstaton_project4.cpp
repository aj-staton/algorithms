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
bool isPalindrome(string word, string indent) {
  if (word.length() == 1) {
    return true;
  } else if (word.length() == 2) {
    if (word.at(0) == word.at(1)) {
      return true;
    }   
  } else {
  // Check to see if the first and last charaters are the same.
  // if they aren't, we know the word isn't a palindrome.
    // cout << indent << word << endl; 
    if (word.at(0) == word.at(word.length()-1)){
      return isPalindrome(word.substr(1, word.length()-2), "  ");
    } else {
      return false;
    }
  }
}

/**********************EXECUTION**********************/
int main(int argc, char *argv[]) {
  string line;
  while (getline(cin, line) && cin.eof() != true) {
    // 1. Read the input.
    string input = line;
    cout << "INPUT: " << input << endl;
    //NOTE: substr(x,y) gets Y number of characters after X.
    //string addend1 = input.substr(0, delim1);

    // 2. Create a solution table so we can easily lookup our
    //    pre-computed values.
    vector<bool> solution_list_bool;
    vector<string> solution_list_string;
    for (int i = 0; i < input.length(); ++i) {
      // 
      if (i == 0) {
        solution_list_bool.push_back(true);
        solution_list_string.push_back(input.substr(0,1));
      } else {
        string temp = input.substr(0, i+1);
        // cout << temp << endl;
        solution_list_string.push_back(temp);
        solution_list_bool.push_back(isPalindrome(temp,""));
      }
    }
    PrintVector(solution_list_bool);
    cout << "\n";
    PrintVector(solution_list_string);
    cout << "\n\n";
  }
  return 0;
}
