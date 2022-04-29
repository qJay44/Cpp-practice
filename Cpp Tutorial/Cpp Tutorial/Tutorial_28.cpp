/*

		Class functions and defining them outside! (PART 3)

*/

#include <iostream>
#include <string>
#include <vector>

class MyClass
{
private:
	std::vector<std::string> myStrings;
public:
	MyClass();

	// Accesssors
	const std::vector<std::string>& getMyStrings() const;

	// Modifiers

	// Functions
	void add(const std::string str);
	const std::string toString() const;
};

// MyClass function definitions

MyClass::MyClass()
{
	this->myStrings.push_back("Hi I am nr 1");
}

const std::vector<std::string>& MyClass::getMyStrings() const
{
	return this->myStrings;
}

void MyClass::add(const std::string str)
{
	this->myStrings.push_back(str);
}

const std::string MyClass::toString() const
{
	std::string finish = "";
	for (size_t i = 0; i < this->myStrings.size(); i++)
	{
		finish += std::to_string(i) + ": " + this->myStrings[i] + "\n";
	}

	return finish;
}

int main()
{
	MyClass obj;

	obj.add("Another string");

	for (size_t i = 0; i < 10; i++)
	{
		obj.add("Another str" + std::to_string(i));
	}

	std::cout << obj.toString() << "\n";

	system("PAUSE");
	return 0;
}
