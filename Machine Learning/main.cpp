#include "neuralnetwork.h"
#include <iostream>
#include<string>

void learn(unsigned count, Neural_Network &net)
{
	std::vector<double> *a = new std::vector<double>(10, 0);
	for (unsigned i = 0; i < count; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			(*a)[j] = double(rand() % 10000) / 40000;
		}
		std::vector<double> *res = net.learn(a, a);
		delete res;
	}
	delete a;

}

int main()
{
	unsigned inputs = 10, outputs = 10;
	std::vector<int> config = { 10 };
	Neural_Network net(inputs, outputs, &config);
	std::vector<double> *data = new std::vector<double>(inputs, 0), *result = new std::vector<double>(outputs, 0);
	
	while (true)
	{
		std::string command;
		int num;
		std::cin >> command >> num;
		if (command == "learn")
		{
			learn(num, net);
		}
		else
		{
			for (int j = 0; j < 10; ++j)
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