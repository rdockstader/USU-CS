#include <array>
#include <iostream>

const auto COLS = 40;
const auto ROWS = 20;
const auto ITERATIONS = 100;
const auto ALIVE_CHAR = "|";
const auto DEAD_CHAR = "_";


using grid_t = std::array <std::array<bool, COLS>, ROWS> ;
using tinyGrid_t = std::array < std::array<bool, 3>, 3 > ;

void display(grid_t const & r)
{
	for (auto&& ROW : r)
	{
		for (auto&& e : ROW)
		{
			if (e)
			{
				std::cout << ALIVE_CHAR;
			}
			else
			{
				std::cout << DEAD_CHAR;
			}
		}
		std::cout << std::endl;
	}
}

bool update(bool topRight, bool topCenter, bool topLeft, bool right, bool center, bool left, bool bottomRight, bool bottomCenter, bool bottomLeft)
{

	bool curValue = center;
	auto x = 0;
	tinyGrid_t grid;
	grid[0][0] = topLeft;
	grid[0][1] = topCenter;
	grid[0][2] = topRight;
	grid[1][0] = left;
	grid[1][1] = center;
	grid[1][2] = right;
	grid[2][0] = bottomLeft;
	grid[2][1] = bottomCenter;
	grid[2][2] = bottomRight;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (grid[i][j] == true)
				{
					++x;
				}
			}
		}
		if (center == false)
		{
			if (x == 3)
			{
				return true;
			}
			if (x == 2)
			{
				return curValue;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (x == 4)
			{
				return true;
			}
			if (x == 3)
			{
				return curValue;
			}
			else
			{
				return false;
			}
		}
}


grid_t updateMain(grid_t oldGrid)
{
	grid_t newGrid;
	for (int k = 1; k < COLS - 1; ++k) //top row
	{
		newGrid[0][k] = update(false, false, false, oldGrid[0][k + 1], oldGrid[0][k], oldGrid[0][k + 1], oldGrid[1][k - 1], oldGrid[1][k], oldGrid[1][k+1]);
	}
	for (int l = 1; l < COLS - 1; ++l)//bottom row
	{
		auto rows = ROWS - 1;
		newGrid[rows][l] = update(oldGrid[rows - 1][l + 1], oldGrid[rows - 1][l], oldGrid[rows - 1][l - 1], oldGrid[rows][l + 1], oldGrid[rows][l], oldGrid[rows][l - 1], false, false, false);
	}
	
	
	for (int m = 1; m < ROWS - 1; ++m) //left column
	{
		newGrid[m][0] = update(oldGrid[m - 1][1], oldGrid[m - 1][0], false, oldGrid[m][1], oldGrid[m][0], false, oldGrid[m + 1][1], oldGrid[m + 1][0], false);
	}
	for (int n = 1; n < ROWS - 1; ++n) //right column
	{
		int column = COLS - 1;
		newGrid[n][column] = update(false, oldGrid[n - 1][column], oldGrid[n - 1][column - 1], false, oldGrid[n][column], oldGrid[n][column - 1], false, oldGrid[n + 1][column], oldGrid[n + 1][column - 1]);
	}
	
	
	
	for (int i = 1; i < ROWS - 1; ++i)  //center parts
	{
		for (int j = 1; j < COLS - 1; ++j)
		{
			newGrid[i][j] = update(oldGrid[i - 1][j + 1], oldGrid[i - 1][j], oldGrid[i - 1][j - 1], oldGrid[i][j + 1], oldGrid[i][j], oldGrid[i][j - 1], oldGrid[i + 1][j + 1], oldGrid[i + 1][j], oldGrid[i + 1][j - 1]);
		}
	}

	//corners
	newGrid[0][0] = update(false, false, false, oldGrid[0][1], oldGrid[0][0], false, oldGrid[1][1], oldGrid[1][0], false);
	newGrid[ROWS - 1][COLS - 1] = update(false, oldGrid[ROWS - 2][COLS - 1], oldGrid[ROWS - 2][COLS - 2], false, oldGrid[ROWS - 1][COLS - 1], oldGrid[ROWS - 1][COLS - 2], false, false, false);
	newGrid[ROWS - 1][0] = update(oldGrid[ROWS - 2][1], oldGrid[ROWS - 2][0], false, oldGrid[ROWS - 1][1], oldGrid[ROWS - 1][0], false, false, false, false);
	newGrid[0][COLS - 1] = update(false, false, false, false, newGrid[0][COLS - 1], newGrid[0][COLS - 2], false, newGrid[1][COLS - 1], newGrid[1][COLS - 2]);

	return newGrid;

}

void createGliderAutomation(grid_t & oldGrid)
{
	//[column] [row]
	//first box
	oldGrid[5][1] = true;
	oldGrid[6][1] = true;
	oldGrid[5][2] = true;
	oldGrid[6][2] = true;
	//second box
	oldGrid[3][38] = true;
	oldGrid[4][38] = true;
	oldGrid[3][37] = true;
	oldGrid[4][37] = true;
	//gun
	oldGrid[5][10] = true;
	oldGrid[6][10] = true;
	oldGrid[7][10] = true;
	oldGrid[8][11] = true;
	oldGrid[9][12] = true;
	oldGrid[9][13] = true;
	oldGrid[4][11] = true;
	oldGrid[3][12] = true;
	oldGrid[3][13] = true;
	//gun2
	oldGrid[6][14] = true;
	oldGrid[4][15] = true;
	oldGrid[8][15] = true;
	oldGrid[5][16] = true;
	oldGrid[6][16] = true;
	oldGrid[7][16] = true;
	oldGrid[6][17] = true;
	//glider
	oldGrid[5][20] = true;
	oldGrid[4][20] = true;
	oldGrid[3][20] = true;
	oldGrid[5][21] = true;
	oldGrid[4][21] = true;
	oldGrid[3][21] = true;
	oldGrid[2][22] = true;
	oldGrid[6][22] = true;
	oldGrid[2][24] = true;
	oldGrid[6][24] = true;
	oldGrid[1][24] = true;
	oldGrid[7][24] = true;

}


void initializeVariables(grid_t& oldGrid)
{
	for (auto&& row : oldGrid)
	{
		for (auto&& e : row)
		{
			e = false;
		}
	}
}

void displayAutomation(grid_t& oldGrid)
{
	for (int iter = 1; iter <= ITERATIONS; ++iter)
	{
		oldGrid = updateMain(oldGrid);
		display(oldGrid);
		std::cout << std::endl;
	}
}

int main()
{
	grid_t oldGrid;

	initializeVariables(oldGrid);

	createGliderAutomation(oldGrid);

	displayAutomation(oldGrid);

	system("PAUSE");

	}
