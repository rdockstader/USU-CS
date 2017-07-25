#include "sorting.hpp"

void insertionSort(std::vector<int>& c)
{
	for (auto i = 1u; i < c.size(); ++i)
	{
		for (auto j = 0u; j < i; ++j)
		{
			if (c[j] < c[i]) std::swap(c[j], c[i]);
		}
	}
}
