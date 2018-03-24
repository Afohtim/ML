#include "neuralnetwork.h"
#include <iostream>

int main()
{
	unsigned inputs = 3, outputs = 4;
	Neural_Network net(inputs, outputs);
	std::vector<int> config = { 2, 2, 3 };
	net.setup_hiden_layers(&config);
	std::vector<double> *data = new std::vector<double>(inputs, 0), *result = new std::vector<double>(outputs, 0);
	result = net.start(data);
	for (auto res : *result)
	{
		std::cout << res << ' ';
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}