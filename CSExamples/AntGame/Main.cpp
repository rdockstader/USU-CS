#include "AntGame.hpp"

int main()
{
	antGame game;
	grid_t oldGrid;

	oldGrid = game.getGridSize();

	game.initializeVariables(oldGrid);

	game.displayAutomation(oldGrid);

	game.displayAntRowAndCol();
	system("PAUSE");
}

/*
THINGS TO DO:

1. Make it so if they run into each other, then don't actually move.

*/
