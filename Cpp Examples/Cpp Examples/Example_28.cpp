/*

		Pointers as Function parameters

*/

#include<iostream>

using namespace std;

void func(int* a, int& b)
{
	*a = 10;
	b = *a;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
}

int main()
{
	int numberPtr = 0;
	int numberRef = 0;

	func(&numberPtr, numberRef);

	int* p = &numberPtr;

	return 0;
}
