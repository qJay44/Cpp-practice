#include <iostream>

template<typename T>
T add(T a, T b)
{
	return a + b;
}

template<typename T>
T sub(T a, T b)
{
	return a - b;
}

int main()
{
	std::cout << sub(3, 4) << std::endl;

	return 0;
}
