#include "AntGame.hpp"

void antGame::moveAnt(grid_t& grid)
{
	DIRECTION dir = randomDirection();
	auto oldAntCol = antCol;
	auto oldAntRow = antRow;
	if (dir == DIRECTION::UP_LEFT)
	{
		antCol--;
		antRow--;
	}
	else if (dir == DIRECTION::UP)
	{
		antRow--;
	}
	else if (dir == DIRECTION::UP_RIGHT)
	{
		antRow--;
		antCol++;
	}
	else if (dir == DIRECTION::LEFT)
	{
		antCol--;
	}
	else if (dir == DIRECTION::RIGHT)
	{
		antCol++;
	}
	else if (dir == DIRECTION::DOWN_LEFT)
	{
		antCol--;
		antRow++;
	}
	else if (dir == DIRECTION::DOWN)
	{
		antRow++;
	}
	else
	{
		antRow++;
		antCol++;
	}
	if (antCol >= 0 && antCol <= COLS - 1 && antRow >= 0 && antRow <= ROWS - 1)
	{
		grid[oldAntRow][oldAntCol] = 'E';
		grid[antRow][antCol] = 'A';
		return;
	}
	else
	{
		std::cout << "The ant has left the building in " << iters << " moves!" << std::endl;
		return;
	}


}

void antGame::moveCritters(grid_t& grid)
{
	for (auto&& e : critters)
	{
		DIRECTION dir = randomDirection();
		auto oldCritterCol = e.column;
		auto oldCritterRow = e.row;
		if (dir == DIRECTION::UP_LEFT)
		{
			e.column--;
			e.row--;

		}
		else if (dir == DIRECTION::UP)
		{
			e.row--;

		}
		else if (dir == DIRECTION::UP_RIGHT)
		{
			e.row--;
			e.column++;
		}
		else if (dir == DIRECTION::LEFT)
		{
			e.column--;
		}
		else if (dir == DIRECTION::RIGHT)
		{
			e.column++;
		}
		else if (dir == DIRECTION::DOWN_LEFT)
		{
			e.column--;
			e.row++;
		}
		else if (dir == DIRECTION::DOWN)
		{
			e.row++;
		}
		else
		{
			e.row++;
			e.column++;
		}
		if (e.column >= 0 && e.column <= COLS - 1 && e.row >= 0 && e.row <= ROWS - 1)
		{
			grid[oldCritterRow][oldCritterCol] = 'E';
			grid[e.row][e.column] = 'C';
			return;
		}
		else if (e.column > COLS - 1)
		{
			e.column--;
		}
		else if (e.column < 0)
		{
			e.row++;
		}
		else if (e.row > ROWS - 1)
		{
			e.row--;
		}
		else if (e.row < 0)
		{
			e.row++;
		}
	}
}
