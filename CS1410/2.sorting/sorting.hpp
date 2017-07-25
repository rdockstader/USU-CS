#ifndef SORTING_ASSIGNMENT_HPP
#define SORTING_ASSIGNMENT_HPP

#include <chrono>
#include <vector>
#include <fstream>
#include <functional>


void bubbleSort(std::vector<int>& c);
std::vector<int>  generateList(int);
void runSort(int size, std::function<void(std::vector<int>)> function, std::ofstream& fout);
void bubbleSort(std::vector<int>&);
void insertionSort(std::vector<int>&);
void selectionSort(std::vector<int>&);
void mergeSort(std::vector<int>&);
void quickSort(std::vector<int>& A, int p, int q);
void stdSort(std::vector<int>&);
void quickSortFunc(std::vector<int>&);
int min(std::vector<int>&,unsigned int);
std::vector<int> merge(std::vector<int>&, std::vector<int>&);
int partition(std::vector<int>&, int, int);
void testFunction(std::string fName, std::function<void(std::vector<int>)> function, std::ofstream& fout);


class timer
{
public:
	void startTimer(void);
	void endTimer(void);
	double duration(void);
private:
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

};


#endif
