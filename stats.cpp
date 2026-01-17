// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

int count(vector<double> v) {
    // Simply call the size function for the count
    return v.size();
}

double sum(vector<double> v) {
    // Check v isn't empty
    assert(v.size() > 0);
    // Create a sum value thats 0
    double sum = 0;
    for(size_t i = 0; i < v.size(); i++){
        // For every value in the vector add to the sum value
        sum += v[i];
    }
    return sum;
}

double mean(vector<double> v) {
    // Check v isn't empty
    assert(v.size() > 0);
    // Divide the sum by the number of values
    return sum(v)/count(v);
}

double median(vector<double> v) {
    // Check v isn't empty
    assert(v.size() > 0);
    double median;
    // Sort the vector by value
    std::sort(v.begin(), v.end());

    // If the vector has an even number of values average the middle two numbers
    if(count(v) % 2 == 0){
        median = (v[(count(v) / 2)] + v[(count(v) / 2 - 1)]) / 2;
    } else {
        // If the vector has an odd number of values find the middle value
        median = v[(count(v) / 2)];
    }
    return median;
} 

double min(vector<double> v) {
    // Check v isn't empty
    assert(v.size() > 0);
    // Sort the vector
    std::sort(v.begin(), v.end());
    // Return the first value, it will be the minimum
    return v[0];
}

double max(vector<double> v) {
    // Check v isn't empty
    assert(v.size() > 0);
    // Sort the vector
    std::sort(v.begin(), v.end());
    // Recturn the last value, it will the the maximum
    return v[v.size()-1];
}

double stdev(vector<double> v) {
    // Check v isn't empty
    assert(v.size() > 1);
    double sum = 0;
    double m = mean(v);
    // For every value in the vector add to the sum the difference between the mean the value squared
    for (size_t i = 0; i < v.size(); i++){
        sum += pow(std::abs((v[i])-(m)),2);
    }
    // Take the square root of the sum over the size minus 1 of the vector
    return sqrt((sum/(v.size() - 1)));
}

double percentile(vector<double> v, double p) {
    // Check v isn't empty & p is between 0 and 1
    assert(v.size() > 0);
    assert(p >= 0 && p <= 1);
    double rank;
    double intpart = 0;
    double fractpart = 0;
    double percentile;
    // Sort the vector
    std::sort(v.begin(), v.end());

    // Calculate the rank by multipling p with the vector size minus 1
    rank = p*(v.size()-1);
    // Split into the fraction part with modf function
    fractpart = modf(rank, &intpart);
    
    // Check if its the 0th percentile (1st number)
    if (p <= 0.0) {
    percentile = v[0];
     // Check if its the 100th percentile (last number)
    } else if(p == 1){
        percentile = v[v.size()-1];
    // Otherwise use the seperated integer part and fraction part to plug into the percentile formula
    } else {
        percentile = v[intpart] + fractpart*(v[intpart+1]-v[intpart]);
    }

    return percentile;
}

vector<double> filter(vector<double> v, vector<double> criteria, double target) {
    // Check v isn't empty & p is between 0 and 1
    assert(v.size() == criteria.size());
    // Create an emtpy vector to add to
    vector<double> filtered;
    // For every value in the vector if the indexed criteria value matches the target value, add to the emtpy vector
    for(size_t i = 0; i < v.size(); i++){
        if(criteria[i] == target){
            filtered.push_back(v[i]);
        }
    }
    return filtered;
}
