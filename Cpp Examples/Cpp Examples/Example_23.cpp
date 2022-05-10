#include <iostream>

void func(int a, int& b)
{
	a = 10;
	b = 20;
}

int main()
{
	const int c = 20;
	int a, b = 0;

	func(a, b);
	func(c, b);
	func(20, b);

	return 0;
}
