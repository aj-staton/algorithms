/*##############################################################
Project 3 for CSCE350 multiplies large numbers (numbers that
struggle to fit in an integer, long, or other type). I will do
this by breaking down the large number into thier own elements
in a vector.

Example: 2,334,345,532,389 * 89,794,289,298,000

This file will solve this problem in two ways:
 1) Brute force. This is the highly intuitive
    approach that many people learn in grade school.
    	1234
       *  21
	1234     This algorithm takes n^2 time.
     + 24680
       25914
 2) The Karatsube Algorithm. This algorithm is much more
    efficient, taking n^~1.58 time.

Copyright: Austin Staton
Date: October 31st, 2019

I will be using resources from cplusplus.com
##############################################################*/
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::stoi; // String to Integer
using std::vector;
using std::string;

/*********************************************************
 * PrintVector() is a helper function to deliver the large
 * numbers to standard output.
 * Param:
 *     theVector -- the vector to be printed.
 ********************************************************/
void PrintVector(vector<int> const &theVector) {
  for (auto const x: theVector) {
    cout << x;
  }
  cout << endl;
}

/*********************************************************
 * Sum() will compute the sum of two numbers where indiv-
 * idual values are stored in vectors. 
 * Params:
 *     a -- the first addend vector
 *     b -- the second addend vector
 ********************************************************/
vector<int> Sum(vector<int> const &a, vector<int> const &b) {
  if (a.size() > b.size()) {

  } else {

  }
  return sum;
}
/*********************************************************
 * 
 ********************************************************/
vector<int> BruteForceMultiply(vector<int> const &a, vector<int> const &b) {
  vector<int> product;
  
  return product; 
}

/********************************************************
 * 
 *******************************************************/
vector<int> KaratsubaMultiply(vector<int> const &a, vector<int> const &b) {
  vector<int> product;
  return product;
}

int main(int argc, char *argv[]) {
  string input;
  cin >> input;

  // Fill vectors with the inputted values. 
  vector<int> a,b; // 'a' is first factor; 'b' is the second.
  int split_position = input.find("*");
  for (unsigned int i = 0; i < split_position; ++i) {
    a.push_back(input.at(i) - 48); // ASCII integers start at 48.
  }
  for (unsigned int i = split_position + 1; i < input.length(); ++i) {
    b.push_back(input.at(i) - 48); // ASCII integers start at 48.
  }
  //PrintVector(a);
  //PrintVector(b);

  vector<int> bf = BruteForceMultiply(a, b);
  cout << "B: " << PrintVector(bf);
  /*
  vector<int> k = KaratsubaMultiply(a,b);
  cout << "K: " << PrintVector(k); 
  */
  return 0;
}
