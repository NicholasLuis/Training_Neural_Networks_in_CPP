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
    srand(time(NULL));
    rand();

    /*

    std::cout << "\n\n--------Logic Gate Example----------------\n\n";
    Perceptron p(2);

    p.set_weights({10,10,-15}); //AND
    std::cout << "And Gate" << std::endl;
    std::cout << p.run({0,0}) << std::endl;
    std::cout << p.run({0,1}) << std::endl;
    std::cout << p.run({1,0}) << std::endl;
    std::cout << p.run({1,1}) << std::endl;

    p.set_weights({20,20,-10}); //OR
    std::cout << "OR Gate" << std::endl;
    std::cout << p.run({0,0}) << std::endl;
    std::cout << p.run({0,1}) << std::endl;
    std::cout << p.run({1,0}) << std::endl;
    std::cout << p.run({1,1}) << std::endl;

    p.set_weights({-20,-20,10}); //NOR
    std::cout << "NOR Gate" << std::endl;
    std::cout << p.run({0,0}) << std::endl;
    std::cout << p.run({0,1}) << std::endl;
    std::cout << p.run({1,0}) << std::endl;
    std::cout << p.run({1,1}) << std::endl;

    p.set_weights({-10,-10,15}); //NAND
    std::cout << "NAND Gate" << std::endl;
    std::cout << p.run({0,0}) << std::endl;
    std::cout << p.run({0,1}) << std::endl;
    std::cout << p.run({1,0}) << std::endl;
    std::cout << p.run({1,1}) << std::endl;

    std::cout << "\n\n--------Hard Coded XOR Example----------------\n\n";
    // Creating the neural network
    std::vector<size_t> layerInfo = { 2, 2, 1 }; // Shape of the network (2 inputs, 2 neurons, then 1 neuron)
    MultiLayerPerceptron mlp(layerInfo, 1.0, 0.5);
    mlp.set_weights({ {{20,20,-10},{-10,-10,15}}    ,   {{10,10,-15}} });
    //                ^OR (layer1) ^NAND (layer1)     ^AND (layer2)
    std::cout << mlp.run({ 0,0 })[0] << std::endl;
    std::cout << mlp.run({ 0,1 })[0] << std::endl;
    std::cout << mlp.run({ 1,0 })[0] << std::endl;
    std::cout << mlp.run({ 1,1 })[0] << std::endl;
    return 0;
    
    std::cout << "\n\n--------Trained XOR Example----------------\n\n";
    MultiLayerPerceptron mlp = MultiLayerPerceptron({ 2,2,1 });
    std::cout << "Training Neural Network as an XOR Gate..." << std::endl;

    double MSE;
    for (int i = 0; i < 3000; i++) {
        MSE = 0.0;
        MSE += mlp.bp({ 0,0 }, { 0 });
        MSE += mlp.bp({ 0,1 }, { 1 });
        MSE += mlp.bp({ 1,0 }, { 1 });
        MSE += mlp.bp({ 1,1 }, { 0 });
        MSE = MSE / 4.0;
        if (i % 100 == 0)
            std::cout << "MSE = " << MSE << std::endl;
    }

    std::cout << "\n\nTrained weights (Compare to hardcoded weights):\n\n";
    mlp.print_weights();

    std::cout << "XOR:" << std::endl;
    std::cout << "0 0 = " << mlp.run({ 0,0 })[0] << std::endl;
    std::cout << "0 1 = " << mlp.run({ 0,1 })[0] << std::endl;
    std::cout << "1 0 = " << mlp.run({ 1,0 })[0] << std::endl;
    std::cout << "1 1 = " << mlp.run({ 1,1 })[0] << std::endl;
     */

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
