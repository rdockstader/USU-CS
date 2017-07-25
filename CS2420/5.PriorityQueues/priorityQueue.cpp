//built ins
#include<iostream>
#include<string>
//hpp's
#include"priorityQueue.hpp"

bool isDebug = false;

int priorityQueue::getRandomNum(int begin, int end)
{
	static std::random_device randDev;
	static std::mt19937 mersenneTwister(randDev());
	std::uniform_int_distribution<> unifIntDist(begin, end);
	return unifIntDist(mersenneTwister);
}

void priorityQueue::seedRandomValues(int amountOfValues)
{
	for (int i = 0; i < amountOfValues; ++i)
	{
		addNum(getRandomNum(0, 1000));
	}
}

void priorityQueue::addNum(int num)
{
	++size;

	if (!median)
		median = num;
	else if (num <= median)
		addToMin(num);
	else
		addToMax(num);

	if (maxHeap.size() >= minHeap.size() + 2)
	{
		//merges++;
		addToMin(median);
		median = maxHeap[maxHeap.size() - 1];
		maxHeap.pop_back();
	}
	else if (minHeap.size() >= maxHeap.size() + 2)
	{
		//merges++;
		addToMax(median);
		median = minHeap[minHeap.size() - 1];
		minHeap.pop_back();
	}



}

void priorityQueue::addToMin(int num)
{
	minHeap.push_back(num);
	if (minHeap.size() <= 1)
	{
		if (isDebug)
			std::cout << "MinHeap size not greater then 1. Size: " << minHeap.size() << std::endl;
	}
	else
	{
		if (isDebug)
			std::cout << "Minheap size is greater then 1. Size: " << minHeap.size() << std::endl;
		int curNode = minHeap.size() - 1;
		while ((minHeap[curNode] < minHeap[curNode - 1]) && curNode >= 0)
		{
			std::swap(minHeap[curNode], minHeap[curNode - 1]);
			merges++;
			curNode--;
			if (curNode <= 0)
				break;
		}
	}
	if (isDebug)
	{
		std::cout << "Minheap: ";
		for (auto e : minHeap)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

}

void priorityQueue::addToMax(int num)
{
	maxHeap.push_back(num);
	if (maxHeap.size() <= 1)
	{
		if (isDebug)
			std::cout << "MaxHeap size not greater then 1. Size: " << maxHeap.size() << std::endl; 
	}
	else
	{
		if (isDebug)
			std::cout << "Maxheap size is greater then 1. Size: " << maxHeap.size() << std::endl;
		int curNode = maxHeap.size() - 1;
		while ((maxHeap[curNode] > maxHeap[curNode - 1]) && curNode >= 0)
		{
			std::swap(maxHeap[curNode], maxHeap[curNode - 1]);
			merges++;
			curNode--;
			if (curNode <= 0)
				break;
		}
	}
	if(isDebug)
	{
		std::cout << "Maxheap: ";
		for (auto e : maxHeap)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}

}


void priorityQueue::report(bool doPrintQueue)
{
	std::cout << std::endl;
	std::cout << "Median: " << median << std::endl;
	std::cout << "Heap Size: " << size << std::endl;
	std::cout << "Merges: " << merges << std::endl;
	std::cout << std::endl;

	if (doPrintQueue)
		printQueue();

}

void priorityQueue::printQueue()
{
	printMax(1, "");
	std::cout << median << std::endl;	
	printMin(1, "");
}


void priorityQueue::printMax(int place, std::string indent)
{
	if (maxHeap.size() == 0)
		return;
	if (place >= maxHeap.size()+1)
		return;
	indent = indent + "	";
	printMax(getRightChild(place), indent);
	std::cout << indent << maxHeap[place-1] << std::endl;
	printMax(getLeftChild(place), indent);

}

void priorityQueue::printMin(int place, std::string indent)
{
	if (minHeap.size() == 0)
		return;
	if (place >= minHeap.size()+1)
		return;
	indent = indent + "	";
	printMin(getRightChild(place), indent);
	std::cout << indent << minHeap[place-1] << std::endl;
	printMin(getLeftChild(place), indent);
}

int priorityQueue::getParent(int curPos)
{
	return curPos / 2;
}
int priorityQueue::getLeftChild(int curPos)
{
	return 2 * curPos;
}
int priorityQueue::getRightChild(int curPos)
{
	return (2 * curPos) + 1;
}