#include "display.hpp"
#include "RollAndTurn.hpp"
#include <iostream>


int main(void)
{
	std::cout << "Player will go first." << std::endl;
	auto playerPoints = 0;
	auto devilPoints = 0;
	while (playerPoints < WINNING_SCORE && devilPoints < WINNING_SCORE)
	{
		playerPoints = playerTurn(playerPoints);
		display(playerPoints, devilPoints);
		system("PAUSE");
		devilPoints = devilTurn(devilPoints);
		display(playerPoints, devilPoints);
	}
}
