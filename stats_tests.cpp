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
void testing(vector<double> data, vector<double> correct, double p);
void testing_filter(vector<double> data, vector<double> criteria, vector<double> correct, double target);

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  // Call your test functions here

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;
  
  //TESTING 1
  //Used Desmos Graphing Calculator to get most of these Stats

  //length 10
  //sum 52
  //mean 5.2
  //median 4.5
  //max 12
  //min 1
  //stdev 3.74046937043
  //Percentile (.5); rank = 5.5; ==> 4.5

  vector<double> criteria_1 =
                          {1, 0, 0, 1  , 1, 3, 2,   2,  1,  1};
  vector<double> data_1 = {1, 1, 2, 3.4, 4, 5, 6, 7.6, 10, 12};
  vector<double> correct_filter_1 = {1, 3.4, 4, 10, 12};
  double target_1 = 1;
  double p_1 = .5;
  vector<double> correct_data_1 = {10, 52, 5.2, 4.5, 12, 1, 3.74046937043, 4.5};
  testing(data_1, correct_data_1, p_1);
  testing_filter(data_1, criteria_1, correct_filter_1, target_1);


  //TESTING 2
  ////Used Desmos Graphing Calculator to get most of these Stats

  //length 7
  //sum 48
  //mean 6.85714285714
  //median 7
  //max 12.9
  //min 2
  //stdev 3.76114217708
  //Percentile (1.0); Should return last number ==> 12.9

  vector<double> criteria_2 =
                          {.4, .3,.3,.3,.4, .5, .3};
  vector<double> data_2 = {2, 3.1, 6, 7, 7, 10, 12.9};
  vector<double> correct_filter_2 = {3.1, 6, 7, 12.9};
  double target_2 = .3;
  double p_2 = 1.0;
  vector<double> correct_data_2 = {7, 48, 6.85714285714, 7, 12.9, 2, 3.76114217708, 12.9};
  testing(data_2, correct_data_2, p_2);
  testing_filter(data_2, criteria_2, correct_filter_2, target_2);

  //if percentile is 0.0; Should return first number ==> 2
  vector<double> correct_data_3 = {7, 48, 6.85714285714, 7, 12.9, 2, 3.76114217708, 2};
  testing(data_2, correct_data_3, 0.0);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.
void testing(vector<double> data, vector<double> correct, double p)
{
  assert(almost_equal(count(data), correct[0]));

  assert(almost_equal(sum(data), correct[1]));

  assert(almost_equal(mean(data), correct[2]));
  
  assert(almost_equal(median(data), correct[3]));

  assert(almost_equal(max(data), correct[4]));

  assert(almost_equal(min(data), correct[5]));

  assert(almost_equal(stdev(data), correct[6]));

  assert(almost_equal(percentile(data, p), correct[7]));

  cout << "Passed Round of Testing" << endl;
}

void testing_filter(vector<double> data, vector<double> criteria, vector<double> correct, double target)
{
  vector<double> potential = filter(data, criteria, target);
  assert(potential.size() == correct.size());
  for(size_t i = 0; i < correct.size(); i++)
  {
    assert(almost_equal(correct[i], potential[i]));
  }
  cout << "Passed Filter Testing" << endl;
}
