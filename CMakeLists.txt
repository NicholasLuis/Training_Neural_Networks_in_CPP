cmake_minimum_required(VERSION 3.23)
project(TrainingNeuralNetworksinCPP)
set(CMAKE_CXX_STANDARD 20)

add_executable(${CMAKE_PROJECT_NAME}
	src/FollowAlong/MLP.cpp
	src/FollowAlong/MLP.h
	src/FollowAlong/NeuralNetworks.cpp # Contains main function
)