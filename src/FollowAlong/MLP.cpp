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

void MultiLayerPerceptron::set_weights(const std::vector<std::vector<std::vector<double> > > w_init) {
    // w_init is a vector of vectors of vectors of doubles.
	// Outer-most vector corresponds to the layer, Next-inner vector is the neurons, Inner-most are the weights
	
	/*
	// Initializing iterators
	std::vector< std::vector< std::vector<double> > >::const_iterator layer_it; // Layer iterator
	std::vector< std::vector<double> >::const_iterator neuron_it; // Nueron iterator
	std::vector<double>::const_iterator weight_it; // Weight iterator

	for (layer_it = w_init.begin(); layer_it != w_init.end(); layer_it++) { // Iterates through the layers
		for (neuron_it = layer_it->begin(); neuron_it != layer_it->end(); neuron_it++) { // Iterates through the neurons
			for (weight_it = neuron_it->begin(); weight_it != neuron_it->end(); weight_it++) { // Iterates through the weights and assigns them

			}
		}
	}
	*/
}

void MultiLayerPerceptron::print_weights() {
    std::cout << std::endl;
    for (size_t i = 1; i < network.size(); i++){
        for (size_t j = 0; j < layers[i]; j++) {
            std::cout << "Layer " << i+1 << " Neuron " << j << ": ";
            for (auto &it: network[i][j].weights)
                std::cout << it << "   ";
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

std::vector<double> MultiLayerPerceptron::run(std::vector<double> x) {
    // Run an input forward through the neural network.
    // x is a vector with the input values.
    return values.back();
}
