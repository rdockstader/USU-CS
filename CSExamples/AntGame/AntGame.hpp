#ifndef ANT_GAME_HPP
#define ANT_GAME_HPP

#include <array>
#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include <algorithm>


static std::random_device rd;
static std::mt19937 engine(rd());

using grid_t = std::vector <std::vector<char>>;

struct cords
{
	int column;
	int row;
};

class antGame
{
public:
	void initializeVariables(grid_t& oldGrid);
	void displayAutomation(grid_t& oldGrid);
	grid_t getGridSize();

	void displayAntRowAndCol();
private:
	enum DIRECTION
	{
		UP_LEFT,
		UP,
		UP_RIGHT,
		LEFT,
		RIGHT,
		DOWN_LEFT,
		DOWN,
		DOWN_RIGHT

	};



	int antRow, antCol, iters = 0, crittersAmount = 1, ROWS = 1, COLS = 1;
	std::vector<cords> critters;
	int generateRandomStartCol();
	int generateRandomStartRow();
	DIRECTION randomDirection();

	void moveAnt(grid_t& grid);
	void moveCritters(grid_t& grid);

	void display(grid_t const & r);


};




#endif
