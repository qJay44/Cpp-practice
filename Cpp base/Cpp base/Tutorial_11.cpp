#include <iostream>
#include <fstream>

/*

	C++ Tutorial | Part 11 | Output to FILE and tips!

*/

// OUTPUT TO A FILE
// IF FILE DOES NOT EXITST WITH A CERTAIN NAME, IT WILL BE CREATED
// TEXT OR BINARY
// FILE-TYPE DOES NOT REALLY MATTER, IT WILL BE TEXT ANYWAY 

int main()
{
	std::string data = "this is data\nNew line";
	int num = 35;
	double someDouble = 2.35;

	std::string fileName = "myFile.txt";

	std::ofstream outFile;
	outFile.open(fileName.c_str());

	if (outFile.is_open())
	{
		outFile << data
			<< "\n"
			<< num
			<< "\n"
			<< someDouble;
	}

	outFile.close();
	
	system("PAUSE");
	return 0;
}