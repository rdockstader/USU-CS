#include "header.hpp"


void main()
{
	std::cout << "Welcome to Ryan's Maze Solver!" << std::endl;

	mazeSolver ms;

	ms.specifyFile();
	ms.readFile();
	std::cout << std::endl;
	std::cout << "Displaying original File..." << std::endl;
	std::cout << std::endl;
	ms.display();
	ms.navigateMaze();
	std::cout << std::endl;
	std::cout << "Displaying solved file.." << std::endl;
	std::cout << std::endl;
	ms.display();

	std::cout << "Finished." << std::endl;
	char dummy;
	std::cin >> dummy;
}
