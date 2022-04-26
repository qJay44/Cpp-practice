#include <iostream>
#include <fstream>
#include <string>

int main()
{
	const char* fileName = "Files/myFile.txt";

	std::ifstream inFile(fileName);

	std::string line = "";
	char c = ' ';
	int nrOfAs = 0;

	if (inFile.is_open())
	{
		// Get all lines
		while (std::getline(inFile, line))
		{
			std::cout << line << "\n";
		}

		// reseting the eof state (back to the start)
		inFile.clear();
		inFile.seekg(0, std::ios::beg);
		std::cout << "\n";

		// Get all characters
		while (inFile.get(c))
		{
			std::cout << c;
		}

		// reseting the eof state (back to the start)
		inFile.clear();
		inFile.seekg(0, std::ios::beg);
		std::cout << "\n";

		std::string name = "";
		int age = 0;
		std::string bloodType = "";
		std::string street = "";
		std::string catName = "";
		double height = 0.0f;

		// Read file as data file
		while (!inFile.eof())
		{
			std::getline(inFile, name);
			inFile >> age;
			inFile.ignore();
			std::getline(inFile, bloodType);
			std::getline(inFile, street);
			std::getline(inFile, catName);
			inFile >> height;
			inFile.ignore();
		}

		std::cout << name << "\n" << age << "\n" << bloodType << "\n" << street << "\n" << catName << "\n" << height << "\n\n";

	}
	else std::cout << "Could not open the file: " << fileName << "\n";

	inFile.close();

	system("PAUSE");
	return 0;
}
