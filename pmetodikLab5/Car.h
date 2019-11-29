#pragma once
#include <string>

class Car
{
	std::string name;
	double speed;
public:

	Car(std::string, double);
	~Car();
	std::string getName() { return name; }
	double getSpeed() { return speed; }

};

Car::Car(std::string name, double speed) : name(name), speed(speed)
{
}

Car::~Car()
{
}
