#include "sorting.hpp"

void bubbleSort(std::vector<int>& c)
{
	auto done = false;
	while (!done)
	{
		done = true;
		for (auto i = 0u; i < c.size() - 1; ++i)
		{
			if (c[i] > c[i + 1])
			{
				std::swap(c[i], c[i + 1]);
				done = false;
			}
		}
	}
}
