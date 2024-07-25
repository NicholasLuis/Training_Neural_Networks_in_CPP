#include "MLP.h"
// Last updated: Ch3, L2

double frand(){
	return (2.0*(double)rand() / RAND_MAX) - 1.0;
}


// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(size_t inputs, double bias){
	this->bias = bias;
	weights.resize(inputs+1);
	generate(weights.begin(),weights.end(),frand);
}

// Run the perceptron. x is a vector with the input values.
double Perceptron::run(std::vector<double> x){
	x.push_back(bias);
	double sum = inner_product(x.begin(),x.end(),weights.begin(),(double)0.0);
	return sigmoid(sum);
}

// Challenge: Finish the following functions:

void Perceptron::set_weights(std::vector<double> w_init){
	// Verifies that this is same size as inputs + 1 (activation fcn)
	if (weights.size() != w_init.size()) {
		std::cout << "Incorrect w_init input size" << std::endl;
	}
	else {
		weights = w_init;
	}
	
}

double Perceptron::sigmoid(double x){
	// Return the output of the sigmoid function applied to x
	return 1 / (1 + exp(-x));
}

// Return a new MultiLayerPerceptron object with the specified parameters.
MultiLayerPerceptron::MultiLayerPerceptron(std::vector<size_t> layers, double bias, double eta) {
    this->layers = layers;
    this->bias = bias;
    this->eta = eta;

	// Nested loops to create neurons layer by layer
	for (size_t i = 0; i < layers.size(); i++) { // Iterates through i layers
		
		values.push_back(std::vector<double>(layers[i], 0.0)); // Vector of values
		network.push_back(std::vector<Perceptron>());// Vector of neurons (empty for now)
		
		if (i>0) {// Does not iterate through input layer because it has no neurons
			for (size_t j = 0; j < layers[i]; j++) { // Iterates through the neurons in given layer
				network[i].push_back(Perceptron(layers[i-1], bias));
			}
		}
	}
}
