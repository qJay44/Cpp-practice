/*

		Working dynamic array using functions

*/

#include <iostream>

void initialize(int from, const int& cap, int* arr);
void expand(int*& arr, int& cap, const int& nrOfEl);
void addElement(int el, int*& arr, int& nrOfEl, int& cap);
void getAt(int index, int* arr, const int& nrOfEl);

void printAll(int* arr, const int& nrOfEl)
{
	for (size_t i = 0; i < nrOfEl; i++)
	{
		std::cout << i << ": " << arr[i] << std::endl;
	}
}

int main()
{
	int cap = 2; // Max cap for array
	int nrOfEl = 0; // Number of valid elements in array
	int* arr = new int[cap];

	initialize(0, cap, arr);
	addElement(100, arr, nrOfEl, cap);
	addElement(1000, arr, nrOfEl, cap);
	addElement(100, arr, nrOfEl, cap);
	addElement(100, arr, nrOfEl, cap);
	addElement(100, arr, nrOfEl, cap);
	printAll(arr, nrOfEl);

	getAt(-2, arr, nrOfEl);

	return 0;
}

void initialize(int from, const int& cap, int* arr)
{
	for (size_t i = from; i < cap; i++)
	{
		arr[i] = 0;
	}
}

void expand(int*& arr, int& cap, const int& nrOfEl)
{
	// 1: Increase max cap
	cap *= 2;

	// 2: Create temp array
	int* tempArr = new int[cap];

	// 3: Copy over valid values form old array
	for (size_t i = 0; i < nrOfEl; i++)
	{
		tempArr[i] = arr[i];
	}

	// 4: Delete old array memory
	delete[] arr;

	// 5: Point old array pointer to new array location
	arr = tempArr;

	// 6: Init a new array
	initialize(nrOfEl, cap, arr);

	std::cout << "Array expanded, new size: " << cap << std::endl;
}

void addElement(int el, int*& arr, int& nrOfEl, int& cap)
{
	if (nrOfEl >= cap)
	{
		expand(arr, cap, nrOfEl);
	}

	arr[nrOfEl++] = el;
}

void getAt(int index, int* arr, const int& nrOfEl)
{
	if (index >= nrOfEl || index < 0)
	{
		std::cout << "OUT OF BOUNDS" << std::endl;
	}

	else std::cout << arr[index] << std::endl;
}
