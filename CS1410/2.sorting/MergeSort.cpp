#include "sorting.hpp"
#include <iostream>




std::vector<int> merge(std::vector<int>& a, std::vector<int>& b) 
{ 
	auto i = 0u; 
	auto j = 0u; 
	std::vector<int> res;
	res.reserve(a.size() + b.size());
	while (i<a.size() && j<b.size()) 
	{ 
		if(a[i] < b[j]) 
		{
			res.push_back(a[i]);
			++i; 
		} 
		else 
		{ 
			res.push_back(b[j]);
			++j; 
		} 
	} 
	if(i<a.size())
	{ 
		for (auto k = i; k<a.size(); ++k)
			res.push_back(a[k]);
	} 
	else 
	{ 
		for (auto k = j; k<b.size(); ++k)
			res.push_back(b[k]); 
	} 

	return res;
}

void mergeSort(std::vector<int>& c)
{
	if (c.size() > 2)
	{
		auto end = c.size();
		auto start = 0;
		auto mid = start + (end - start) /2;
		if (c.size() % 2 != 0)
			mid = start + (end - start) / 2;
		std::vector<int>a, b;
		a.resize(mid);
		b.resize(mid);
		for (auto i = 0u; i < a.size(); ++i)
		{
			a[i] = c[i];
			b[i] = c[i + mid];

		}
	
		mergeSort(a);
		mergeSort(b);
		c = merge(a, b);
		
	}
}
