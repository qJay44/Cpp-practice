/*

		Classes in classes

*/

#include <iostream>
#include <string>

class Car
{
public:
	Car() :
		tl(1), tr(2), bl(3), br(4)
	{};

	~Car() {};

	void printWheels()
	{
		std::cout << "Wheels: \n"
			<< "Top left: " << tl.pressure << '\n'
			<< "Top right: " << tr.pressure << '\n'
			<< "Bottom left: " << bl.pressure << '\n'
			<< "Bottom right: " << br.pressure << '\n'
			<< '\n';
	}

private:

	class Wheel
	{
	public:
		int pressure;

		Wheel(int pressure) { this->pressure = pressure; };
		~Wheel() {};
	};

	Wheel tl;
	Wheel tr;
	Wheel bl;
	Wheel br;

};

int main()
{
	Car car1;

	car1.printWheels();

	return 0;
}
