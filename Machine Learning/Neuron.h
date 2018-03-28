#pragma once
#include<vector>
#include<cmath>

#define e 2.71828
#define ALPHA 10

class Neuron;

struct Edge
{
	Edge(Neuron *end);
	double weight;
	Neuron *to = nullptr;
	double gradient = 0;
};

class Neuron
{
private:
	double data = 0;
	std::vector<Edge> *out_edges = new std::vector<Edge>;
	double derivative = 0;
public:
	Neuron();

	double get_der();
	void set_der(double der);
	void find_der();
	double get_data();
	void push();
	void set_data(double input);
	void add_value(double input);
	void normalize();
	void create_edge(Neuron *to);

	~Neuron();
};