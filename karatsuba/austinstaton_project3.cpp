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
#include <algorithm> // Transform
#include <functional> // Plus

using std::cin;
using std::cout;
using std::endl;
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
}
/*********************************************************
 *  CorrectVector() is a helper function for Sum(). When
 *  computing the sum, I don't manage a carrying digit to
 *  add to the next highest digit value. This function
 *  is what fixes that error.
 *  Param:
 *      theVector -- the vector that needs correction
 *      e.g. -- [6, 6, 6] + [6, 6, 6] = [12, 12, 12]
 *         After Correction: [12, 12, 12] = [1, 3, 3, 2] 
 ********************************************************/
void CorrectVector(vector<int> &theVector) {
  for (unsigned int i = theVector.size()-1; i != 0; --i) {
    if (theVector.at(i) > 9 && i != 0) {
      theVector.at(i) -= 10;
      theVector.at(i-1)++;
    }
    else if (theVector.at(i) > 9 && i == 0) {
      theVector.at(i) -= 10;
      theVector.insert(theVector.begin(), 1);
    }
  } 
}

/*********************************************************
 * Sum() will compute the sum of two numbers where indiv-
 * idual values are stored in vectors.
 * Params:
 *     a -- the first addend vector
 *     b -- the second addend vector
 ********************************************************/
vector<int> Sum(vector<int> const &a, vector<int> const &b) {
  cout << "Sum()" << endl;
  vector<int> sum;
  if (a.size() > b.size()) {
    sum = a; 
    for (unsigned int i = 0; i < a.size(); ++i) {
      sum[i] += b[i];
    }
  } else {
    sum = b;
    for (unsigned int i = 0; i < b.size(); ++i) {
      sum[i] += a[i];
    }
  }
  CorrectVector(sum)
  //TODO: UNIT TEST THIS
  return sum;
}
/*********************************************************
 * BruteForceMultiply() implements the basic algorithm for
 * digit multiplication that many young kids learn in
 * elementary school. A product of the multiplication will
 * be returned from the function.
 * Params:
 *     a -- the first vector factor
 *     b -- the second vector factor
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
  //cout << endl;
  //PrintVector(b);
  //cout << endl;


  vector<int> c;
  for (int i = 0; i < 4; ++i) {
    c.push_back(12);
  }
  PrintVector(c); 
  cout << endl;
  CorrectVector(c);
  PrintVector(c);
  /*
  vector<int> sum = Sum(a,b);
  PrintVector(sum);
  */ 
  /*
  vector<int> bf = BruteForceMultiply(a, b);
  cout << "B: " << PrintVector(bf) << endl;
  */
  /*
  vector<int> k = KaratsubaMultiply(a,b);
  cout << "K: " << PrintVector(k) << endl; 
  */
  return 0;
}
