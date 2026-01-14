// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

int count(vector<double> v) 
{
  int count = 0;
  for (size_t i = 0; i < v.size(); i++) count++;
  return count;
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
    //checks if its odd, if so it grabs the "middle number"
  if (count(v) % 2 != 0) return v[count(v) / 2];

  //otherwise it averages the other 2 numbers closest to the middle
  return (v[count(v) / 2] + v[(count(v) / 2) + 1]) / 2;
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
  assert(false);
  return 0.0;
}

double percentile(vector<double> v, double p) 
{
  assert(false);
  return 0.0;
}

vector<double> filter(vector<double> v,
                      vector<double> criteria,
                      double target) {
  assert(false);

  std::vector<double> emptyObject;
  return emptyObject;
}
