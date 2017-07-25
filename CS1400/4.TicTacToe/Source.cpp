#include <iostream>
#include "TicTacToe.hpp"


void main(void)
{
	TicTacToe game;
	auto playAgain = true;
	TicTac anyWinnerYet = TicTac::NO_WINNER_YET;
	TicTac playerTurn;
	while (playAgain == true)
	{

		if (anyWinnerYet == TicTac::PLAYER_O_WIN)
		{
			std::cout << "Player O won the last game, and will go first!" << std::endl;
			playerTurn = TicTac::PLAYER_O_TURN;
			anyWinnerYet = TicTac::NO_WINNER_YET;
		}
		else if (anyWinnerYet == TicTac::PLAYER_X_WIN)
		{
			std::cout << "Player X won the last game, and will go first!" << std::endl;
			playerTurn = TicTac::PLAYER_X_TURN;
			anyWinnerYet = TicTac::NO_WINNER_YET;
		}
		else
		{
			playerTurn = game.beginGame();
			anyWinnerYet = TicTac::NO_WINNER_YET;
		}
		





		while (anyWinnerYet == TicTac::NO_WINNER_YET)
		{
			while (playerTurn == TicTac::PLAYER_X_TURN)
			{
				std::cout << "It is now Player X's turn!" << std::endl;
				anyWinnerYet = game.takeTurn(TicTac::PLAYER_X_TURN);
				playerTurn = TicTac::PLAYER_O_TURN;
			}

			if (anyWinnerYet != TicTac::NO_WINNER_YET)
			{

				break;
			}

			while (playerTurn == TicTac::PLAYER_O_TURN)
			{
				std::cout << "It is now Player O's turn!" << std::endl;
				anyWinnerYet = game.takeTurn(TicTac::PLAYER_O_TURN);
				playerTurn = TicTac::PLAYER_X_TURN;
			}
			
		}
		game.winnaWinnaChickenDinna(anyWinnerYet);
		playAgain = game.playAgainFunction();
	}

	std::cout << "You Have Chosen to end the game." << std::endl;
	std::cout << "Thanks for Playing!" << std::endl;
	system("PAUSE");

}
