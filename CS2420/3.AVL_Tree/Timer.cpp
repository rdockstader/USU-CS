#include"Timer.hpp"
//funciton to start the timer
void timer::startTimer(void)
{
	//set the start time to the time the function is called.
	start = std::chrono::system_clock::now();
}

//function to stop the time.
void timer::endTimer(void)
{
	//set the end time to the time the functino is called
	end = std::chrono::system_clock::now();
}

//output the duration
double timer::duration(void)
{
	//set the elapsed_seconds to end - start.
	elapsed_seconds = end - start;
	//return that value.
	return elapsed_seconds.count();
}