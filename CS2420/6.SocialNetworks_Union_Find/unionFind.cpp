#include"unionFind.hpp"
#include<iostream>

UnionFind::UnionFind(int elements)
{
	rank.resize(elements);
	parent.resize(elements);
	for (auto i=0; i < elements; ++i)
	{
		//std::cout << i << std::endl;
		rank[i] = 0; //set the rank to zero, as it only contains itself.
		parent[i] = i; //set the items parent, to itself.
	}
}

int UnionFind::Find(int element)
{
	finds++;
	if (parent[element] == element) return element;
	// path compression
	return parent[element] = Find(parent[element]);
}

void UnionFind::Union(int ele_a, int ele_b)
{

	//set the elements to their roots, using the find function.
	ele_a = Find(ele_a);
	ele_b = Find(ele_b);

	if (ele_a == ele_b)
		return; //if they already have the same root, break.

	unions++;
	if (rank[ele_a] > rank[ele_b])
	{
		parent[ele_b] = ele_a;
		rank[ele_a] = rank[ele_a] + rank[ele_b] + 1;
	}
	else
	{
		parent[ele_a] = ele_b;
		rank[ele_b] = rank[ele_b] + rank[ele_a] + 1;
	}


}

int UnionFind::getRoot(int element)
{
	if (parent[element] == element) return element;

	return getRoot(parent[element]);
}
