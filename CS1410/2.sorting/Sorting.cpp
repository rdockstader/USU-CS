#include "Sorting.hpp"
#include <random>
#include <iostream>
#include <string>



std::vector<int> generateList(int size)
{
	std::cout << "Generating list of " << size << " integers." << std::endl;
	std::vector<int> c;
	c.resize(size);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, size);


	for (auto&& e : c)
	{
		e = dist(gen);
	}
	return c;
}

void runSort(int size,std::function<void(std::vector<int>)> function, std::ofstream& fout)
{
	std::cout << "Running sort..." << std::endl;
	timer timer;
	std::vector<int> c = generateList(size);
	timer.startTimer();
	function(c);
	timer.endTimer();
	fout << size << "\t" << timer.duration() << std::endl;
}

void testFunction(std::string fName, std::function<void(std::vector<int>)> function, std::ofstream& fout)
{
	fout << "Testing Function: " << fName << std::endl;
	fout << "size" << "\tDuration" << std::endl;
	for (auto i = 10000; i <= 100000; i += 10000)
	{
		runSort(i, function, fout);
	}
}









