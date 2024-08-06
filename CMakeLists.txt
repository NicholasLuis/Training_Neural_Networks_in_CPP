cmake_minimum_required(VERSION 3.23)
project(TrainingNeuralNetworksinCPP)
set(CMAKE_CXX_STANDARD 20)

add_executable(${CMAKE_PROJECT_NAME}
	#src/FollowAlong/MLP.cpp
	#src/FollowAlong/MLP.h
src/NeuralNetworks.cpp # Contains main function
src/NeuralNetworks/GPU_MLP.cpp # Re-making the file to be GPU-parallelized
src/NeuralNetworks/GPU_MLP.h # Re-making the file to be GPU-parallelized
src/NeuralNetworks/Perceptron.cpp # Seperated the perceptron class from the network class
src/NeuralNetworks/Perceptron.h # Seperated the perceptron class from the network class
src/log/NetworkShape.txt
src/log/NetworkWeights.txt
src/log/log.cpp
src/log/log.h
)