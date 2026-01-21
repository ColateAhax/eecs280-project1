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

void test_sum_small_data_set();

void compare(vector<double> v, vector<double> b);

void test_count();
void test_sum();
void test_mean();
void test_median();
void test_min();
void test_max();
void test_stdev();
void test_percentile();
void test_filter();

// Add prototypes for you test functions here.

// Precision for floating point comparison
const double epsilon = 0.00001;

static bool almost_equal(double x, double y) 
{
  return abs(x - y) < epsilon;
}

int main() {
  test_sum_small_data_set();
  // Call your test functions here

  test_count();
  test_mean();
  test_median();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  test_filter();
  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}
// Add the test function implementations here.
void test_count()
{
  //checks for empty vector
  vector<double> v_1 = {};

  //checks for single vector
  vector<double> v_2 = {1};

  //cehcks for multiple vectors
  vector<double> v_3 = {1, 2, 3};

  assert(count(v_1) == 0);
  assert(count(v_2) == 1);
  assert(count(v_3) == 3);

  cout << "Passed Count Testing" << endl;
}

void test_sum()
{
  //checks for empty vector
  vector<double> v_1 = {};

  //checks for double numbers
  //should be 16.5
  vector<double> v_2 = {1.1, 2.2, 3.3, 4.4, 5.5};

  //chekcs for negative numbers
  //should be 12
  vector<double> v_3 = {-1, -2, -3, 5, 6, 7};

  assert(count(v_1) == 0);
  assert(count(v_2) == 16.5);
  assert(count(v_3) == 12);
  cout << "Passed Sum Testing" << endl;
}

void test_mean()
{
  //checks for negative ints
  //should be 3.4
  vector<double> v_1 = {-1, -5, 10, 16, -3};

  //checks for doubles
  //should be 3.3
  vector<double> v_2 = {1.1, 2.2, 3.3, 4.4, 5.5};

  assert(almost_equal(mean(v_1), 3.4));
  assert(almost_equal(mean(v_2), 3.3));

  cout << "Passed Mean Testing" << endl;
}

void test_median()
{
  //checks for even size
  //should be 8.5
  vector<double> v_1 = {5, 6, 8, 9, 10, 15};

  //checks for odd size
  //should be 6
  vector<double> v_2 = {1, 4, 6, 7, 10};

  //checks for even size that is out of order
  //should be 5.3
  vector<double> v_3 = {7, 4, 10, 3, 20, 1, -4, 6.6};

  assert(almost_equal(median(v_1), 8.5));
  assert(median(v_2) == 6);
  assert(almost_equal(median(v_3), 5.3));

  cout << "Passed Median Testing" << endl;
}

void test_min()
{
  //checks for array of 1
  //should be 5
  vector<double> v_1 = {5};

  //checks for negative numbers
  //should be -7
  vector<double> v_2 = {1, 4, 6, -7, 10};

  //checks for doubles
  //should be 1.1
  vector<double> v_3 = {11, 4, 6, 1.1, 10};

  assert(min(v_1) == 5);
  assert(min(v_2) == -7);
  assert(almost_equal(min(v_3), 1.1));

  cout << "Passed Min Testing" << endl;
}

void test_max()
{
  //checks for array of 1
  //should be 5
  vector<double> v_1 = {5};

  //checks for negative numbers
  //should be -1
  vector<double> v_2 = {-1, -4, -6, -7, -10};

  //checks for doubles
  //should be 11.3
  vector<double> v_3 = {11.3, 4, 6, 1.1, 10};

  assert(max(v_1) == 5);
  assert(max(v_2) == -1);
  assert(almost_equal(max(v_3), 11.3));

  cout << "Passed Max Testing" << endl;
}

void test_stdev()
{
  //checks for same value
  //should be 0
  vector<double> v_1 = {3, 3, 3, 3, 3, 3};

  //checks for single vector
  //should be 6.68331255192
  vector<double> v_2 = {5, -4, -3, 10};

  //cehcks for other random vector
  //should be 20.6228029133
  vector<double> v_3 = {1, 10 , 3, 4, 50};

  assert(stdev(v_1) == 0);
  assert(almost_equal(stdev(v_2), 6.68331255192));
  assert(almost_equal(stdev(v_3), 20.6228029133));

  cout << "Passed Stdev Testing" << endl;
}

void test_percentile()
{
  //checks for normal vector
  //should be 3.5
  vector<double> v_1 = {1, 2, 3, 4, 5, 6};

  //checks for previous vector out of order
  vector<double> v_2 = {4, 1, 6, 3, 2, 5};

  //checks for data set with doubles
  //should be 1.1275
  vector<double> v_3 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

  assert(almost_equal(percentile(v_1, .5), 3.5));
  assert(almost_equal(percentile(v_2, .5), 3.5));
  assert(almost_equal(percentile(v_3, .5), 3.85));
  
  //chekcs for when p = 1
  assert(almost_equal(percentile(v_1, 1), 6));

   //chekcs for when p = 0
  assert(almost_equal(percentile(v_1, 0), 1));

  cout << "Passed Percentile Testing" << endl;
}

void test_filter()
{
  //using the example given in the proj description
  vector<double> locations = {0, 1, 0, 1, 1, 2, 2, 0, 1};
  vector<double> temps = {15.5, 23.1, 7.8, 19.2, 22.6, 4.6, 1.9, 14.3, 18.0};
  // Filter to the temperature measurements at location 1
  vector<double> temps_1 = filter(temps, locations, 1);
  vector<double> correct_temps_1 = {23.1, 19.2, 22.6, 18.0};
  compare(temps_1, correct_temps_1);

  //when doubles are in the location
  vector<double> locations_2 = {0, 1.1, 0, 1.1, 1.1, 2.2, 2.2, 0, 1.1};
  vector<double> temps_2 = filter(temps, locations_2, 1.1);
  compare(temps_2, correct_temps_1);

  //when there are no mathces
  vector<double> temps_3 = filter(temps, locations, 100);
  compare(temps_3, {});

  cout << "Passed Filter Testing" << endl;
}

//compares that 2 arrays are identical
void compare(vector<double> v, vector<double> b)
{
  assert(v.size() == b.size());
  for (size_t i = 0; i < v.size(); i++)
  {
    assert(almost_equal(v[i], b[i]));
  }
}