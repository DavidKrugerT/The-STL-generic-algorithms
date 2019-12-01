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
	std::string getName()  { return name; } 
	double getSpeed() const { return speed; }
	friend std::ostream& operator<<(std::ostream& os, Car &rhs);
	friend bool operator==(const Car &lhs, const Car &rhs);
	friend bool operator<(const Car &car, double i);

	
};

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
	return lhs.name == rhs.name && lhs.speed == rhs.speed;
}

inline bool operator<(const Car & car, double i)
{
	return car.getSpeed() < i;
}
