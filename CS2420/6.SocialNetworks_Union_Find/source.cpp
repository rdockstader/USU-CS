#include"unionFind.hpp"
#include"Randomizer.hpp"

#include<iostream>

void leaveConsoleOpen();
int generateRandomNumber(int maxNumber);

int main()
{
	constexpr int members = 15000;
	int days = 0;

	UnionFind socialNetwork(members);
	Randomizer randomizer(members-1);

	bool hasWorldPeace = false;
	while (!hasWorldPeace)
	{
		socialNetwork.Union(
			randomizer.generateRandomInt()
			, randomizer.generateRandomInt()
		);
		++days;
		for (int i = 0; i < members; ++i)
		{
			if (socialNetwork.getRoot(0) != socialNetwork.getRoot(i))
			{
				hasWorldPeace = false;
				break;
			}
			else
				hasWorldPeace = true;
		}

	}

	std::cout << "this disjoint set connected " << members << " people after ";
	std::cout << socialNetwork.getUnions() << " successful unions." << std::endl;
	std::cout << "It took " << days << " days to achieve wold peace." << std::endl;
	std::cout << "Find was called recursively a total of " << socialNetwork.getFinds() << " times." << std::endl;




	leaveConsoleOpen();
	return 0;
}

void leaveConsoleOpen()
{
	char dummy;
	std::cout << "Enter any character to exit." << std::endl;
	std::cin >> dummy;
}

int generateRandomNumber(int maxNumber)
{
	return 0;
}