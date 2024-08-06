#include "Perceptron.h"

double frand() {
	return (2.0 * (double)rand() / RAND_MAX) - 1.0;
}

Perceptron::Perceptron(size_t inputs) {
	// Consructor that specifies the number of inputs
	this->bias = 1;

	// Randomizes the initial weights
	this->weights.resize(inputs + 1);
	generate(weights.begin(), weights.end(), frand);

}

Perceptron::Perceptron(size_t inputs, double bias) {
	// Overload constructor that specifies the number of inputs and a bias
	
	// Create a vector of randomized weights
}

void Perceptron::getWeights();

std::vector<double> Perceptron::getWeights() {
	return weights;
}