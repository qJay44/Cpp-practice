/*

		Function Overloading (PART 5)

*/


#include <iostream>
#include "myMathFunctions.h"

// FUNCTION OVERLOADING
// Function header = function signature
// FUNCTION OVERRIDING (OVERSHADOWING)

int main()
{
	std::cout << add(1, 2) << "\n";
	std::cout << add(10.3f, 2.f) << "\n";

	system("PAUSE");
	return 0;
}
