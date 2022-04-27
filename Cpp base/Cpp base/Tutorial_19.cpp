/*

		Function prototypes... How to divide a function into parts (PART 3)

*/

#include <iostream>


// Function PROTOTYPE
// Function HEADER: Return-type, Name, input parameters

void myFunc(); // PROTOTYPE
float myDivisionFunc(float, float); // PROTOTYPE

int main()
{
	myFunc();
	std::cout << myDivisionFunc(10.3, 4) << "\n";

	system("PAUSE");
	return 0;
}

void myFunc() // DEFINITION
{
	std::cout << "my func";
}

float myDivisionFunc(float a, float b) // DEFINITION
{
	if (b == 0) return 0.f;
	return a / b;
}
