#include "header.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


mazeSolver::mazeSolver()
{

}

void mazeSolver::specifyFile()
{
	std::cout << " Please specify the maze file you would like to solve: ";
	std::cin >> file_name;
	std::cout << std::endl;
}



void mazeSolver::readFile(void)
{
	std::ifstream input_file(file_name);
	auto r = 0;
	auto c = 0;
	input_file >> r >> c;

	matrix.resize(r+1);
	for(auto&& row: matrix)
		row.resize(c+1);


	std::cout << "Reading Maze File..." << std::endl;
	std::cout << std::endl;


	for (auto i = 1; i <= r; ++i)
	{
		for (auto j = 1; j <= c; ++j)
		{
			char fromFile;
			input_file >> fromFile;
			matrix[i][j] = read(fromFile);
			if (matrix[i][j] == START)
			{
				startRow = i;
				startCol = j;
			}
		}
		std::cout << std::endl;
	}

}

mazeSolver::cellType mazeSolver::read(char fromFile)
{
	switch (fromFile)
	{
	case 'X': return WALL;
	case 's': return START;
	case 'e': return END;
	default: return EMPTY;

	}
	return EMPTY;
}


void mazeSolver::navigateMaze()
{
	std::cout << "Solving Maze..." << std::endl;

	solve(startRow, startCol);
	
}

bool mazeSolver::solve(int r, int c)
{
	auto& cell = matrix[r][c];
	if (cell == WALL) return false;
	if (cell == VISITED) return false;
	if (cell == END) return true;
	cell = VISITED;
	if (solve(r - 1, c))
	{
		cell = ON_PATH;
		return true;
	}
	if (solve(r + 1, c))
	{
		cell = ON_PATH;
		return true;
	}
	if (solve(r, c - 1))
	{
		cell = ON_PATH;
		return true;
	}
	if (solve(r, c + 1))
	{
		cell = ON_PATH;
		return true;
	}
	return false;
}

void mazeSolver::display()
{
	for (auto&& row : matrix)
	{
		for (auto&& cell : row)
		{
			display(cell);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void mazeSolver::display(cellType c)
{
	switch (c)
	{
	case WALL:
		std::cout << 'X';
		break;
	case VISITED:
		std::cout << ' ';
		break;
	case EMPTY:
		std::cout << ' ';
		break;
	case ON_PATH:
		std::cout << '.';
		break;
	case START:
		std::cout << 's';
		break;
	case END:
		std::cout << 'e';
		break;
	}
}
