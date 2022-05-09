/*

		Passing dynamic arrays into functions using pointer-reference

*/

#include <iostream>

void func(int*& intArr)
{
	delete[] intArr;
	intArr = new int[20];

	for (size_t i = 0; i < 20; i++)
	{
		intArr[i] = 10;
	}
}

int main()
{
	int* intArr = new int[10];

	func(intArr);

	for (size_t i = 0; i < 20; i++)
	{
		std::cout << i << ": " << intArr[i] << '\n';
	}

	delete[] intArr;

	return 0;
}
