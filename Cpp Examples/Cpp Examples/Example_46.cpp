#include <iostream>
#include <ctime>

class Dice
{
public:
	Dice(int maxValue = 4)
	{
		this->maxValue = maxValue;
	}

	~Dice(){};

	int toss() const
	{
		return rand() % this->maxValue;
	}

	const int& getMaxValue() const
	{
		return this->maxValue;
	}

private:
	int maxValue;
};

void mainMenu(int& choice, Dice** diceArr, const int& cap, int& nrOfDice)
{
	int totalValue = 0;
	int maxValue = 0;

	switch (choice)
	{
	// Add dice
	case 1:
		std::cout << "Input max value for dice: ";
		std::cin >> maxValue;

		if (nrOfDice < cap)
		{
			diceArr[nrOfDice++] = new Dice();
		}
		break;

	// Get max value for all dice
	case 2:
		for (size_t i = 0; i < nrOfDice; i++)
		{
			std::cout << i << ": " << diceArr[i]->getMaxValue() << '\n';
		}
		break;

	// Toss all dice and get the total
	case 3:
		for (size_t i = 0; i < nrOfDice; i++)
		{
			totalValue += diceArr[i]->toss();
		}
		std::cout << "Total value of all dice: " << totalValue << '\n';

		break;

	default:
		std::cout << "Wrong input" << std::endl;
		break;
	}

	std::cout << '\n';
	std::cout << "Menu" << '\n';
	std::cout << "1: Add dice" << '\n';
	std::cout << "2: Show dice" << '\n';
	std::cout << "3: Toss all dice" << '\n' << '\n';
	std::cout << "Choice: ";
	std::cin >> choice;

}

int main()
{
	srand(time(0));

	int cap = 10;
	int nrOfDice = 0;
	int choice = 0;
	Dice** diceArr = new Dice * [cap];

	mainMenu(choice, diceArr, cap, nrOfDice);

	while (choice > 0)
	{
		mainMenu(choice, diceArr, cap, nrOfDice);
	}

	// Delete final
	for (size_t i = 0; i < nrOfDice; i++)
	{
		delete diceArr[i];
	}

	delete[] diceArr;

	return 0;
}
