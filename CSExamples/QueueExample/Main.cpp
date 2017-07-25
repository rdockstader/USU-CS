#include "queue.hpp"

#include <cassert>
#include <iostream>

int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	auto a = q.dequeue();
	assert(a == 1);
	q.foreach([](int i) {std::cout << i << std::endl; });
	

	char dummy;
	std::cin >> dummy;
}
