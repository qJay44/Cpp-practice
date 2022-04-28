/*

		Pointers introduction

*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int* intPtr = nullptr;

	intPtr = &a; // pointer is being assigned the address to the variable "a"

	cout << a << endl;
	cout << &a << endl;
	cout << intPtr << endl;
	cout << *intPtr << endl; // Dereference

	system("PAUSE");
	return 0;
}
