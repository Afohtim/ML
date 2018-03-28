#include "neuralnetwork.h"
#include <iostream>
#include<string>

void learn(unsigned count, Neural_Network &net)
{
	std::vector<double> a(10, 0);
	for (unsigned i = 0; i < count; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			a[j] = 1;
			net.learn(&a, &a);
			a[j] = 0;
		}
	}
}

int main()
{
	unsigned inputs = 10, outputs = 10;
	std::vector<int> config = { 15, 10, 20 };
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
			if (command != "z")
				(*data)[num] = 1;
			result = net.start(data);
			for (auto res : *data)
			{
				std::cout << res << ' ';
			}
			std::cout << std::endl;
			(*data)[num] = 0;
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