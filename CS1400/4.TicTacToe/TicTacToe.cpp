#include <iostream>
#include "TicTacToe.hpp"
#include <random>

TicTacToe::TicTacToe()
	: thisTurnPlayer('y')
	, space1('1')
	, space2('2')
	, space3('3')
	, space4('4')
	, space5('5')
	, space6('6')
	, space7('7')
	, space8('8')
	, space9('9')
{}


TicTac TicTacToe::displayBoard(TicTac PlayerTurn, int PlayerChoice)
{


	if(PlayerTurn == TicTac::PLAYER_X_TURN)
	{
	thisTurnPlayer = 'x';
	}
	if (PlayerTurn == TicTac::PLAYER_O_TURN)
	{
		thisTurnPlayer = 'o';
	}
	auto validResponse = false;
	while (validResponse == false)
	{
		if (PlayerChoice == 1 && space1 != 'x' && space1 != 'o')
		{
			space1 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 2 && space2 != 'x' && space2 != 'o')
		{
			space2 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 3 && space3 != 'x' && space3 != 'o')
		{
			space3 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 4 && space4 != 'x' && space4 != 'o')
		{
			space4 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 5 && space5 != 'x' && space5 != 'o')
		{
			space5 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 6 && space6 != 'x' && space6 != 'o')
		{
			space6 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 7 && space7 != 'x' && space7 != 'o')
		{
			space7 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 8 && space8 != 'x' && space8 != 'o')
		{
			space8 = thisTurnPlayer;
			validResponse = true;
		}
		else if (PlayerChoice == 9 && space9 != 'x' && space9 != 'o')
		{
			space9 = thisTurnPlayer;
			validResponse = true;
		}
		else
		{
			std::cout << PlayerChoice << " Has already been filled, please choose another response.";
			std::cin >> PlayerChoice;
			std::cout << std::endl;
		}

	}

	std::cout << "   " << space1 << "  |  " << space2 << "  |  " << space3 << "  " << std::endl;
	std::cout << "---" <<  "-"   << "--+--" <<   "-"  << "--+--" << "   " << std::endl;
	std::cout << "   " << space4 << "  |  " << space5 << "  |  " << space6 << "  " << std::endl;
	std::cout << "---" <<  "-"   << "--+--"  << "-"   << "--+--" << "   " << std::endl;
	std::cout << "   " << space7 << "  |  " << space8 << "  |  " << space9 << "  " << std::endl;

	return TicTacToe::returnWinner(PlayerTurn);
	//return TicTac::NO_WINNER_YET;
	
}


void TicTacToe::winnaWinnaChickenDinna(TicTac AnyWinnerYet)
{
	std::cout << "The Game has ended in a:" << std::endl;
	if (AnyWinnerYet == TicTac::DRAW)
	{
		std::cout << std::endl;
		std::cout << " ____     ____                           " << std::endl;
		std::cout << "|    \\   |    \\   /\\   \\            / " << std::endl;
		std::cout << "|     |  |____/  /__\\   \\    /\\    /  " << std::endl;
		std::cout << "|     |  | \\    /    \\   \\  /  \\  /   " << std::endl;
		std::cout << "|____/   |  \\  /      \\   \\/    \\/    " << std::endl;
		std::cout << std::endl;
		std::cout << "(draw)" << std::endl;
	}
	if (AnyWinnerYet == TicTac::PLAYER_O_WIN)
	{
		std::cout << std::endl;
		std::cout << "    ___   " << "\t" << "               _______          ___       " << std::endl;
		std::cout << "   /   \\ " << "\t" << "  \\          /    |     |\\   | /   \\    " << std::endl;
		std::cout << "  |     | " << "\t" << "   \\        /     |     | \\  | \\___     " << std::endl;
		std::cout << "  |     | " << "\t" << "    \\  /\\  /      |     |  \\ |     \\   " << std::endl;
		std::cout << "   \\___/ " << "\t" << "     \\/  \\/    ___|___  |   \\| \\___/   " << std::endl;
		std::cout << std::endl;
		std::cout << "(O wins)" << std::endl;
	}
	if (AnyWinnerYet == TicTac::PLAYER_X_WIN)
	{
		std::cout << std::endl;
		std::cout << "        " <<         "               _______          ___     " << std::endl;
		std::cout << "  \\  / " << "\t" << "  \\          /    |     |\\   | /   \\    " << std::endl;
		std::cout << "   \\/  " << "\t" << "   \\        /     |     | \\  | \\___     " << std::endl;
		std::cout << "   /\\  " << "\t" << "    \\  /\\  /      |     |  \\ |     \\    " << std::endl;
		std::cout << "  /  \\ " << "\t" << "     \\/  \\/    ___|___  |   \\| \\___/    " << std::endl;
		std::cout << std::endl;
		std::cout << "(X wins)" << std::endl;
	}
}


TicTac TicTacToe::beginGame(void)
{
	auto readyToRollx = 'n';
	auto readyToRollo = 'n';
	auto rollTurn = 'x';
	auto xRoll = 0;
	auto oRoll = 0;
	std::cout << "Welcome to Tic Tac Toe!" << std::endl;

	std::cout << "To play the game, you will enter the number" << std::endl;
	std::cout << "That corrisponds to the number on the board" << std::endl;
	std::cout << "The numbers are as follows:" << std::endl;

	std::cout << "   " << space1 << "  |  " << space2 << "  |  " << space3 << "  " << std::endl;
	std::cout << "---" << "-" << "--+--" << "-" << "--+--" << "   " << std::endl;
	std::cout << "   " << space4 << "  |  " << space5 << "  |  " << space6 << "  " << std::endl;
	std::cout << "---" << "-" << "--+--" << "-" << "--+--" << "   " << std::endl;
	std::cout << "   " << space7 << "  |  " << space8 << "  |  " << space9 << "  " << std::endl;

	std::cout << "Please Roll(r) to see who goes first!" << std::endl;
	std::cout << "Player X will roll first." << std::endl;
	while (rollTurn == 'x')
	{
		std::cout << "Player X: Press (r) key when ready to roll";
		std::cin >> readyToRollx;
		std::cout << std::endl;
		if (readyToRollx == 'r')
		{
			xRoll = TicTacToe::roll();
			std::cout << "Player X has rolled a " << xRoll << "." << std::endl;
			rollTurn = 'o';
		}
		else
		{
			std::cout << readyToRollx << " is not a valid response. " << std::endl;
			std::cout << std::endl;
		}
	}

	while (rollTurn == 'o')
	{
		std::cout << "Player O : Press (r) key when ready to roll";
		std::cin >> readyToRollo;
		std::cout << std::endl;
		if (readyToRollo == 'r')
		{

			oRoll = TicTacToe::roll();
			std::cout << "Player O has rolled a " << oRoll << "." << std::endl;
			rollTurn = 'n';
		}
		else
		{
			std::cout << readyToRollo << " is not a valid response. " << std::endl;
			std::cout << std::endl;
		}
	}
	if (xRoll >= oRoll)
	{
		return TicTac::PLAYER_X_TURN;
		std::cout << "Player X will go first. " << std::endl;
	}
	else
	{
		return TicTac::PLAYER_O_TURN;
		std::cout << "Player O will go first. " << std::endl;
	}
}



int TicTacToe::roll()
{
	static std::random_device rd;
	static std::mt19937 engine(rd());
	std::uniform_int_distribution<> die(1, 6);
	return die(engine);
}



TicTac TicTacToe::takeTurn(TicTac PlayerTurn)
{
	auto turnChoice = 0;
	std::cout << "Choose a space (1-9): ";
	std::cin >> turnChoice;

	while (turnChoice < 1 || turnChoice > 9)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << turnChoice << " is not a valid response. Please choose a space (1-9)" << std::endl;
		std::cin.clear();
		std::cin.ignore('100', '\n');
		std::cin >> turnChoice;
	}
	return(TicTacToe::displayBoard(PlayerTurn, turnChoice));



	//auto continuePlaying = displayBoard(PlayerTurn, turnChoice);
	//return(continuePlaying);


}

bool TicTacToe::playAgainFunction(void)
{
	auto playAgain = 'a';
	std::cout << "Would you like to play again(y/n)?";
	space1 = '1';
	space2 = '2';
	space3 = '3';
	space4 = '4';
	space5 = '5';
	space6 = '6';
	space7 = '7';
	space8 = '8';
	space9 = '9';
	std::cin >> playAgain;
	std::cout << std::endl;
	while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N')
	{
		std::cout << "Please Choose a Valid Response (y/n)..." << std::endl;
		std::cin >> playAgain;

	}
	if (playAgain == 'y' || playAgain == 'Y')
	{
		std::cout << "You have Chosen To play again!" << std::endl;
		return(true);
	}
	else
	{
		return(false);
	}
}

int turnCounter = 0;

TicTac TicTacToe::returnWinner(TicTac whosTurn)
{

	turnCounter++;
	TicTac winnaWinna;
	if (whosTurn == TicTac::PLAYER_O_TURN)
	{
		winnaWinna = TicTac::PLAYER_O_WIN;
	}
	if (whosTurn == TicTac::PLAYER_X_TURN)
	{
		winnaWinna = TicTac::PLAYER_X_WIN;
	}
	if (space1 == space2 && space2 == space3 && space1 != '-')
	{
		return winnaWinna;
	}
	else if (space4 == space5 && space5 == space6 && space4 != '-')
	{
		return winnaWinna;
	}
	else if (space7 == space8 && space8 == space9 && space7 != '-')
	{
		return winnaWinna;
	}
	else if (space1 == space4 && space4 == space7 && space1 != '-')
	{
		return winnaWinna;
	}
	else if (space2 == space5 && space5 == space8 && space2 != '-')
	{
		return winnaWinna;
	}
	else if (space3 == space6 && space6 == space9 && space3 != '-')
	{
		return winnaWinna;
	}
	else if (space1 == space5 && space5 == space9 && space1 != '-')
	{
		return winnaWinna;
	}
	else if (space3 == space5 && space5 == space7 && space3 != '-')
	{
		return winnaWinna;
	}
	else if (space1 != '1' && space2 != '2' && space3 != '3' && space4 != '4' && space5 != '5' && space6 != '6' && space7 != '7' && space8 != '8' && space9 != '9')
	{
		return TicTac::DRAW;
	}
	else
	{
		return TicTac::NO_WINNER_YET;
	}
}
