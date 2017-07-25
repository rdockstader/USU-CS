#include "Sorting.hpp"
#include <fstream>
#include <iostream>

void main(void)
{
	
	std::ofstream fout("output.txt");

	testFunction("bubble sort", bubbleSort, fout);
	testFunction("Selection sort", selectionSort, fout);
	testFunction("insertion sort", insertionSort, fout);
	testFunction("Merge Sort", mergeSort, fout);
	testFunction("Quick sort", quickSortFunc, fout);
	testFunction("std::sort", stdSort, fout);
	

}
