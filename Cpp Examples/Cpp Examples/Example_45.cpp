#include <iostream>

class Wheel
{
public:
	Wheel(int inches = 20)
	{
		this->inches = inches;
	};
	~Wheel()
	{

	};

	const int& getInches() const
	{
		return inches;
	}

	void setInches(const int inches)
	{
		this->inches = inches;
	}

private:
	int inches;
};

class Car
{
public:
	Car()
	{
		this->wheelLF = Wheel(22);
		this->wheelRF = Wheel(24);
		this->wheelLR = Wheel(26);
		this->wheelRR = Wheel(28);
	};
	~Car()
	{

	};

	Wheel& getWheel(int index)
	{
		Wheel* wptr = nullptr;
		switch (index)
		{
		case 1:
			wptr = &this->wheelLF;
			break;
		case 2:
			wptr = &this->wheelRF;
			break;
		case 3:
			wptr = &this->wheelLR;
			break;
		case 4:
			wptr = &this->wheelRR;
			break;
		default:
			std::cout << "No wheel above wheel 4" << '\n';
			break;
		}

		return *wptr;
	}

private:
	Wheel wheelLF;
	Wheel wheelRF;
	Wheel wheelLR;
	Wheel wheelRR;
};

int main()
{
	Car car1;
	std::cout << car1.getWheel(1).getInches() << std::endl;
	std::cout << car1.getWheel(2).getInches() << std::endl;
	std::cout << car1.getWheel(3).getInches() << std::endl;
	std::cout << car1.getWheel(4).getInches() << std::endl;

	car1.getWheel(1).setInches(30);
	std::cout << car1.getWheel(1).getInches() << std::endl;

	return 0;
}

