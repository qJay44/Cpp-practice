#include <iostream>
#include <vector>

void func(std::vector<char>& a)
{
	a.push_back('E');
	a.push_back('F');
	a.push_back('G');
	a.push_back('H');
}

int main()
{
	std::vector<char> myVec;
	myVec.push_back('A');
	myVec.push_back('B');
	myVec.push_back('C');
	myVec.push_back('D');

	func(myVec);

	for (size_t i = 0; i < myVec.size(); i++)
	{
		std::cout << i << ": " << myVec[i] << std::endl;
	}

	return 0;
}
