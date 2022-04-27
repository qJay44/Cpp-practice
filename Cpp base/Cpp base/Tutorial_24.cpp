/*

		Functions and Array/Vector as parameters
		
*/

#include <iostream>
#include <vector>

void printArr(const int& size, const int arr[])
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\n";
	}
}

void replaceArr(const int& size, int* arr, const int& value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

void printVector(const std::vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\n";
	}
}

int main()
{
	const int arrSize = 10;
	int arr[arrSize];
	std::vector<int> myVec;

	for (size_t i = 0; i < arrSize; i++)
	{
		arr[i] = i;
	}

	for (size_t i = 0; i < arrSize; i++)
	{
		myVec.push_back(i);
	}

	replaceArr(arrSize, arr, 220);
	replaceArr(myVec.size(), myVec.data(), 2320);

	printArr(arrSize, arr);
	printArr(myVec.size(), myVec.data());

	printVector(myVec);

	system("PAUSE");
	return 0;
}
