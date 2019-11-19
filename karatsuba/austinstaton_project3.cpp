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
 2) The Karatsuba Algorithm. This algorithm is much more
    efficient, taking n^~1.58 time.

Copyright: Austin Staton
Date: October 31st, 2019

I will be using resources from cplusplus.com
##############################################################*/
#include <iostream>
#include <string>
#include <vector>
/*
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
*/
using namespace std;

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
/******************************************************
 * BalanceVectorSize() adds leading zeros to the front
 * of vectors. This makes calculations much easier,
 * since the size of vectors do not vary in for loops.
 * Params:
 *     a -- the first vector
 *     b -- the second vector
 *****************************************************/
void BalanceVectorSize(vector<int> &a, vector<int> &b) {
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
}
/*******************************************************
 * RemoveZeros() removes any leading, non-significant
 * zeros from the front of a vector. This has to be done
 * because of the use of the BalanceVectorSize()
 * function, which adds leading zeros.
 * This function exists for the pretty formatiing of
 * output.  e.g. - [0,0,4,5,6,0,0] >> [4,5,6,0,0]
 * Param:
 *     a -- the vector to remove the leading zeros from
 ******************************************************/
void RemoveZeros(vector<int> &a) {
  // Find the first significant digit.
  int first_real_number = -1;
  for (int i = 0; i < a.size(); ++i) {
    if (a.at(i) != 0) {
      first_real_number = i;
      break;
    }
  }
  // Leave if the array is filled with 0's. 
  // We need to only have ONE zero.
  if (first_real_number == -1) {
    for (int i = 0; i < a.size() -1; ++i) {
      a.erase(a.begin());
    }
    return;
  }
  // Delete the non-significant digits.
  for (int i = 0; i < first_real_number; ++i) {
    a.erase(a.begin());
  }
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
  for (unsigned int i = theVector.size()-1; i != -1; --i) {
    if (theVector.at(i) > 9 && i == 0) {
      int big = theVector.at(i) / 10;
      int little = theVector.at(i) % 10;
      theVector.at(i) = little;
      theVector.insert(theVector.begin(), little);
      theVector.at(i) = big;
    }
    else if (theVector.at(i) > 9 && i != 0) {
      int big = theVector.at(i) / 10;
      int little = theVector.at(i) % 10;
      theVector.at(i-1) += big;
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
  for (int i = 0; i < power; ++i) {
    a.insert(a.end(), 0);
  }
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
vector<int> Sum(vector<int> &a, vector<int> &b) {
  BalanceVectorSize(a, b);
  vector<int> sum = a; 
  for (unsigned int i = a.size()-1; i != -1; --i) {
    sum[i] += b[i];
  }
  // Fix the lack of carrying digits.
  CorrectVector(sum);
  return sum;
}
/***************************************************
 * Difference() computes the difference between the
 * "numbers" passed in as parameters.
 * NOTE: this computes A-B.
 * Params:
 *     a -- the minuend vector
 *     b -- the subtrahend vector
 **************************************************/
vector<int> Difference(vector<int> a, vector<int> b) {
  BalanceVectorSize(a, b);
  vector<int> diff = a; 
  for (unsigned int i = a.size()-1; i != -1; --i) {
    if (b[i] > a[i] && i != 0) {
      // Remove 10 from the next significant digit
      --diff[i-1];
      diff[i] += 10;
      diff[i] -= b[i];
    }
    else {
      diff[i] -= b[i];
    }
  }
  CorrectVector(diff);
  return diff;
}

/**************************************************************
 * VectorDigitProduct() multiplies an entire vector by a single
 * integer digit, and returns the product vector.
 * Params:
 *       a -- the vector used as a factor
 *   digit -- the integer to multiply by
 *************************************************************/
vector<int> VectorDigitProduct(vector<int> a, int digit) {
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
vector<int> BruteForceMultiply(vector<int> a, vector<int> b) {
  BalanceVectorSize(a,b);
  vector<int> product(a.size(), 0); // Make a vector equal in length, equal to 0.
  vector<int> temp;

  int counter_for_appending_zeros = 0;
  for (unsigned int i = a.size()-1; i != -1; --i) {
    temp = VectorDigitProduct(a, b.at(i));
    for (int i = 0; i < counter_for_appending_zeros; ++i) {
      temp.push_back(0);
    }
    product = Sum(product, temp);
    counter_for_appending_zeros += 1;
  }
  // Format for output.
  RemoveZeros(product);
  return product; 
}

/*********************************************************
 * KaratsubaMultiply() multiplys together two vectors of
 * digits in a more efficient manner than the grade-school
 * mulitplication method. It does this by doing LESS com-
 * putationally expensive work more often, while doing
 * MORE computationally expensive work less often. The
 * algorithm computes this tradeoff with algebra:
 * a*b = c2*10^2m + c1*10^m + c0
 *  c2 = a1*b1
 *  c1 = a1*b0+b1*a0
 *  c0 = a0*b0
 *  --Time Efficiency: n^(logbase(2,3)) ~= n^(1.58)
 * Params:
 *     a -- the first factor
 *     b -- the second factor
 ********************************************************/
vector<int> KaratsubaMultiply(vector<int> a, vector<int> b, string indent) {
  BalanceVectorSize(a, b);
  int n = a.size(); // 'n' i.e. input size
  int m = n/2;
  vector<int> a1, b1, a0, b0;
  if (a.size() == 1) {
    vector<int> ret_vec;
    ret_vec.push_back(a.at(0)*b.at(0));
    CorrectVector(ret_vec);
    // cout << indent << "Returning...";
    // PrintVector(ret_vec);
    return ret_vec;
  }

  // Split vectors to a1,b1,a0,b0.
  for (int i = 0; i < m; ++i) {
    a1.push_back(a.at(i));
    b1.push_back(b.at(i));
  }
  for (int i = m; i < n; i++) {
    a0.push_back(a.at(i));
    b0.push_back(b.at(i));
  }

  vector<int> c2 = KaratsubaMultiply(a1, b1, indent + "  ");
  CorrectVector(c2);
  vector<int> c0 = KaratsubaMultiply(a0, b0, indent + "  ");
  CorrectVector(c0);
  // Calculate c1
  vector<int> sum1 = Sum(a0,a1);
  vector<int> sum2 = Sum(b0,b1);
  vector<int> pro = KaratsubaMultiply(sum1, sum2, indent + "  ");
  
  vector<int> diff = Difference(pro, c2);
  CorrectVector(diff);

  vector<int> c1 = Difference(diff, c0);
  CorrectVector(c1);
  // Work to calculate a*b
  vector<int> first_term = E(c2, 2*m);
  CorrectVector(first_term);
  vector<int> second_term = E(c1, m);
  CorrectVector(second_term);
  vector<int> first_and_second = Sum(first_term, second_term);
  vector<int> answer = Sum(first_and_second, c0);
  RemoveZeros(answer);
  CorrectVector(answer);
  return answer;
}

/********************* Execution Function *******************/
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

  ///*
  cout << "****Inputs****\nA: ";
  PrintVector(a);
  cout << endl;
  cout << "B: ";
  PrintVector(b);
  cout << "\n";
  //*/

  /*
  vector<int> diff = Difference(a, b);
  cout << endl;
  PrintVector(diff);
  */
  
  vector<int> bf = BruteForceMultiply(a, b);
  cout << "B: ";
  PrintVector(bf);
  cout << "\n";
  
  vector<int> k = KaratsubaMultiply(a,b, "");
  cout << "K: ";
  PrintVector(bf);
  cout << "\n"; 
  
  return 0;
}
