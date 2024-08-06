#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>
#include "Perceptron.h"

class MultilayerPerceptron {
private:
	std::vector<std::vector<Perceptron*>> *network; // Creates layers of perceptrons
public:
	void operate();
	__global__ void run(std::vector<std::vector<Perceptron*>> *network);
	__global__ void backProp(std::vector<std::vector<Perceptron*>>* network);
};