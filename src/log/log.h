#pragma once

#include <fstream>
#include <mutex>
#include <iostream>
#include <vector>

class logger
{
	// This logs string data into files. Note: must create new a new logger object for every file

private:
	std::mutex* mutex;
	std::ofstream outfile;
	std::string fileName;
	bool usingMutex;
	std::vector<std::vector<int>> nnShape = { {-1} }; // Dimensions of the nueral network (number of inputs, layers, nuerons in each layer)
	std::vector<std::vector<std::vector<double>>> weights = { { {-1} } }; // Weight vector of each neuron on the network
public:
	logger(const std::string inputFileName);
	logger(const std::string inputFileName, std::mutex* inputMutex);
	~logger(); // Destructor
	void log(const std::vector<std::vector<double>> toLog);
	std::vector<std::vector<double>> getWeights();
	std::vector<std::vector<double>> getWeights(std::string inputFileName);
	std::vector<std::vector<int>> getShape();
	std::vector<std::vector<int>> getShape(std::string inputFileName);

};