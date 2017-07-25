#include "Sorting.hpp"

void timer::startTimer(void)
{
	start = std::chrono::system_clock::now();
}

void timer::endTimer(void)
{
	end = std::chrono::system_clock::now();
}

double timer::duration(void)
{
	elapsed_seconds = end - start;
	return elapsed_seconds.count();
}
