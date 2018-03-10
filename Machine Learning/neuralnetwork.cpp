#include "neuralnetwork.h"


Layer::Layer(unsigned number_of_neurons)
{
	//TODO
}

Layer::~Layer()
{
	//TODO
}

void Layer::push()
{
	for (std::vector<Neuron>::iterator neuron = this->neurons->begin(); neuron != this->neurons->end(); ++neuron)
	{
		neuron->push();
	}
}

void Layer::fill(std::vector<double> *data)
{
	unsigned length = this->neurons->end() - this->neurons->begin();
	for (unsigned iter = 0; iter < length; ++iter)
	{
		(this->neurons->begin() + iter)->set_data(*(data->begin() + iter));
	}
}

void Layer::connect(Layer *with)
{
	//TODO
}

Neural_Network::Neural_Network(unsigned number_of_inputs, unsigned number_of_outputs)
{
	//TODO
}

Neural_Network::~Neural_Network()
{
	//TODO
}

std::vector<double>* Neural_Network::start(std::vector<double> *input)
{
	this->input_layer->fill(input);
	input_layer->push();
	for (auto layer = this->hiden_layers->begin; layer != this->hiden_layers->end(); layer++)
	{
		layer->push();
	}
}