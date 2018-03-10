#include "Neuron.h"

double sigma(double x)
{
	return (1.0 / (1 + pow(e, -x)));
}

void push_edge(Neuron *from, Edge *edge)
{
	edge->to->add_value((edge->weight) * from->get_data);
}

Neuron::Neuron()
{
	//TODO
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