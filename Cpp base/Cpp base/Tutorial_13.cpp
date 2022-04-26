#include <iostream>
#include <string>

/*

		Array tutorial, tips, errors and examples

*/

int main()
{
	const int arraySize = 4;
	const int arraySizeStrings = 3;

	int myArray[arraySize] = { 10, 20, 40, 32};
	std::string myStringArray[arraySizeStrings] = { "NONE" };

	for (size_t i = 0; i < arraySize; i++)
	{
		std::cout << i << " " << myArray[i] << "\n";
	}

	std::cout << "\n";

	for (size_t i = 0; i < arraySizeStrings; i++)
	{
		std::cout << i << " Enter str: ";
		std::getline(std::cin, myStringArray[i]);
	}

	for (size_t i = 0; i < arraySizeStrings; i++)
	{
		std::cout << i << myStringArray[i] << "\n";
	}

	system("PAUSE");
	return 0;
}
