#include "AntGame.hpp"

void antGame::initializeVariables(grid_t& oldGrid)
{
	for (auto&& row : oldGrid)
	{
		for (auto&& e : row)
		{
				e = 'E';
		}
	}

	antCol = generateRandomStartCol();
	antRow = generateRandomStartRow();

	oldGrid[antRow][antCol] = 'A';

	for (int i = 1; i <= crittersAmount; ++i)
	{
		auto row = generateRandomStartRow();
		auto col = generateRandomStartCol();
		oldGrid[row][col] = 'C';
		cords cord;
		cord.row = row;
		cord.column = col;
		critters.push_back(cord);
	}
}

grid_t antGame::getGridSize()
{	
	grid_t grid;
	std::cout << "Number of Rows?" << std::endl;
	std::cin >> ROWS;
	std::cout << "Number of Columns?" << std::endl;
	std::cin >> COLS;
	std::cout << "Number of Critters?" << std::endl;
	std::cin >> crittersAmount;
	std::cout << std::endl;
	grid.resize(ROWS);
	for (auto&& e : grid)
	{
		e.resize(COLS);
	}

	return grid;

}
