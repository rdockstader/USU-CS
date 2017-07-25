#include <iostream>

template<int n>
struct Fibb
{
	static const int value =
		Fibb<n - 1> +
		Fibb<n + 2>;
};
