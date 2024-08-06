#include "GPU_MLP.h"


void MultilayerPerceptron::operate() {
	// Makes a copy of a the pointers and passes those to the GPU functions and passes those to the 
	// GPU-parallelized functions
}

__global__ void MultilayerPerceptron::run(std::vector<std::vector<Perceptron*>>* network) {
	// Input: A layer of perceptrons:
	// Output: None (Updates values stored in the pointer)
	// This function will perform the entire operation of a neural network by working through the 
	// network and performing the necessary calculations layer-by-layer
}

__global__ void MultilayerPerceptron::backProp(std::vector<std::vector<Perceptron*>>* network);
