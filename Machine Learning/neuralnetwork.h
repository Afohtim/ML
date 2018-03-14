#pragma once
#include "Neuron.h"
#include <vector>

struct Layer
{
	std::vector<Neuron> *neurons = nullptr;
	Layer(unsigned number_of_neurons);

	void push();
	void fill(std::vector<double> *data);
	void connect(Layer *to);
	std::vector<double>* get_data();

	~Layer();
};

class Neural_Network
{
private:
	std::vector<Layer> *hiden_layers = nullptr;
	Layer *input_layer = nullptr, *output_layer = nullptr;
public:
	Neural_Network(unsigned number_of_inputs, unsigned number_of_outputs);

	std::vector<double>* start(std::vector<double> *input);
	void setup_hiden_layers(std::vector<int> *config);

	~Neural_Network();
};

