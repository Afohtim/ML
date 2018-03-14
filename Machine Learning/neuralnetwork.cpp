#include "neuralnetwork.h"


Layer::Layer(unsigned number_of_neurons)
{
	this->neurons = new std::vector<Neuron>(number_of_neurons);
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

std::vector<double>* Layer::get_data()
{
	std::vector<double> *ans;
	for (auto neuron = this->neurons->begin(); neuron != this->neurons->end(); ++neuron)
	{
		ans->push_back(neuron->get_data());
	}
	return ans;
}

void Layer::connect(Layer *with)
{
	for (auto from = this->neurons->begin(); from != this->neurons->end(); ++from)
	{
		for (auto to = with->neurons->begin(); to != with->neurons->end(); ++to)
		{
			from->create_edge(&*to);//???
		}
	}
}

Neural_Network::Neural_Network(unsigned number_of_inputs, unsigned number_of_outputs)
{
	this->input_layer = new Layer(number_of_inputs);
	this->output_layer = new Layer(number_of_outputs);
}

Neural_Network::~Neural_Network()
{
	//TODO
}

void Neural_Network::setup_hiden_layers(std::vector<int> *config)
{
	this->hiden_layers = new std::vector<Layer>(config->size());
	for (unsigned iter = 0; iter < config->size(); iter++)
	{
		(this->hiden_layers->begin() + iter)->neurons->resize(*(config->begin() + iter));
	}
}


std::vector<double>* Neural_Network::start(std::vector<double> *input)
{
	this->input_layer->fill(input);
	input_layer->push();
	for (auto layer = this->hiden_layers->begin; layer != this->hiden_layers->end(); layer++)
	{
		layer->push();
	}
	return this->output_layer->get_data();
}