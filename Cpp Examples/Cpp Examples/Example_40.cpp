#include <iostream>

void expand(int**& arr, int& cap, int nrOfEl)
{
	// Step 1 increase capacity:
	cap *= 2;

	// Step 2 create temp array:
	int** tempArr = new int* [cap];

	// Step 3 initialize temp array:
	for (size_t i = 0; i < cap; i++)
	{
		tempArr[i] = nullptr;
	}

	// Step 4 copy over things from old array:
	for (size_t i = 0; i < nrOfEl; i++)
	{
		tempArr[i] = new int(*arr[i]);
	}

	// Step 5 delete old array:
	for (size_t i = 0; i < nrOfEl; i++)
	{
		delete arr[i];
	}

	delete[] arr;

	// Step 6 point old array to new one
	arr = tempArr;

	std::cout << "Array expanded" << cap << std::endl;
}

void add(int el, int**& arr, int& cap, int& nrOfEl)
{
	if (nrOfEl >= cap)
	{
		expand(arr, cap, nrOfEl);
	}

	arr[nrOfEl++] = new int(el);

	std::cout << "Element added" << std::endl;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int cap = 5;
	int nrOfEl = 0;
	int** arr = new int*[cap];

	// Initialize
	for (size_t i = 0; i < cap; i++)
	{
		arr[i] = nullptr;
	}

	add(5, arr, cap, nrOfEl);
	add(5, arr, cap, nrOfEl);
	add(5, arr, cap, nrOfEl);

	for (size_t i = 0; i < nrOfEl; i++)
	{
		std::cout << i << ": " << arr[i] << " " << *arr[i] << std::endl;
	}

	// Delete
	for (size_t i = 0; i < cap; i++)
	{
		delete arr[i];
	}

	delete[] arr;

	return 0;
}
