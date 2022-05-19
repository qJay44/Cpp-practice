#include <iostream>
#include <string>

using namespace std;

void initialize(int, const int&, string*);
void expand(string*&, int&, const int&);
void addElement(string, string*&, int&, int&);
void printAll(const int&, string*);
string getAt(int, string*, const int&);
void menu(int&, string*&, int&, int&);

int main()
{
	// Array
	int cap = 10;
	int nrOfEl = 0;
	string* arr = new string[cap];

	// Menu
	int choice = 0;

	menu(choice, arr, nrOfEl, cap);

	while (choice > 0)
	{
		menu(choice, arr, nrOfEl, cap);
	}




	delete[] arr;

	return 0;
}

void initialize(int from, const int& cap, string* arr)
{
	for (size_t i = from; i < cap; i++) arr[i] = "";
}

void expand(string*& arr, int& cap, const int&nrOfEl)
{
	cap *= 2;
	string* tempArr = new string[cap];

	for (size_t i = 0; i < nrOfEl; i++) tempArr[i] = arr[i];

	delete[] arr;
	arr = tempArr;

	initialize(nrOfEl, cap, arr);

	cout << "Array expanded" << endl;
}

void addElement(string el, string*& arr, int& nrOfEl, int& cap)
{
	if (nrOfEl >= cap) expand(arr, cap, nrOfEl);
	arr[nrOfEl++] = el;

	cout << "Element added" << endl;
}

void printAll(const int& nrOfEl, string* arr)
{
	for (size_t i = 0; i < nrOfEl; i++) cout << i << ": " << arr[i] << endl;
}

string getAt(int index, string* arr, const int& nrOfEl)
{
	string data = "";

	if (index >= nrOfEl || index < 0) throw("Out of bounds");
	else data = arr[index];

	return data;
}

void menu(int& choice, string*& arr, int& nrOfEl, int& cap)
{
	cout << "0: Quit" << endl;
	cout << "1: Add" << endl;
	cout << "2: Print" << endl;
	cout << endl;

	cout << "Enter a choice: " << endl;
	cin >> choice;
	cout << endl;

	string name = "";

	switch (choice)
	{
	case 0: break;
	case 1:
		cout << "Name of a car: ";
		cin.ignore();
		getline(cin, name);
		addElement(name, arr, nrOfEl, cap);
		break;

	case 2:
		printAll(nrOfEl, arr);
		cout << endl;
		break;

	default:
		cout << "Wrond choice" << endl;
	}
}
