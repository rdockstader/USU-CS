#ifndef TIMER_HPP
#define TIMER_HPP
#include <chrono>
#include <vector>
#include <fstream>
#include <functional>

//create a timer class, for teseting
class timer
{
public:
	//function to start the timer
	void startTimer(void);
	//function to end the timer
	void endTimer(void);
	//function to output the duration
	double duration(void);
private:
	//two timepoint variables of start and end
	std::chrono::time_point<std::chrono::system_clock> start, end;
	//duration variable.
	std::chrono::duration<double> elapsed_seconds;

};

#endif // !TIMER_HPP
