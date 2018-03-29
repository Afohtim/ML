#include "neuralnetwork.h"




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
	std::vector<double> *ans = new std::vector<double>;
	for (auto neuron = this->neurons->begin(); neuron != this->neurons->end(); ++neuron)
	{
		ans->push_back(neuron->get_data());
	}
	return ans;
}



void Layer::activate_neurons()
{
	for (auto neuron = this->begin(); neuron != this->end(); ++neuron)
	{
		neuron->activate();
	}
}

void Layer::normalize()
{
	for (auto neuron = this->begin(); neuron != this->end(); ++neuron)
	{
		neuron->normalize();
	}
}

std::vector<Neuron>::iterator Layer::begin()
{
	return this->neurons->begin();
}

std::vector<Neuron>::iterator Layer::end()
{
	return this->neurons->end();
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

Neural_Network::Neural_Network(unsigned number_of_inputs, unsigned number_of_outputs, std::vector<int> *config)
{
	this->input_layer = new Layer;
	input_layer->neurons->resize(number_of_inputs);
	this->output_layer = new Layer;
	output_layer->neurons->resize(number_of_outputs);
	this->setup_hiden_layers(config);
	input_layer->connect(&this->hiden_layers->front());
	this->hiden_layers->back().connect(output_layer);


}

std::vector<double>* Neural_Network::learn(std::vector<double>* input, std::vector<double>* wanted)
{
	std::vector<double>* res = this->start(input);
	for (auto neuron = this->output_layer->neurons->begin(); neuron != this->output_layer->neurons->end(); ++neuron)
	{
		int i = neuron - output_layer->neurons->begin();
		neuron->set_der(neuron->get_data() - *(wanted->begin() + i));
	}
	for (auto layer = this->hiden_layers->end() - 1; ; --layer)
	{
		for (auto neuron = layer->neurons->begin(); neuron != layer->neurons->end(); ++neuron)
		{
			neuron->find_der();
		}
		if (layer == this->hiden_layers->begin())
		{
			break;
		}
	}
	for (auto neuron = this->input_layer->neurons->begin(); neuron != this->input_layer->neurons->end(); ++neuron)
	{
		neuron->find_der();
	}
	return res;
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
	for (auto layer = hiden_layers->begin(); layer != (hiden_layers->end() - 1); ++layer)
	{
		layer->connect(&*(layer + 1));
	}
}

void Neural_Network::clear()
{
	std::vector<double>* zeroes = new std::vector<double>;
	for (auto layer = hiden_layers->begin(); layer != hiden_layers->end(); ++layer)
	{
		zeroes->resize(layer->neurons->size());
		layer->fill(zeroes);
	}
	zeroes->resize(output_layer->neurons->size());
	output_layer->fill(zeroes);
	zeroes->clear();
	delete zeroes;
}


std::vector<double>* Neural_Network::start(std::vector<double> *input)
{
	this->clear();
	this->input_layer->fill(input);
	input_layer->push();
	for (std::vector<Layer>::iterator layer = this->hiden_layers->begin(); layer != this->hiden_layers->end(); layer++)
	{
		layer->activate_neurons();
		layer->push();
	}
	this->output_layer->activate_neurons();
	return this->output_layer->get_data();
}