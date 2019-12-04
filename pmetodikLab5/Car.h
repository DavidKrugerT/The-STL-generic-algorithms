#pragma once
#include <string>
#include <iostream>


/*
------------------------------------------------------
	Class Car - Creating a Car with name and top speed
------------------------------------------------------
*/
class Car
{
	std::string name;
	double speed;
public:
	Car(std::string, double);		//initializer
	~Car();							//deconstructor
	std::string getName()  { return name; } 
	double getSpeed() const { return speed; }
	friend std::ostream& operator<<(std::ostream& os, Car &rhs); //ostream operator
	friend bool operator==(const Car &lhs, const Car &rhs); //is equal to oprator
	friend bool operator<(const Car &car, double i); //less than Operator
	Car(const Car & rhs) : Car(rhs.name, rhs.speed) {}; //Copy Constructor
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
