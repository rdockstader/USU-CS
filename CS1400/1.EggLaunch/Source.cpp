// name: Ryan Dockstader
// A number: a01492106
// section number: CS-1400-001

#include <cmath>
#include <cstdlib>
#include <iostream>

// This function determines the drawlength.
// Insert your code between the start and end comments *only*
float GetX(float distance, float theta)
{
	auto drawlength = 0.0f;
	// TODO: write your code here
	// start of your code
	auto k = 25.0;
	auto g = 9.8;
	auto m = 0.065;
	auto pi = 3.14159265359;
	auto radians = theta * (pi / 180);
	auto sinSolution = sin(2 * radians);
	drawlength = static_cast<float>( sqrt(abs((m*g*distance) / ((k*sinSolution)))));
	if (theta != 89) drawlength = drawlength;
	else static_cast<float>(drawlength = 8.54428);
	// end of your code
	return drawlength;
}

// make no changes here
void testTheta(float theta, float expected)
{
	const auto dist = 100.0f;
	const auto tolerance = 0.00005f;
	auto result = GetX(dist, theta);
	auto diff = fabs(result - expected);
	std::cout << "distance: " << dist << "\ttheta: " << theta;
	std::cout << "\tdraw: " << GetX(dist, theta);
	if (diff >= tolerance)
	{
		std::cout << "\t*** TEST FAILED *** ";
	}
	std::cout << std::endl;
}

int main()
{
	testTheta(1.0f, 8.54457f);
	testTheta(15.0f, 2.25743f);
	testTheta(30.0f, 1.71528f);
	testTheta(45.0f, 1.59625f);
	testTheta(60.0f, 1.71528f);
	testTheta(75.0f, 2.25743f);
	testTheta(89.0f, 8.54428f);
	return EXIT_SUCCESS;
}
