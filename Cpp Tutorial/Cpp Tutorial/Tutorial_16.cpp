/*

		References, a quick look and examples

*/

#include <iostream>

int main()
{
	int i = 20;
	int k = 30;
	double d = 20.3;

	// Type, reference operator, initial value!
	int& r = i;
	double& dr = d;

	r = k;
	r = 10;

	std::cout << r << "\n";
	std::cout << INT_MAX << "\n";

	system("PAUSE");
	return 0;
}
