#include <vector>

//linear find
bool find(int target, std::vector<int>& container)
{
	for(auto&& e: container)
	{
		if(e == target) return true;
	}
	return false;

}

//binary find
bool find(int target, std::vector<int> container, int begin, int end)
{
	if (end < begin) return false;

	//divide in half

	auto mid = (begin + end) / 2;
	if(container[mid] == target) return true;

	//determine correct half
	//search in that half

	if(container[mid] < target)
	{
		find(target, container, begin, mid - 1);
	}
	else
	{
		find(target, container, mid + 1, end);
	}

}
