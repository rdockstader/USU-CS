#include "AntGame.hpp"

const char ANT = 'A';
const char OPEN_SPACE = '-';
const char CRITTER = 'C';

void antGame::display(grid_t const & r)
{
	for (auto&& ROW : r)
	{
		for (auto&& e : ROW)
		{
			if (e == 'A')
			{
				std::cout << ANT;
			}
			else if (e == 'C')
			{
				std::cout << CRITTER;
			}
			else if (e == 'E')
			{
				std::cout << OPEN_SPACE;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void antGame::displayAutomation(grid_t& oldGrid)
{
	while (antCol >= 0 && antCol <= COLS - 1 && antRow >= 0 && antRow <= ROWS - 1)
	{
		display(oldGrid);
		moveAnt(oldGrid);
		moveCritters(oldGrid);
		iters++;
	}
}

void antGame::displayAntRowAndCol()
{
	std::cout << "Ant Row: " << antRow << " Ant Col: " << antCol << std::endl;
}
