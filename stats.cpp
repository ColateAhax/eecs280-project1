// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

int count(vector<double> v) {
  int count = 0;
  for (size_t i = 0; i < v.size(); i++) count++;
  return count;
}

double sum(vector<double> v) {
  double total = 0.0;
  for (size_t i = 0; i < v.size(); i++) total += v[i];
  return total;
}

double mean(vector<double> v) {
  return sum(v)/count(v);
}

double median(vector<double> v) {
  if (count(v) % 2 != 0) return v[count(v) / 2];
  return (v[count(v) / 2] + v[(count(v) / 2) + 1]) / 2;
}

double min(vector<double> v) {
  assert(false);
  return 0.0;
}

double max(vector<double> v) {
  assert(false);
  return 0.0;
}

double stdev(vector<double> v) {
  assert(false);
  return 0.0;
}

double percentile(vector<double> v, double p) {
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
