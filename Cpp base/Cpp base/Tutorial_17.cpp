/*

		Functions and their uses (PART 1)

*/

#include <iostream>

// RETURN TYPE, NAME, INPUT PARAMETER(S)

int addTwoNumbers(int a, int b) // FUNCTION HEAD
{
	return a + b;
}

int main()
{
	std::cout << addTwoNumbers(5, 7) << "\n";

	system("PAUSE");
	return 0;
}
