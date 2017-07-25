#include <string>
#include <iostream>
#include <vector>

class Animal
{
public:
	Animal(std::string n):name(n){}
	std::string getName() { return name; }
	virtual std::string speak()=0;
private:
	std::string name;
};

class Dog : public Animal
{
public:
	Dog(std::string n):Animal(n){}
	std::string speak() override { return "Woof"; }
};

class Poodle : public Dog
{
public:
	Poodle() :Dog("Fluffy") {}
	std::string speak() override { return "Grrr"; }
};

class Cat : public Animal
{
public:
	Cat(std::string n):Animal(n){}
	std::string speak() override { return "Meow"; }
};

int main()
{
	Dog d("Fido");

	std::cout << d.getName() << std::endl;
	std::cout << d.speak() << std::endl;

	Poodle p;

	std::cout << p.getName() << std::endl;
	std::cout << p.speak() << std::endl;

	Cat c("Mr Scraggles");

	std::cout << c.getName() << std::endl;
	std::cout << c.speak() << std::endl;

	std::vector<Animal*> a;
	a.push_back(&d);
	a.push_back(&c);
	a.push_back(&p);

	for (auto&& Animal : a)
	{
		std::cout << Animal->getName() << " Says " << Animal->speak() << std::endl;
	}


	char dummy;
	std::cin >> dummy;
}
