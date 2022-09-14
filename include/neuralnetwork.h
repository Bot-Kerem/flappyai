#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <array>
#include <algorithm>
#include <random>
#include <iostream>

template <std::size_t numInputs, std::size_t numOutputs, std::size_t numHiddenNodes>
class NeuralNetwork{
  private:
    struct _HiddenLayer{
        std::array<float, numHiddenNodes> Biases{};
        std::array<float, numInputs> InputWidths{};
    };

    struct _OutputLayer{
        std::array<float, numOutputs> Biases{};
        std::array<float, numHiddenNodes> HiddenWidths{};
    };

    _HiddenLayer HiddenLayer{};
    _OutputLayer OutputLayer{};

  public:
    NeuralNetwork(){
      // randomize

      // hidden layer
      for(auto& bias: HiddenLayer.Biases){
        bias = random01();
      }
      for(auto& width: HiddenLayer.InputWidths){
        width = random01();
      }

      // output layer
      for(auto& bias: OutputLayer.Biases){
        bias = random01();
      }
      for(auto& width: OutputLayer.HiddenWidths){
        width = random01();
      }
    }

    std::array<float, numOutputs> predict(std::array<float, numInputs> inputs){
      // calculations
      std::array<float, numHiddenNodes> calcHiddenLayer;
      std::array<float, numOutputs> calcOutputLayer;
      calcHiddenLayer.fill(0);
      calcOutputLayer.fill(0);
      // calculated hidden layer

      for(int i = 0; i < numHiddenNodes; i++){
        for(auto& input: inputs){
          calcHiddenLayer[i] += input * HiddenLayer.InputWidths[i];
        }
        calcHiddenLayer[i] += HiddenLayer.Biases[i];
      }

      for(int i = 0; i < numOutputs; i++){
        for(auto& hiddenNode: calcHiddenLayer){
          calcOutputLayer[i] += hiddenNode * OutputLayer.HiddenWidths[i];
        }
        calcOutputLayer[i] += OutputLayer.Biases[i];
      }

      return calcOutputLayer;
    }

    float random_11(){
      return ((float)rand() / RAND_MAX * 2) -1;
    }

    float random01(){
      return (float)rand() / RAND_MAX;
    }

}; // class NeuralNetwork

#endif // NEURALNETWORK_H
