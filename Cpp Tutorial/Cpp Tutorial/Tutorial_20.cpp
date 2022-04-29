/*

		Functions in different files! (PART 4)

*/

#include <iostream>
#include "myMathFunctions.h";

int main()
{
	int sum = add(10, 20);
	int result = substraction(10, 20);
	int product = multiplication(10, 20);

	std::cout << sum << "\n";
	std::cout << result << "\n";
	std::cout << product << "\n";
	

	system("PAUSE");
	return 0;
}
