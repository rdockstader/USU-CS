#include "sorting.hpp"
#include <vector>

void quickSort(std::vector<int>& A, int p, int q)
{
	int r;
	if (p<q)
	{
		r = partition(A, p, q);
		quickSort(A, p, r);
		quickSort(A, r + 1, q);
	}
}


int partition(std::vector<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;
	int j;

	for (j = p + 1; j<q; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			std::swap(A[i], A[j]);
		}

	}

	std::swap(A[i], A[p]);
	return i;
}


void quickSortFunc(std::vector<int>& v)
{
	auto p = 0;
	auto q = v.size();

	quickSort(v, p, q);
}
