#pragma once

#include <string>

class Dice
{
public:
	Dice(const int value = 6, const std::string color = "Black");
	~Dice();

	// Accessors
	inline const int& getValue() const { return this->value; };
	inline const std::string& getColor() const { return this->color; }

	// Modifiers
	inline void setColor(const std::string color) { this->color = color; }

	// Functions
	const int toss() const;
	static int getStaticID();

private:
	const int value;
	std::string color;

	// Static variables
	static int ID;


};
