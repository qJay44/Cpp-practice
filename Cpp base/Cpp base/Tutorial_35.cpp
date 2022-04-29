/*

		 Static variables and functions, in and outside classes

*/

#include<iostream>
#include<string>
#include"Dice.h"


class Person
{
private:
	std::string name;
	int age;
	int id;

	// Static variables
	static int ID;

public:
	Person(std::string name = "EMPTY", int age = -1)
	{
		this->name = name;
		this->age = age;

		Person::ID++;
		this->id = Person::ID;
	}

	~Person() {}

	// Accessors

	// Functions

	// Static functions
	int getID()
	{
		return this->id;
	}

	static int getStaticID()
	{
		return Person::ID;
	}
};

// Initialize static variables for class "Person"
int Person::ID = 0;

// Functions
static void print(int i)
{
	std::cout << "Hello World" << i << '\n';
}

static void print(char c)
{
	std::cout << "Hello World" << c << '\n';
}

// Main
int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		static int number = 20;
		number++;

		std::cout << number << '\n';
	}


	print(20);
	print('f');

	Person person1;
	std::cout << person1.getID() << '\n';

	Person person2;
	std::cout << person2.getID() << '\n';

	Person person3;
	std::cout << person3.getID() << '\n';

	std::cout << Person::getStaticID() << '\n';
	return 0;
}
