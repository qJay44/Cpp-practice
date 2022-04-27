/*

		Functions... Optimization and things to think about (PART 6)

*/

#include <iostream>

// Does a value need to be changed? If not, make it "const", else make it a reference

void func1(int& valueToChange, const int& value)
{

	valueToChange = value;
}

const float& median(const int& a, const int& b, const int& c)
{
	return (a + b + c) / 3.f;
}

int main()
{
	int a = 20;
	int b = 10;

	func1(a, b);

	std::cout << a << "\n";
	std::cout << median(10, 20, 30) << "\n";

	system("PAUSE");
	return 0;
}
