#include "Randomizer.hpp"

Randomizer::Randomizer(int maxNum)
{
	maxNumber = maxNum;
}

int Randomizer::generateRandomInt()
{
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, maxNumber);

	return dist(gen);
}
