#include "MLP.h"

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
		std::cerr << "Incorrect w_init input size";
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
MultiLayerPerceptron::MultiLayerPerceptron(std::vector<size_t> layersinfo, double bias, double eta) {
    this->layers = layersinfo;
    this->bias = bias;
    this->eta = eta;

	// Nested loops to create neurons layer by layer
	for (size_t i = 0; i < layers.size(); i++) { // Iterates through i layers
		
		values.push_back(std::vector<double>(layers[i], 0.0)); // Vector of values
        d.push_back(std::vector<double>(layers[i], 0.0)); // Vector of error terms
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

	for (size_t i = 0; i < w_init.size(); i++) { // Iterates through the layers of a given network
		for (size_t j = 0; j < w_init[i].size(); j++) { // Iterates through the neurons of a given layer
			network[i+1][j].set_weights(w_init[i][j]); // i+1 because we skip over input layer
		}
	}
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
	values[0] = x;
    for (size_t i = 1; i < network.size(); i++) {
        for (size_t j = 0; j < layers[i]; j++) {
			values[i][j] = network[i][j].run(values[i-1]);
        }
    }

    return values.back();
}

// Run a single (x,y) pair with the backpropagation algorithm.
double MultiLayerPerceptron::bp(std::vector<double> x, std::vector<double> y) {
    // Resetting values
    MSE = 0.0;
    outputWeightedError = 0.0; // SUM(w_k1 * d_k) 

    // Backpropagation Step by Step:
    // STEP 1: Feed a sample to the network
    std::vector<double> results = run(x);
    if (results.size() != y.size()) { // Makes sure the output size is as expected
        std::cerr << "The size of the results vector is not expected";
        return -1;
    }
    // STEP 2: Calculate the MSE
    for (size_t i = 0; i < y.size(); i++) { // Iterates through every output value
        MSE += pow(y[i] - results[i] , 2.0);
    }
    MSE /= y.size();

    // STEP 3: Calculate the output error terms (of each output neuron)
    for (size_t i = 0; i < results.size(); i++) { // Iterates through every output value
        d.back()[i] = results[i] * (1.0 - results[i]) * (y[i] - results[i]);
    }

    // STEP 4: Calculate the error term of each neuron on each layer    
    for (size_t i = network.size() - 2; i > 0; i--) { // Iterates through layers (backwards)
        for (size_t h = 0; h < network[i].size(); h++) { // Iterates through neurons in given layer
            outputWeightedError = 0.0;
            for (size_t k = 0; k < layers[i + 1]; k++) {// Iterates through the input weights connected to the output of given neuron
                outputWeightedError += network[i+1][k].weights[h] * (d[i+1][k]);
            }
            d[i][h] = values[i][h] * (1.0 - values[i][h]) * outputWeightedError;
        }
    }
    // STEPS 5 & 6: Calculate the deltas and update the weights
    for (size_t i = 1; i < network.size(); i++) // Iterates through the layers
        for (size_t j = 0; j < layers[i]; j++) // Iterates through the neurons in given layer
            for (size_t k = 0; k < layers[i - 1] + 1; k++) { // Iterates through the weights in given neuron
                if (k == layers[i - 1]) // Because values vector does not contain info on the bias
                    Delta = eta * d[i][j] * bias;
                else
                    Delta = eta * d[i][j] * values[i - 1][k];
                network[i][j].weights[k] += Delta; // Updating weights
            }
    return MSE;
}
