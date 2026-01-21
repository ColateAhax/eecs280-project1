// stats.cpp
#include <iostream>
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

const double epsilon = 0.00001;

static bool almost_equal(double x, double y) 
{
  return abs(x - y) < epsilon;
}

bool isAscending(vector<double> v)
{
  for(size_t i = 1; i < v.size(); i++)
  {
    //checks if the index before is greater than the current index
    //if that is the case then the data set is not ascending (sorted)
    if (v[i - 1] > v[i]) return false;
    return true;
  }

  return true;
}

int count(vector<double> v) 
{
  // int count = 0;
  // for (size_t i = 0; i < v.size(); i++) count++;
  // return count;
  return v.size();
}

double sum(vector<double> v) 
{
  double total = 0.0;
  for (size_t i = 0; i < v.size(); i++) total += v[i];
  return total;
}

double mean(vector<double> v) 
{
  return sum(v)/count(v);
}

double median(vector<double> v) 
{
  //checks that vector is sorted
  if (!isAscending(v)) sort(v.begin(), v.end());
  
    //checks if its odd, if so it grabs the "middle number"
  if (count(v) % 2 != 0) return v[count(v) / 2];

  //otherwise it averages the other 2 numbers closest to the middle
  return (v[count(v) / 2] + v[(count(v) / 2) - 1]) / 2;
}

double min(vector<double> v) 
{
    //by default sets the minimum number to the first number
  int minInd = 0;
  for (size_t i = 1; i < v.size(); i++)
  {
    //sets the current index in the loop as the current number
    double currentNum = v[i];
    double oldNum = v[minInd];

    //checks if the current number is smaller than the old number
    if(currentNum < oldNum) minInd = i;
  }
  return v[minInd];
}

double max(vector<double> v) 
{
    //by default sets the maximum number to the first number
  int maxInd = 0;
  for (size_t i = 1; i < v.size(); i++)
  {
    //sets the current index in the loop as the current number
    double currentNum = v[i];
    double oldNum = v[maxInd];

    //checks if the current number is bigger than the old number
    if(currentNum > oldNum) maxInd = i;
  }
  return v[maxInd];
}

double stdev(vector<double> v) 
{
    //completes the sum
  double sum = 0.0;
  for (size_t i = 0; i < v.size(); i++)
  {
    sum += (v[i] - mean(v)) * (v[i] - mean(v));
  }

  //calculates the number infront of the sum
  double val = 1.0;
  val = val / (count(v) - 1);

  //returns final stdev
  return sqrt(val * sum);
}

double percentile(vector<double> v, double p) 
{
  if (!isAscending(v)) sort(v.begin(), v.end());
  //SPECIAL CASES
  //if percentile is 1
  if (p == 1.0 || fabs(1.0 - p) < 0.00001) return v[v.size() - 1];
  //if percentile is 0
  if (p == 0.0 || fabs(0.0 - p) < 0.00001) return v[0];

  //calculated the rank
  double rankNum = (p * (count(v) - 1)) + 1;
  
  //splits the rank into integer k and decimal d
  int k = rankNum;
  double d = rankNum - k;

  //modifies the original percentile function for an index that starts with 0
  return v[k - 1] + (d * (v[k] - v[k - 1]));
}

vector<double> filter(vector<double> v,
                      vector<double> criteria,
                      double target) 
{
//creates the empty vector
  vector<double> filteredVector;

  //the loop goes through the criteria and when it matches the target
  //it adds the respective index to the new vector
  for(size_t i = 0; i < criteria.size(); i++)
  {
    if (almost_equal(target, criteria[i])) filteredVector.push_back(v[i]);
  }
  return filteredVector;
}
