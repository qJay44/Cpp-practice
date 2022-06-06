#include <iostream>

using namespace std;

class Wheel
{
public:
	Wheel(int size = 20)
		: size(size)
	{
	}
	~Wheel(){};

	const int getSize() const
	{
		return this->size;
	}


private:
	int size;

};

class Truck
{
public:
	Truck()
		: wheelLF(26), wheelRF(26), wheelLR(26), wheelRR(26)
	{
		cout << wheelLF.getSize() << '\n';
		cout << wheelRF.getSize() << '\n';
	}

	~Truck(){};

private:
	Wheel wheelLF;
	Wheel wheelRF;
	Wheel wheelLR;
	Wheel wheelRR;
};

int main()
{
	Truck truck;

	return 0;
}
