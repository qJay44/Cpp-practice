#include <iostream>

int func(int i)
{
	if (i > 10)
	{
		throw("Larger than 10");
	}

	return i;
}

int main()
{
	try
	{
		func(11);
	}
	catch (const char* c)
	{
		std::cout << c << std::endl;
	}

	system("PAUSE");
	return 0;
}
