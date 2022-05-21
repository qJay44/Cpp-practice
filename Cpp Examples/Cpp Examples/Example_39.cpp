#include <iostream>

int main()
{
	int cap = 10;
	int nrOrEl = 0;

	int** arr = new int*[cap];

	for (size_t i = 0; i < cap; i++)
	{
		arr[i] = nullptr;
	}

	arr[nrOrEl++] = new int(5);

	for (size_t i = 0; i < nrOrEl; i++)
	{
		std::cout << *arr[i] << std::endl;
	}

	for (size_t i = 0; i < nrOrEl; i++)
	{
		delete arr[i];
	}

	delete[] arr;

	return 0;
}
