#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <array>
#include <algorithm>
#include <iostream>
template <std::size_t numInputs, std::size_t numOutputs, std::size_t numHiddenNodes>
class NeuralNetwork{
  private:
    std::array<float, numHiddenNodes> HiddenNodeWeights{};
    std::array<float, numOutputs> OutputWeights{};
  public:
    NeuralNetwork(){

    }
    std::array<float, numOutputs> predict(std::array<float, numInputs> inputs){
      std::array<float, numHiddenNodes> HiddenLayer;
      std::array<float, numHiddenNodes> OutputLayer;

      // calculations

      return OutputLayer;
    }

}; // class NeuralNetwork

#endif // NEURALNETWORK_H
