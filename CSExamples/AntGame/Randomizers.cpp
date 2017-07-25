#include "AntGame.hpp"

int antGame::generateRandomStartRow()
{
	std::uniform_int_distribution<> row(1, ROWS-1);

	return row(engine);
}

int antGame::generateRandomStartCol()
{

	std::uniform_int_distribution<> column(1, COLS-1);

	return column(engine);

}


antGame::DIRECTION antGame::randomDirection()
{
	std::uniform_int_distribution<> direction(1, 8);
	auto returnDir = direction(engine);


	if (returnDir == 1)
		return DIRECTION::UP_LEFT;
	if (returnDir == 2)
		return DIRECTION::UP;
	else if (returnDir == 3)
		return DIRECTION::UP_RIGHT;
	else if (returnDir == 4)
		return DIRECTION::LEFT;
	else if (returnDir == 5)
		return DIRECTION::RIGHT;
	else if (returnDir == 6)
		return DIRECTION::DOWN_LEFT;
	else if (returnDir == 7)
		return DIRECTION::DOWN;
	else
		return DIRECTION::DOWN_RIGHT;

	/*
	1 2 3
	4   5
	6 7 8
	*/

}
