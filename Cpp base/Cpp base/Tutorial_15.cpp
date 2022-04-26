#include <iostream>
#include <string>
#include <vector>

/*

		Vector container class tutorial and examples of use

*/

int main()
{
	std::vector<int> myIntVec;
	std::vector<std::string> myStrVec;

	myIntVec.push_back(13);
	myIntVec.push_back(23);
	myIntVec.push_back(33);

	myStrVec.push_back("name");
	myStrVec.push_back("surname");

	myIntVec.erase(myIntVec.begin() + 0);
	myIntVec.erase(myIntVec.end() - 1);

	myIntVec.clear();

	for (size_t i = 0; i < myIntVec.size(); i++)
	{
		std::cout << myIntVec[i] << " ";
	}

	for (size_t i = 0; i < myStrVec.size(); i++)
	{
		std::cout << myStrVec[i] << " ";
	}

	std::cout << "\n";

	system("PAUSE");
	return 0;
}
