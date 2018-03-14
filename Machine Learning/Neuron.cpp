#include "Neuron.h"

double sigma(double x)
{
	return (1.0 / (1 + pow(e, -x)));
}


Edge::Edge(Neuron *end)
{
	*weight = rand();
	to = end;

}

Neuron::Neuron()
{
	data = 0;
}

Neuron::~Neuron()
{
	//TODO
}

void Neuron::set_data(double input)
{
	this->data = input;
}

void Neuron::add_value(double input)
{
	this->data += input;
}

void Neuron::push()
{
	for (std::vector<Edge>::iterator edge = this->out_edges->begin(); edge != this->out_edges->end(); ++edge)
	{
		edge->to->add_value((edge->weight) * this->get_data);
	}
}

void Neuron::normalize()
{
	this->data = sigma(data);
}

double Neuron::get_data()
{
	return this->data;
}

void Neuron::create_edge(Neuron *to)
{
	this->out_edges->push_back(Edge(to));
}