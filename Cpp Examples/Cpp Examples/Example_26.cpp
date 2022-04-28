/*

		Memory allocation intro with Pointers

*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name = "john";
	string* strPtr = nullptr;

	strPtr = new string; // Allocation
	// strPtr = &name; // Memory leak

	*strPtr = "Bob"; // Dereference
	cout << strPtr << " " << *strPtr << endl;

	delete strPtr; // Deallocate memory

	strPtr = &name;

	cout << strPtr << " " << *strPtr << endl;

	return 0;
}
