/*

		Pointers and Arrays

*/

#include <iostream>
#include <string>

int main()
{
	const int arrSize = 5;
	std::string stringArr[arrSize] = { "Red", "Green", "Blue", "Violet", "Yellow" };
	std::string* sPtr = nullptr;

	sPtr = &stringArr[0];
	sPtr++;

	std::cout << sPtr << " " << *sPtr << '\n';

	return 0;
}
