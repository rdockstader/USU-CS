#include "Rational.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cstdlib>
#include <exception>
#include <cassert>

template<typename C, typename F>
void apply(C & container, F f)
{
	if (container.size() < 2) throw std::runtime_error("Not enough operands."); std::cout << std::endl;
	auto second = container.back();
	container.pop_back();
	auto first = container.back();
	container.pop_back();

	auto result = f(first, second);
	std::cout << first << " op " << second << " = " << result << std::endl;
	container.push_back(result);
}

Rational buildRational(int value)
{
	auto d = 0;
	std::cout << "denominator: ";
	std::cin >> d;
	std::cout << std::endl;
	Rational r(value, d);
	return r;
}




int main()
{
	std::cout << "Calculator Instructions:" << std::endl;
	std::cout << "press <c> to clear." << std::endl;
	std::cout << "Press <e> to exit." << std::endl;
	std::cout << "Enter in reverse polish (Ex: 2 2 + is \" 2+2 \" " << std::endl;
	std::cout << "Enter in all inputs as rational number, Ex: 1/2" << std::endl;

	std::vector<Rational> stack;
	while (true)
	{
		try
		{
			std::string input;
			std::getline(std::cin, input);
			if (input[0] == 'e') return EXIT_SUCCESS;
			if (input[0] == 'c')
			{
				stack.clear();
			}
			/*
			for each operator you want to do the EXACT same thing, so we are going to write something that will take the operator, and do the same thing for each thing.
			this is done in a template, up at the top
			*/
			if (input[0] == '+')
			{
				apply(stack, [](Rational a, Rational b) {return a + b; });
			}
			else if (input[0] == '-')
			{
				apply(stack, [](Rational a, Rational b) {return a - b; });
			}
			else if (input[0] == '*')
			{
				apply(stack, [](Rational a, Rational b) {return a * b; });
			}
			else if (input[0] == '/')
			{
				apply(stack, [](Rational a, Rational b) {return a / b; });
			}
			else
			{
				std::vector<int> vec;
				for (unsigned i = 0; i < input.length(); ++i)
				{
					if (isdigit(input.at(i)))
					{
						int c = input.at(i) - '0';
						vec.push_back(c);

					}
				}
				Rational R(vec[0], vec[1]);
				stack.push_back(R);
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
			stack.clear();
		}
		catch (...)
		{
			std::cout << "Unexpected exception has occured." << std::endl;
			stack.clear();
		}
	}
}
