#include "neuralnetwork.h"
#include <iostream>
#include <string>
#include <ctime>

void learn(double count, Neural_Network &net, unsigned inputs)
{
	std::vector<double> *a = new std::vector<double>(inputs, 0);
	if (count < 0)
	{
		clock_t time = clock();
		while((clock() - time) / (CLOCKS_PER_SEC * 60) < -count)
		{
			for (int j = 0; j < a->size(); ++j)
			{
				(*a)[j] = double(rand() % 10000) / 40000;
			}
			std::vector<double> *res = net.learn(a, a);
			delete res;
		}
	}
	else
	{
		for (unsigned i = 0; i < count; ++i)
		{
			for (int j = 0; j < a->size(); ++j)
			{
				(*a)[j] = double(rand() % 10000) / 40000;
			}
			std::vector<double> *res = net.learn(a, a);
			delete res;
		}
	}
	delete a;
}

int main()
{
	unsigned inputs = 2, outputs = 2;
	std::vector<int> config = { 10 };
	Neural_Network net(inputs, outputs, &config);
	std::vector<double> *data = new std::vector<double>(inputs, 0), *result = new std::vector<double>(outputs, 0);
	
	while (true)
	{
		std::string command;
		double num;
		std::cin >> command >> num;
		if (command == "learn")
		{
			learn(num, net, inputs);
		}
		else
		{
			for (int j = 0; j < data->size(); ++j)
			{
				(*data)[j] = double(rand() % 10) / 40;
			}
			result = net.start(data);
			
			for (auto res : *data)
			{
				std::cout << res << ' ';
			}
			std::cout << std::endl;
			for (auto res : *result)
			{
				std::cout << res << ' ';
			}
			std::cout << std::endl;
		}

	}

	
	system("pause");
	return 0;
}