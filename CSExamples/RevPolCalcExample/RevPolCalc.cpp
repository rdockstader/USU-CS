#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cstdlib>
#include <exception>

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




int main()
{
	std::vector<int> stack;
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
				apply(stack, [](int a, int b) {return a + b; });
			}
			else if (input[0] == '-')
			{
				apply(stack, [](int a, int b) {return a - b; });
			}
			else if (input[0] == '*')
			{
				apply(stack, [](int a, int b) {return a * b; });
			}
			else if (input[0] == '/')
			{
				apply(stack, [](int a, int b) {return a / b; });
			}
			else
			{
				auto value = atoi(input.c_str()); //this function wont work for rational number, so we will have to write our own function to do this.
				stack.push_back(value);
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
			stack.clear();
		}
		catch(...)
		{
			std::cout << "Unexpected exception has occured." << std::endl;
			stack.clear();
		}
	}
}


#include <iostream>
#include <string>

int main()
{
	std::string str("Test string");
	for (unsigned i = 0; i<str.length(); ++i)
	{
		std::cout << str.at(i) << std::endl;
	}
	system("PAUSE");

}
