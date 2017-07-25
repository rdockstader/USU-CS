#include <iostream>
#include "RollAndTurn.hpp"
#include "Display.hpp"

int playerTurn(int playerPoints)
{
	auto currentPoints = playerPoints;
	auto turnOver = false;
	while (turnOver == false)
	{
		std::cout << "It is now your turn, Would you like to Hold(h) or Roll(r)?" << std::endl;
		char playerChoice;
		std::cin >> playerChoice;
		if (playerChoice == 'r')
		{
			int roll = die();
			if (roll == 1)
			{
				std::cout << "You have rolled a 1, and your turn is now over." << std::endl;
				turnOver = true;
				currentPoints = playerPoints;
			}
			else
			{
				currentPoints = currentPoints + roll;
				displayDie(roll);
				std::cout << "You have " << currentPoints << " points this turn." << std::endl;
			}
		}
		else if (playerChoice == 'h')
		{
			std::cout << "You have chosen to hold." << std::endl;
			turnOver = true;
		}
	}	
	return(currentPoints);
}

int devilTurn(int devilPoints)
{
	std::cout << "It is now the Devils turn..." << std::endl;
	auto currentPoints = devilPoints;
	while (currentPoints < devilPoints + 20)
	{
		int roll = die();
		if (roll == 1)
		{
			std::cout << "The Devil has rolled a 1, and lost all his points." << std::endl;
			currentPoints = devilPoints;
			system("PAUSE");
			break;
		}
		else
		{
			currentPoints = currentPoints + roll;
			displayDie(roll);
			std::cout << "The Devil has " << currentPoints << " points this turn." << std::endl;
		}
	}
	if (currentPoints > devilPoints + 20)
	{
		std::cout << "The Devil has chosen to hold" << std::endl;
		system("PAUSE");
	}
	return(currentPoints);
}
