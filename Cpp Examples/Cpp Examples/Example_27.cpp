/*

		Detect memory leaks using flag

*/

#include<iostream>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* intPtr = new int;
	*intPtr = 10;

	cout << intPtr << " " << *intPtr << endl;

	delete intPtr;

	return 0;
}
