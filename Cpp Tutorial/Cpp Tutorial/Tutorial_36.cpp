/*

		Deep copy vs. Shallow copy

*/

#include<iostream>
#include<string>

int main()
{
	int num1 = 10;
	int num2 = 20;

	int* intptr1 = new int(50);
	int* intptr2 = new int(30);

	// Shallow copy
	// intptr1 = intptr2;          Creates memory leak

	// Deep copy (safe)
	*intptr1 = *intptr2;


	num1 = num2;

	std::cout << num1 << "\n";

	delete intptr1;
	delete intptr2;

	return 0;
}
