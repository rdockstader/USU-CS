#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include<random>


class Randomizer
{
public:
	Randomizer(int);
	int generateRandomInt();
private:
	std::random_device rd;
	int maxNumber;

};


#endif // !RANDOMIZER_HPP

