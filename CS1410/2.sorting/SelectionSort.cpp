#include "sorting.hpp"


int min(std::vector<int>& c, unsigned int start)
{
	auto min = std::numeric_limits<int>::max();
	auto cur = -1;
	for (auto i = start; i < c.size(); ++i)
	{
		if (min > c[i])
		{
			min = c[i];
			cur = i;
		}
	}
	return cur;
}

void selectionSort(std::vector<int>& c)
{
	for (auto i = 0u; i < c.size(); ++i)
	{
		auto smallest = min(c, i);
		std::swap(c[i], c[smallest]);
	}
}
