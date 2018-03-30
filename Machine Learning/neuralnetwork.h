#pragma once
#include "Neuron.h"
#include <vector>


struct Layer
{
	std::vector<Neuron> *neurons = new std::vector<Neuron>;

	void push();
	void fill(std::vector<double> *data);
	void connect(Layer *to);
	std::vector<double>* get_data();
	void activate_neurons();
	void normalize();
	std::vector<Neuron>::iterator begin();
	std::vector<Neuron>::iterator end();

	~Layer();
};

class Neural_Network
{
private:
	std::vector<Layer> *hiden_layers = new std::vector<Layer>;
	Layer *input_layer = nullptr, *output_layer = nullptr;
	void setup_hiden_layers(std::vector<int> *config);
	void clear();
public:
	Neural_Network(unsigned number_of_inputs, unsigned number_of_outputs, std::vector<int> *config);

	std::vector<double>* learn(std::vector<double> *input, std::vector<double> *wanted);

	std::vector<double>* start(std::vector<double> *input);

	~Neural_Network();
};

