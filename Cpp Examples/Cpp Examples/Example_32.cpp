#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));

	const int arrSize = 10;
	int statArr[arrSize];
	int* dynamicArr = new int[arrSize];

	for (size_t i = 0; i < arrSize; i++)
	{
		statArr[i] = rand() % 10 + 1;
		dynamicArr[i] = rand() % 10 + 1;

		std::cout << "Static:	" << statArr[i] << '\n';
		std::cout << "Dynamic:	" << statArr[i] << '\n';
	}

	delete[] dynamicArr;

	return 0;
}
