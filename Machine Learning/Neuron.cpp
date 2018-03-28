#include "Neuron.h"

double sigma(double x)
{
	return (1.0 / (1 + pow(e, -x)));
}


Edge::Edge(Neuron *end)
{
	weight = (rand()%10 - 5);
	to = end;

}

Neuron::Neuron()
{
	data = 0;
	bias = double(rand() % 10) / 10;
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
	this->derivative = 0;
	sigma_der = pow(e, -data) / pow(1 + pow(e, -data), 2);
	for (auto edge = this->out_edges->begin(); edge != this->out_edges->end(); ++edge)
	{
		edge->to->add_value((edge->weight) * this->data);
		edge->gradient = 0;
	}
}

void Neuron::normalize()
{
	this->data = sigma(data);
	if (data < EPS) data = 0;
}

void Neuron::activate()
{
	data = sigma(data + bias);
	if (data < EPS) data = 0;
}

double Neuron::get_der()
{
	return derivative;
}

void Neuron::set_der(double der)
{
	this->derivative = der;
}

void Neuron::find_der()
{
	for (auto edge = out_edges->begin(); edge != out_edges->end(); ++edge)
	{
		edge->gradient = edge->to->get_der() * this->data * this->sigma_der;
		this->derivative += edge->weight * edge->to->get_der() * this->sigma_der;
		this->bias_der += this->sigma_der * this->data;
	}
	for (auto edge = out_edges->begin(); edge != out_edges->end(); ++edge)
	{
		edge->weight -= ALPHA * edge->gradient;
	}


}

double Neuron::get_data()
{
	return this->data;
}

void Neuron::create_edge(Neuron *to)
{
	this->out_edges->push_back(Edge(to));
}