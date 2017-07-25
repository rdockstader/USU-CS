#include <iostream>
#include <random>
#include <string>
#include "RollAndTurn.hpp"
#include "Display.hpp"

int die(void)
{
	static std::random_device rd;
	static std::mt19937 engine(rd());
	std::uniform_int_distribution<> die(1, 6);
	return die(engine);
}

