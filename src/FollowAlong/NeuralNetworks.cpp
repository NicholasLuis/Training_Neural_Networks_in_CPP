// NeuralNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.//

// Last updated: Ch5

#include "MLP.h"

int indexOfLargestNumber(std::vector<double> input)
{
    int index = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] > input[index]) {
            index = (int)i;
        }
    }
    return index;
}

int main()
{
    std::cout << "Training Neural Network to recognize the number on a 7 segment display" << std::endl;
    std::cout << "\n\n--------7 Segment Example: Sigmoid---------------\n\n";

    // One-hot encoding output
    MultiLayerPerceptron mlp  = MultiLayerPerceptron({ 7,7,10 }); 
    MultiLayerPerceptron mlp2 = MultiLayerPerceptron({ 7,7,10 });


    // Training
    double MSE, MSE2;
    for (int i = 0; i < 1000; i++) {
        MSE = MSE2 = 0.0;
        MSE += mlp.bp({ 1,1,1,1,1,1,0 }, { 1,0,0,0,0,0,0,0,0,0 }); // 0 Pattern
        MSE += mlp.bp({ 0,1,1,0,0,0,0 }, { 0,1,0,0,0,0,0,0,0,0 }); // 1 Pattern
        MSE += mlp.bp({ 1,1,0,1,1,0,1 }, { 0,0,1,0,0,0,0,0,0,0 }); // 2 Pattern
        MSE += mlp.bp({ 1,1,1,1,0,0,1 }, { 0,0,0,1,0,0,0,0,0,0 }); // 3 Pattern
        MSE += mlp.bp({ 0,1,1,0,0,1,1 }, { 0,0,0,0,1,0,0,0,0,0 }); // 4 Pattern
        MSE += mlp.bp({ 1,0,1,1,0,1,1 }, { 0,0,0,0,0,1,0,0,0,0 }); // 5 Pattern
        MSE += mlp.bp({ 1,0,1,1,1,1,1 }, { 0,0,0,0,0,0,1,0,0,0 }); // 6 Pattern
        MSE += mlp.bp({ 1,1,1,0,0,0,0 }, { 0,0,0,0,0,0,0,1,0,0 }); // 7 Pattern
        MSE += mlp.bp({ 1,1,1,1,1,1,1 }, { 0,0,0,0,0,0,0,0,1,0 }); // 8 Pattern
        MSE += mlp.bp({ 1,1,1,1,0,1,1 }, { 0,0,0,0,0,0,0,0,0,1 }); // 9 Pattern

        MSE = MSE / 10; // Mean MSE of all 10
        if (i % 100 == 0)
            std::cout << "MSE1 = " << MSE << std::endl;
    }
    

    return 0;
}
