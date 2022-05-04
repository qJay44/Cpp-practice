/*

		Unary and Binary operator overloading

*/

#include<iostream>
#include<cstdlib>
#include<string>

class Card
{
public:
	Card(int value, std::string name)
	{
		this->value = value;
		this->name = name;
	}
	~Card() {};

	const Card operator-()
	{
		Card temp(-this->value, this->name + "-");

		return temp;
	}

	const Card operator+(const Card& card)
	{
		Card temp(this->value + card.value, this->name + " + " + card.name);

		return temp;
	}

	const Card operator*(const int multiply)
	{
		this->value *= multiply;
		this->name += "*2";
		Card temp(this->value, this->name);

		return temp;
	}

	inline const int& getValue() const { return this->value; }
	inline const std::string& getName() const { return this->name; }

private:
	std::string name;
	int value;
};

int main()
{
	Card c1(5, "Bad card");
	Card c2(34, "Good card");

	Card c3 = (c1 + c2);
	Card c4(c3 * 2);

	std::cout << c4.getValue() << " " << c3.getName() << '\n';

	return 0;
}
