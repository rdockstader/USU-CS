//built in's
#include<iostream>
//hpps
#include"priorityQueue.hpp"

void leaveConsoleOpen();


void main()
{
	priorityQueue pq;
	//test seed random values function
	pq.seedRandomValues(15);
	//report
	pq.report(true);
	//set int to check report at size
	int checkReportAtSize = 32;
	//loop addNum outside of seed function.
	for (int i = 15; i < 1028; i++)
	{
		auto num = pq.getRandomNum(0, 1000);
		pq.addNum(num);
		if (i == checkReportAtSize)
		{
			pq.report(false);
			checkReportAtSize *= 2;
		}
	}

	leaveConsoleOpen();
}









void leaveConsoleOpen()
{
	char dummy;
	std::cout << "Enter any character to exit." << std::endl;
	std::cin >> dummy;
}