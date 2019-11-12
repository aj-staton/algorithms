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
using std::vector;
using std::string;

/*********************************************************
 * PrintVector() is a helper function to deliver the large
 * numbers to standard output.
 * Param:
 *     theVector -- the vector to be printed.
 ********************************************************/
void PrintVector(vector<int> const &theVector) {
  cout << "[";
  for (unsigned int i = 0; i < theVector.size(); ++i) {
    cout << theVector.at(i);
    if (i != theVector.size()-1) {
      cout << ",";
    }
  }
  cout << "]";
}
/*********************************************************
 * CorrectVector() is a helper function for Sum(). When
 * computing the sum, I don't manage a carrying digit to
 * add to the next highest digit value. This function
 * is what fixes that error. 
 * NOTE: this can also be used to correct something like
 *       [8,16,24,32] to [9,8,7,2] for multiplication 
 * Param:
 *     theVector -- the vector that needs correction
 * 
 *     e.g. -- [6, 6, 6] + [6, 6, 6] = [12, 12, 12]
 *     After Correction: [12, 12, 12] = [1, 3, 3, 2] 
 ********************************************************/
void CorrectVector(vector<int> &theVector) {
  for (unsigned int i = theVector.size()-1; i != 0; --i) {
    if (theVector.at(i) > 9 && i != 0) {
      int big = theVector.at(i) / 10;
      int little = theVector.at(i) % 10;
      theVector.at(i-1) += big;
      theVector.at(i) = little;
    }
    else if (theVector.at(i) > 9 && i == 0) {
      int big = theVector.at(i) / 10;
      int little = theVector.at(i) % 10;
      theVector.insert(theVector.begin(), big);
      theVector.at(i) = little;
    }
  }
}

/***************************************************
 * E() multiplies a vector by a power of 10. Meaning
 * the function appends an appropriate number of 0s
 * to the end of a vector. This function passes the
 * vector to modify by reference for simplicity.
 * Params:
 *      a -- the vector to add 0s to
 *  power -- the number of 0s to add.
 **************************************************/
vector<int> E(vector<int> &a, int power) {
 //TODO: this.
 return a;
}
/***********************************************************
 * Sum() will compute the sum of two numbers where indiv-
 * idual values are stored in vectors. See "CorrectVector()"
 * for the handling of carry-over digits.
 * Params:
 *     a -- the first addend vector
 *     b -- the second addend vector
 ********************************************************/
vector<int> Sum(vector<int> const &a, vector<int> const &b) {
  // Logging
  cout << "Computing the sum of...";
  PrintVector(a);
  cout << " + ";
  PrintVector(b);
  cout << endl;
  // EndLogging

  vector<int> sum = a; 
  for (unsigned int i = 0; i < a.size(); ++i) {
    sum[i] += b[i];
  }
  // Fix the lack of carrying digits.
  cout << "Correcting the computed sum of ...";
  PrintVector(sum);
  CorrectVector(sum);
  cout << " to ";
  PrintVector(sum);
  cout << endl;
  return sum;
}

/**************************************************************
 * VectorDigitProduct() multiplies an entire vector by a single
 * integer digit, and returns the product vector.
 * Params:
 *       a -- the vector used as a factor
 *   digit -- the integer to multiply by
 *************************************************************/
vector<int> VectorDigitProduct(vector<int> a, int digit) {
  // TODO: TEST THIS FUNCTION
  for (int i = 0; i < a.size(); ++i) {
    a.at(i) *= digit;
  }
  // Fix the carry over issues with the helper function. 
  CorrectVector(a);
  return a; 
}

/*********************************************************
 * BruteForceMultiply() implements the basic algorithm for
 * digit multiplication that many young kids learn in
 * elementary school. A product of the multiplication will
 * be returned from the function.
 * Params:
 *     a -- the first factor
 *     b -- the second factor
 ********************************************************/
vector<int> BruteForceMultiply(vector<int> const &a, vector<int> const &b) {
  vector<int> product;
  vector<int> temp;
  
  for (unsigned int i = a.size()-1; i != 0; --i) {
    for (unsigned int j = b.size()-1; i != 0; --j) {
  
    }
  }

  return product; 
}

/*********************************************************
 * KaratsubaMultiply() multiplys together two vectors of
 * digits in a more efficient manner than the grade-school
 * mulitplication method. It does this by doing LESS com-
 * putationally expensive work more often, while doing
 * MORE computationally expensive work less often. The
 * algorithm computes this tradeoff with algebra:
 * a*b = x2*10^2m + x1*10^m + x0
 *  x2 = a1*b1
 *  x1 = a1*b0+b1*a0
 *  x0 = a0*b0
 * 
 * Time Efficiency: n^(logbase(2,3)) ~= n^(1.58)
 *  
 * Params:
 *     a -- the first factor
 *     b -- the second factor
 ********************************************************/
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
  cout << "A: ";
  PrintVector(a);
  cout << endl;
  cout << "B: ";
  PrintVector(b);
  cout << endl;

  // I make both vectors an equivalent size with leading zeros.
  // This makes computations more simple in iteration.
  if (a.size() > b.size()) {
   int difference = a.size() - b.size();
   for (int i = 0; i < difference; ++i) {
     b.insert(b.begin(), 0);
   }
  } else if (b.size() > a.size()) {
    int difference = b.size() - a.size();
    for (int i = 0; i < difference; ++i) {
      a.insert(a.begin(), 0);
    }
  }

  vector<int> sum = Sum(a,b);
  cout << endl;
  
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
