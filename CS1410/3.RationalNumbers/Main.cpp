#include "Rational.hpp"
#include <iostream>

int main()
{
	std::cout << "Please input 2 rational numbers:  " << std::endl;
	Rational a, b;
	std::cin >> a >> b;
	std::cout << std::endl;


	std::cout << "Comparison tests: " << std::endl;
	std::cout << std::endl;
	if (a < b) std::cout << a << '<' << b  << std::endl;
	if (a > b) std::cout << a << '>' << b  << std::endl;
	if (a <= b) std::cout << a << "<=" << b<< std::endl;
	if (a >= b) std::cout << a << ">=" << b<< std::endl;
	if (a == b) std::cout << a << "==" << b<< std::endl;
	if (a != b) std::cout << a << "!=" << b<< std::endl;
	std::cout << std::endl;

	std::cout << "Basic operator test: " << std::endl;
	std::cout << std::endl;
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	std::cout << std::endl;

	std::cout << "c++ opeartor test: " << std::endl;
	std::cout << std::endl;
	
	Rational tempa = a;
	std::cout << tempa << " += " << b << " = " << (a += b) << std::endl;
	tempa = a;
	std::cout << tempa << " -= " << b << " = " << (a -= b) << std::endl;
	tempa = a;
	std::cout << tempa << " *= " << b << " = " << (a *= b) << std::endl;
	tempa = a;
	std::cout << tempa << " /= " << b << " = " << (a /= b) << std::endl;
	std::cout << "double and float tests: " << std::endl;
	std::cout << a << " as a double: " << static_cast<double>(a) << std::endl;
	std::cout << b << " as a float: " <<  static_cast<float>(b) << std::endl;
	



	system("PAUSE");
}
