/*

		Reference vs Pointer in detail

*/

#include <iostream>

int main()
{
	int a = 10;
	int b = 20;

	int& r = a; // "r" became "a"
	int* p1 = &a;
	int* p2 = &b;

	//std::cout << r << '\n';
	//r = b; // "r" or "a" value is changed to 20!
	//std::cout << r << '\n';
	//std::cout << a << '\n';

	std::cout << p1 << " " << *p1 << '\n';
	std::cout << p2 << " " << *p2 << '\n';

	p1 = p2; // "p1" is also pointing to "b"

	std::cout << p1 << " " << *p1 << '\n';
	std::cout << p2 << " " << *p2 << '\n';

	p1 = &a;
	*p1 = *p2; // "a" gets value of "b"

	std::cout << p1 << " " << *p1 << '\n';
	std::cout << p2 << " " << *p2 << '\n';

	return 0;
}
