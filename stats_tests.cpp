/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Statistics Project
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

// Precision for floating point comparison
const double epsilon = 0.00001;

static bool almost_equal(double x, double y) {
  return abs(x - y) < epsilon;
}

void test_sum_small_data_set();
void testing(vector<double> data, vector<double> correct);

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  // Call your test functions here

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  //length 10
  //sum 52
  //mean 5.2
  //median 4.5
  //stdev 3.74046937043
  vector<double> data_1 = {1, 1, 2, 3.4, 4, 5, 6, 7.6, 10, 12};
  vector<double> correct_data_1 = {10, 52, 5.2, 4.5, 12, 1, 3.74046937043};
  testing(data_1, correct_data_1);

  //length 7
  //sum 48
  //mean 6.85714285714
  //median 7
  //stdev 3.76114217708
  vector<double> data_2 = {2, 3.1, 6, 7, 7, 10, 12.9};
  vector<double> correct_data_2 = {7, 48, 6.85714285714, 7, 12.9, 2, 3.76114217708};
  testing(data_2, correct_data_2);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.
void testing(vector<double> data, vector<double> correct)
{
  assert(almost_equal(count(data), correct[0]));

  assert(almost_equal(sum(data), correct[1]));

  assert(almost_equal(mean(data), correct[2]));
  
  assert(almost_equal(median(data), correct[3]));

  assert(almost_equal(max(data), correct[4]));

  assert(almost_equal(min(data), correct[5]));

  assert(almost_equal(stdev(data), correct[6]));

  cout << "Passed Testing" << endl;
}
