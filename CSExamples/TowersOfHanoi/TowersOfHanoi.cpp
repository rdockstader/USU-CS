#include <iostream>
#include <string>


void moveDisk(int n, std::string from, std::string to, std::string other)
{
	if(n <= 0)
		return;
	moveDisk(n - 1, from, other, to);
	std::cout << "Move disc " << n << " from " << from
		<< " to " << to << std::endl;
	moveDisk(n - 1, other, to, from);

}

int numSteps(int n)
{

}

int main()
{
	moveDisk(10, "A", "B", "C");

	char dummy;
	std::cin >> dummy;
}
