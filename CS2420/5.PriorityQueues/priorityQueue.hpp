#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP



//built ins
#include <random>
#include <memory>
#include <vector>
//hpp's
#include"Timer.hpp"


extern bool isDebug;


class priorityQueue
{
public:
	//public function to seed the priorityQueue with a specified amount of random values
	void seedRandomValues(int amountOfValues);
	//public function to return a random number, using the random device in the CPU to seed a mersenne twister. 
	int getRandomNum(int begin, int end);
	//public function to add a value to the priorityQueue
	void addNum(int num);
	void addToMin(int num);
	void addToMax(int num);
	//public function to report the status of the priority queue
	void report(bool printQueue);
	/*-*-*-*-*-*-*-*TIMER FUNCTIONS*-*-*-*-*-*-*/
	//start the private timer
	void startTimer() { pqTimer.startTimer(); }
	//end the private timer
	void endTimer() { pqTimer.endTimer(); }
	//return the duration of the timer.
	double getDuration() { return pqTimer.duration(); }
	//return the size of the prioirty queue
	int getSize() { return size; }
	//print the skewheap "prettily"
	void printQueue();
	void printMin(int place, std::string indent);
	void printMax(int place, std::string indent);
	//get parent/children
	int getParent(int curPos);
	int getLeftChild(int curPos);
	int getRightChild(int curPos);
private:
	//private variable to keep track of merges
	int merges = 0;
	//private size variable, so the priorityQueue will know it's size.
	int size = 0;
	//private pointer to remember the median.
	int median;
	//private timer variable. setup in priortyQueue class to tie the timer to each priorityQueue that is setup.
	timer pqTimer;
	//vector for minHeap
	std::vector<int> minHeap;
	std::vector<int> maxHeap;


};


#endif // !PRIORITY_QUEUE_HPP