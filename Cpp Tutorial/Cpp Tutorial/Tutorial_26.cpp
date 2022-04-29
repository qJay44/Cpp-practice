/*

		Class intro! Member variables, constructor and destructor (PART 1)

*/

#include <iostream>
#include <string>
#include <vector>

class Person
{
private:
	// variables

	std::string name;
	int age;
	std::string address;
	std::string profession;

	// functions

public:
	Person()
	{
		std::cout << "default constructor" << "\n";

		this->name = "none";
		this->age = -1;
		this->address = "none";
		this->profession = "none";
	}

	Person(std::string name, int age, std::string address, std::string profession)
	{
		std::cout << "constructor" << "\n";

		this->name = name;
		this->age = age;
		this->address = address;
		this->profession = profession;
	}

	~Person()
	{
		std::cout << "destructor" << "\n";
	}
};

int main()
{
	Person p1("testName", 11, "Somewhere 34", "testProfession");
	Person p2;

	std::cout << "end" << "\n";

	system("PAUSE");
	return 0;
}
