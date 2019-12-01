#pragma once
#include <string>
#include <iostream>



class Car
{
	std::string name;
	double speed;
public:

	Car(std::string, double);
	~Car();
	std::string getName() { return name; }
	double getSpeed() { return speed; }
	friend std::ostream& operator<<(std::ostream& os, Car &rhs);
	friend bool operator==(const Car &lhs, const Car &rhs);

	
};
// lata tjockis gör en egen fil, skoja
Car::Car(std::string name, double speed) : name(name), speed(speed)
{
}

Car::~Car()
{
}

std::ostream & operator<<(std::ostream & os, Car & rhs)
{
	os << rhs.getName() << rhs.getSpeed();
	return os;
}

bool operator==(const Car & lhs, const Car & rhs)
{
	if (lhs.name == rhs.name && lhs.speed == rhs.speed)
	{
		return true;
	}
	return false;
}