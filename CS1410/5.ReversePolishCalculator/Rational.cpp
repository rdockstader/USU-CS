#include "Rational.hpp"

//constructor
Rational::Rational(int n, int d) :numerator(n / gcd(n, d)), denominator(d/ gcd(n, d)) { }

//operators
Rational::operator double() const
{ 
	return static_cast<double>(numerator / denominator); 
}
Rational::operator float() const
{ 
	return static_cast<float>(numerator / denominator); 
}


// ...and equals..
Rational& Rational::operator+=(Rational const & rhs)
{
	this->setNumerator((numerator * rhs.denominator) + (rhs.numerator * denominator));
	this->setDenominator(denominator * rhs.denominator);
	return *this;
}
Rational& Rational::operator-=(Rational const & rhs)
{
	this->setNumerator((numerator * rhs.denominator) - (rhs.numerator * denominator));
	this->setDenominator(denominator * rhs.denominator);
	return *this;
}
Rational& Rational::operator*=(Rational const & rhs)
{
	this->setNumerator(numerator*rhs.numerator);
	this->setDenominator(denominator*rhs.denominator);
	return *this;
}
Rational& Rational::operator/=(Rational const & rhs)
{
	this->setNumerator(numerator*rhs.denominator);
	this->setDenominator(denominator*rhs.numerator);
	return *this;
}



//Gets and Sets
int Rational::getDenominator()const { return denominator; }
int Rational::getNumerator()const { return numerator; }
void Rational::setNumerator(int n)
{
	numerator = n;


	//numerator = (numerator / gcd(numerator, denominator));
	//denominator = (denominator / gcd(numerator, denominator));
}
void Rational::setDenominator(int d) 
{ 
	denominator = d;

	auto tempNum = numerator;
	auto tempDen = denominator;
	numerator = (numerator / gcd(tempNum, tempDen));
	denominator = (denominator / gcd(tempNum, tempDen));
}



//basic operators
bool operator<(Rational const & a, Rational const & b)
{
	return (a.getNumerator() * b.getDenominator()) < (b.getNumerator() * a.getDenominator());
}
bool operator==(Rational const & a, Rational const & b)
{
	if (a.getNumerator() != b.getNumerator()) return false;
	if (b.getDenominator() != b.getDenominator()) return false;

	return true;
}
bool operator!=(Rational const & a, Rational const & b)
{
	return !(a == b);
}
bool operator>(Rational const & a, Rational const & b)
{
	return b < a;
}
bool operator<=(Rational const & a, Rational const & b)
{
	return !(a > b);
}
bool operator>=(Rational const & a, Rational const & b)
{
	return !(a < b);
}


Rational operator+(Rational const & a, Rational const & b)
{
	Rational rat;
	rat.setNumerator((a.getNumerator()*b.getDenominator()) + (b.getNumerator() * a.getDenominator()));
	rat.setDenominator(a.getDenominator() * b.getDenominator());

	return rat;
}
Rational operator-(Rational const & a, Rational const & b)
{

	Rational rat;
	rat.setNumerator((a.getNumerator()*b.getDenominator()) - (b.getNumerator() * a.getDenominator()));
	rat.setDenominator(a.getDenominator() * b.getDenominator());
	return rat;
}
Rational operator*(Rational const & a, Rational const & b)
{

	Rational rat;
	rat.setNumerator(a.getNumerator() * b.getNumerator());
	rat.setDenominator(a.getDenominator() * b.getDenominator());
	return rat;
}
Rational operator/(Rational const & a, Rational const & b)
{
	Rational rat;
	rat.setNumerator(a.getNumerator() * b.getDenominator());
	rat.setDenominator(a.getDenominator() * b.getNumerator());
	return rat;


}


//iostream operators
std::ostream & operator<<(std::ostream & out, Rational const& a)
{
	out << a.getNumerator() << "/" << a.getDenominator();
	return out;
}
std::istream & operator>>(std::istream & in, Rational & a)
{
	int x, y;
	in >> x;
	std::cout << "/";
	in	>> y;
	a.setNumerator(x);
	a.setDenominator(y);
	return in;
}

int gcd(int a, int b)
{
	if(b == 0)
	{
	        return a;
	}
	else
	{
		return gcd(b, a % b);
	}
}


//Rational Rational::stringToRational(std::string input)
//{
	//Rational r(input.front, input.back);
	//std::cout << r;
	//return r;
//}
