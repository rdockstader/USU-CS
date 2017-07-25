#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include<vector>

#define TVec std::vector


class UnionFind
{
public:
	int getFinds() { return finds; }
	int getUnions() { return unions; }
	UnionFind(int elements);
	int Find(int element);
	void Union(int ele_a, int ele_b);
	int getRoot(int element);
private:
	TVec<int> parent;
	TVec<int> rank;
	int finds = 0;
	int unions = 0;
};

#endif // !UNION_FIND_HPP