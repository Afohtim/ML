#pragma once
#include<vector>
#include<cmath>

#define e 2.71828

class Neuron;

struct Edge
{
	double weight;
	Neuron *to = nullptr;
};

class Neuron
{
public:
	Neuron();

	double get_data(double input);
	void push();
	void set_data(double input);
	void add_value(double input);

	~Neuron();

private:
	double data = 0;
	std::vector<Edge> out_edges;
};