#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>

class Perceptron {
public:
	Perceptron(size_t inputs); // Constructor
	Perceptron(size_t inputs, double bias); // Overload constructor
	std::vector<double> getWeights();
	void setWeights(std::vector<double> );
private:
	std::vector<double> weights;
	double bias;
};