/*

		Dynamic Arrays using Pointers (Detailed long explanation)

*/

#include <iostream>

int main()
{
	int capacity = 20;
	int nrOfElements = 0;
	int* intArr = new int[capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		intArr[i] = 0;
	}

	while (nrOfElements < capacity)
	{
		intArr[nrOfElements++] = 5;
	}

	for (size_t i = 0; i < nrOfElements; i++)
	{
		std::cout << i << ": " << intArr[i] << '\n';
	}

	// Expansion begin

	capacity *= 2;
	int* tempArr = new int[capacity]; //Allocation

	for (size_t i = 0; i < nrOfElements; i++)
	{
		tempArr[i] = intArr[i];
	}

	delete[] intArr; // Deallocation

	intArr = tempArr;

	// Expansion end

	while (nrOfElements < capacity)
	{
		intArr[nrOfElements++] = 10;
	}

	for (size_t i = 0; i < nrOfElements; i++)
	{
		std::cout << i << ": " << intArr[i] << '\n';
	}

	return 0;
}
