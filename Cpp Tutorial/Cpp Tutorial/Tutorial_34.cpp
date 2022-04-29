/*

		Faster loops! Release/Debug and C++ 11 features

*/

#include<iostream>
#include<ctime>
#include<vector>

int main()
{
	// Initialize
	std::vector<int> intArr(100000, 1);
	int sum = 0;


	// Normal loop
	int startTime = clock();

	for (size_t i = 0; i < intArr.size(); i++)
	{
		sum += intArr[i];
	}

	int endTime = clock();

	float time1 = (endTime - startTime) / double(CLOCKS_PER_SEC);
	
	sum = 0;

	// foreach loop

	startTime = clock();

	for (auto& i : intArr)
	{
		sum += i;
	}

	endTime = clock();

	float time2 = (endTime - startTime) / double(CLOCKS_PER_SEC);

	sum = 0;

	// Iterator range loop

	startTime = clock();

	const std::vector<int>::const_iterator end = cend(intArr); // iterator caching
	for (std::vector<int>::const_iterator it = cbegin(intArr); it != end; ++it)
	{
		sum += *it;
	}

	endTime = clock();

	float time3 = (endTime - startTime) / double(CLOCKS_PER_SEC);

	std::cout << "Normal loop: " << time1 << '\n';
	std::cout << "Foreach loop: " << time2 << '\n';
	std::cout << "Iterator range loop: " << time3 << '\n';
	std::cout << "Sum: " << sum << '\n';

	return 0;
}
