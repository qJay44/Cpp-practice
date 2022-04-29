/*

		Class initialization list

*/

#include <iostream>
#include <ctime>

class Dice
{
public:
	Dice(int value);
	virtual ~Dice();

	// Accessors
	const int& getValue() const;

	// Functions
	const int toss() const;

private:
	const int value;
};


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Dice d6(6);
	Dice d16(16);

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << d16.toss() << "\n";
	}

	system("PAUSE");
	return 0;
}

// Class Dice
Dice::Dice(int value)
	: value(value)		// Initializer for class constant member variables and references
{
}

Dice::~Dice()
{
}

const int& Dice::getValue() const
{
	return this->value;
}

const int Dice::toss() const
{
	return rand() % this->value + 1;
}
