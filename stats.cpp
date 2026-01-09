// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt, modf

using namespace std;

int count(vector<double> v) {
    return v.size();
}

double sum(vector<double> v) {
    double sum = 0;
    for(size_t i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum;
}

double mean(vector<double> v) {
    return sum(v)/count(v);
}

double median(vector<double> v) {
    double median;
    std::sort(v.begin(), v.end());

    if(count(v) % 2 == 0){
        median = (v[(count(v) % 2)] + v[(count(v) % 2 - 1)]) / 2;
    } else {
        // Don't add one becuase of indexing at 0
        median = v[(count(v) % 2)];
    }
    return median;
} 

double min(vector<double> v) {
    std::sort(v.begin(), v.end());
    return v[0];
}

double max(vector<double> v) {
    std::sort(v.begin(), v.end());
    return v[v.size()-1];
}

double stdev(vector<double> v) {
    double sum;
    for (size_t i = 0; i < v.size(); i++){
        sum += pow((std::abs(v[i])-std::abs(mean(v))),2);
    }
    return sqrt((1.0/(count(v)-1))*sum);
}

double percentile(vector<double> v, double p) {
    double rank;
    double intpart = 0;
    double fractpart = 0;
    double percentile;
    std::sort(v.begin(), v.end());

    rank = p*(v.size()-1);
    fractpart = modf(rank, &intpart);
    int i = static_cast<int>(intpart);
    percentile = v[i] + fractpart*(v[i+1]-v[i]);

    return percentile;
}

vector<double> filter(vector<double> v, vector<double> criteria, double target) {
    vector<double> filtered;
    for(size_t i = 0; i < v.size(); i++){
        if(criteria[i] == target){
            filtered.push_back(v[i]);
        }
    }
    return filtered;
}
