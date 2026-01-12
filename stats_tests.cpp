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
void test_all_zeros();
void test_with_negatives();
const double epsilon = 0.00001;

int main() {
  test_sum_small_data_set();
  test_all_zeros();
  test_with_negatives();

  return 0;
}

static bool almost_equal(double x, double y) {
  return abs(x - y) < epsilon;
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

void test_all_zeros() {
  cout << "test_all_zeros" << endl;

  vector<double> data(10,0);

  assert(sum(data) == 0);
  assert(median(data) == 0);
  assert(mean(data) == 0);
  assert(min(data)==0);
  assert(stdev(data) == 0);

  cout << "PASS!" << endl;
}

void test_with_negatives() {
  cout << "test_with_negatives" << endl;

  vector<double> data;
  data.push_back(-10);
  data.push_back(2);
  data.push_back(-5);
  data.push_back(4);
  data.push_back(1);
  data.push_back(0);
  data.push_back(-15);

  assert(sum(data) == -23);
  assert(median(data) == 0);
  assert(min(data)==-15);
  assert(almost_equal(stdev(data), 7.01699));

  cout << "PASS!" << endl;
}
//update
void test_identical() {
  cout << "test_identical" << endl;

  vector<double> data(5,5);

  assert(sum(data) == 25);
  assert(median(data) == 5);
  assert(min(data)==5);
  assert(almost_equal(stdev(data), 0));

  cout << "PASS!" << endl;
}

void test_with_decimals() {
  cout << "test_with_decimals" << endl;

  vector<double> data;
  data.push_back(1.202);
  data.push_back(49.293);
  data.push_back(81.32);
  data.push_back(399.12);

  assert(almost_equal(sum(data), 530.935));
  assert(almost_equal(mean(data), 132.73375));
  assert(almost_equal(median(data), 65.3065));
  assert(almost_equal(min(data), 1.202));
  assert(almost_equal(max(data), 399.12));
  assert(almost_equal(stdev(data), 180.7));
  assert(almost_equal(percentile(data, 0.5), 65.3065));

  cout << "PASS!" << endl;
}

void test_mean_zero() {
  cout << "test_mean_zero" << endl;

  vector<double> data;
  data.push_back(-10);
  data.push_back(-2);
  data.push_back(-5);
  data.push_back(10);
  data.push_back(2);
  data.push_back(5);

  assert(sum(data) == 0);
  assert(mean(data) == 0);
  assert(median(data) == 0);
  assert(min(data) == -10);
  assert(max(data) == 10);
  assert(almost_equal(stdev(data), 7.183));
  assert(almost_equal(percentile(data, 0.25), -4.25));

  cout << "PASS!" << endl;
}
