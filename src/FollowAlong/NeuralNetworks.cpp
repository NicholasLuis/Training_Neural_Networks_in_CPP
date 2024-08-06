// NeuralNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.//

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



    std::cout << "\n\n--------7 Segment Example----------------\n\n";
    std::cout << "Training Neural Network to recognize the number on a 7 segment display" << std::endl;

    // One-hot encoding output
    MultiLayerPerceptron mlp = MultiLayerPerceptron({ 7,7,10 }); 

    // Training
    double MSE;
    for (int i = 0; i < 1000; i++) {
        MSE = 0.0;
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
            std::cout << "MSE = " << MSE << std::endl;
    }


    // Validation + Testing
    std::cout << "0: " << indexOfLargestNumber(mlp.run({ 1,1,1,1,1,1,0 })) << std::endl;
    std::cout << "1: " << indexOfLargestNumber(mlp.run({ 0,1,1,0,0,0,0 })) << std::endl;
    std::cout << "2: " << indexOfLargestNumber(mlp.run({ 1,1,0,1,1,0,1 })) << std::endl;
    std::cout << "3: " << indexOfLargestNumber(mlp.run({ 1,1,1,1,0,0,1 })) << std::endl;
    std::cout << "4: " << indexOfLargestNumber(mlp.run({ 0,1,1,0,0,1,1 })) << std::endl;
    std::cout << "5: " << indexOfLargestNumber(mlp.run({ 1,0,1,1,0,1,1 })) << std::endl;
    std::cout << "6: " << indexOfLargestNumber(mlp.run({ 1,0,1,1,1,1,1 })) << std::endl;
    std::cout << "7: " << indexOfLargestNumber(mlp.run({ 1,1,1,0,0,0,0 })) << std::endl;
    std::cout << "8: " << indexOfLargestNumber(mlp.run({ 1,1,1,1,1,1,1 })) << std::endl;
    std::cout << "9: " << indexOfLargestNumber(mlp.run({ 1,1,1,1,0,1,1 })) << std::endl;
    

    return 0;
}
