/*

		Functions and reference parameters (PART 2)

*/

#include <iostream>
#include <string>

// REFERENCE PARAMETERS
// PASS BY VALUE
// PASS BY REFERENCE

void changeName_VALUE(std::string name) // PASS BY VALUE
{
	/*
	
		Function will change the "name" variable.

	*/

	name = "value";
}

void changeName_REF(std::string &nameToChange, std::string name) // PASS BY REFERENCE
{
	/*

		Function will change the "name" variable (by reference).

	*/

	nameToChange = name;
}

int main()
{
	std::string characterName = "test01";

	changeName_VALUE(characterName);
	changeName_REF(characterName, "EXAMPLE");

	std::cout << characterName << "\n";

	system("PAUSE");
	return 0;
}
