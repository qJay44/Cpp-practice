/*

		Class accessors and modifiers (PART 2)

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

public:
	// default constructor
	Person()
	{
		this->name = "none";
		this->age = -1;
		this->address = "none";
		this->profession = "none";
	}

	// constructor
	Person(std::string name, int age, std::string address, std::string profession)
	{
		this->name = name;
		this->age = age;
		this->address = address;
		this->profession = profession;
	}

	// destructor
	~Person()
	{
	}

	// accessors

	inline const std::string& getName() const { return this->name; }
	inline const int& getAge() const { return this->age; }
	inline const std::string& getAddress() const { return this->address; }
	inline const std::string& getProfession() const { return this->profession; }

	// modifiers

	inline void setName(const std::string& name) { this->name = name; }
	inline void setAge(const int& age) { this->age = age; }
	inline void setAddress(const std::string& address) { this->address = address; }
	inline void setProfession(const std::string& profession) { this->profession = profession; }

	// function
	const std::string toString() const
	{
		std::string finalString = "";
		finalString =
			"Name: "	    + this->name				 + " | " +
			"Age: "		    + std::to_string(this->age)  + " | " +
			"Address: "	    + this->address				 + " | " +
			"Profession: "  + this->profession			 + " | " + "\n";

		return finalString;
	}
};

int main()
{
	Person p1("testName", 11, "Somewhere 34", "testProfession");
	Person p2;

	std::cout << p1.getName() << "\n";
	std::cout << p2.getName() << "\n";

	p1.setName("Daniel");
	std::cout << p1.getName() << "\n";

	std::cout << p1.toString() << "\n";

	system("PAUSE");
	return 0;
}
