// NeuralNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.//

// Last updated: Ch4, L8

#include "MLP.h"

int main(){
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

    */

    // Creating the neural network
    std::vector<size_t> layerInfo = { 2, 2, 1 }; // Shape of the network (2 inputs, 2 neurons, then 1 neuron)
    MultiLayerPerceptron mlp(layerInfo, 1.0, 0.5);
    mlp.set_weights({ {{20,20,-10},{-10,-10,15}}    ,   {{10,10,-15}} });
    //                ^OR (layer1) ^NAND (layer1)     ^AND (layer2)

    // Running the neural network
    std::cout << "XOR Gate" << std::endl;
    std::cout << mlp.run({ 0,0 })[0] << std::endl;
    std::cout << mlp.run({ 0,1 })[0] << std::endl;
    std::cout << mlp.run({ 1,0 })[0] << std::endl;
    std::cout << mlp.run({ 1,1 })[0] << std::endl;
    return 0;
}
