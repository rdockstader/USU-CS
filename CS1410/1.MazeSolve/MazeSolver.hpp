#ifndef MAZE_SOLVER_HEADER_HPP
#define MAZE_SOLVER_HEADER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class mazeSolver
{
public:
	mazeSolver();
	void specifyFile();
	void readFile();
	void navigateMaze();
	void display();


private:
	enum cellType
	{
		WALL,
		VISITED,
		EMPTY,
		ON_PATH,
		START,
		END
	};

	std::vector <std::vector<cellType>> matrix;
	std::string file_name;
	int startRow;
	int startCol;

	void display(cellType);
	cellType read(char);
	bool solve(int, int);

};



#endif
