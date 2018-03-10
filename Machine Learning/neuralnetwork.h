#pragma once
#include "Neuron.h"
#include <vector>

class Layer
{
private:
	std::vector<Neuron> *neurons;
	Layer *next = nullptr;
public:
	Layer(unsigned number_of_neurons);

	void push();
	void fill(std::vector<double> *data);
	void connect(Layer *to);

	~Layer();
};

class Neural_Network
{
private:
	std::vector<Layer> *hiden_layers;
	Layer *input_layer, *output_layer;
public:
	Neural_Network(unsigned number_of_inputs, unsigned number_of_outputs);

	std::vector<double>* start(std::vector<double> *input);


	~Neural_Network();
};

