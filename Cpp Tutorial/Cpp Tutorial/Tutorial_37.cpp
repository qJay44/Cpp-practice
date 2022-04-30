/*

		Class copy constructor

*/

#include<iostream>
#include<cstdlib>
#include<string>

class Car
{
public:
	Car(std::string name, int horsePower);
	Car(const Car& obj); // Copy constructor

	~Car();

	const std::string& getName() const;
	const int& getHorsePower() const;

private:
	std::string name;
	int* horsePower;
};

int main()
{
	Car car1("Audi A4", 2000);
	Car car2(car1); // Copy constructor
	//Car car2 = car1; // Copy constructor

	//car2 = car1; // Assignment operator

	std::cout << car1.getName() << " " << car1.getHorsePower() << '\n';
	std::cout << car2.getName() << " " << car2.getHorsePower() << '\n';

	return 0;
}

Car::Car(std::string name, int horsePower)
{
	this->name = name;
	this->horsePower = new int(horsePower);
}

Car::Car(const Car& obj)
{
	this->name = obj.name;
	this->horsePower = new int(*obj.horsePower);
}

Car::~Car()
{
	delete this->horsePower;
}

const std::string& Car::getName() const
{
	return this->name;
}

const int& Car::getHorsePower() const
{
	return *this->horsePower;
}
