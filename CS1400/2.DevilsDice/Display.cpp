#include "display.hpp"
#include "RollAndTurn.hpp"
#include <iostream>
#include <string>

namespace
{
	std::string devilString = "The Devil";
	std::string playerString = "Player One";
	std::string currentString;
	auto turnChoice = 'o';
}


void displayScore(int i, int score)
{
	std::cout << '\t';
	if (((score / INCREMENT)*INCREMENT) == ((i / INCREMENT)*INCREMENT))
	{
		std::cout << "-->";
	}
	else
	{
		std::cout << "   ";
	}

	std::cout << i << '\t';
}


void display(int player1Score, int devilScore)
{
	for (auto i = WINNING_SCORE; i >= 0; i -= 5)
	{
		displayScore(i, player1Score); // player1
		displayScore(i, devilScore); // player2
		std::cout << std::endl;
	}
	std::cout << "Player 1: " << player1Score << "\t";
	std::cout << "the Devil: " << devilScore << std::endl;
	




	if (player1Score >= WINNING_SCORE)
	{
		std::cout << "Player 1 wins!" << std::endl;
	}
	else if (devilScore >= WINNING_SCORE)
	{
		std::cout << "The Devil wins!" << std::endl;
	}

}

void displayDie(int dieNumber)
{
	std::cout << "|   "; 
	std::cout << dieNumber << "   |" << std::endl;
	std::cout << "|       |" << std::endl;
}

