cmake_minimum_required(VERSION 3.23)
project(TrainingNeuralNetworksinCPP)
set(CMAKE_CXX_STANDARD 20)

add_executable(${CMAKE_PROJECT_NAME}
	#src/FollowAlong/MLP.cpp
	#src/FollowAlong/MLP.h
	src/FollowAlong/NeuralNetworks.cpp # Contains main function
	src/FollowAlong/GPU_MLP.cpp # Re-making the file to be GPU-parallelized
	src/FollowAlong/GPU_MLP.h # Re-making the file to be GPU-parallelized
)