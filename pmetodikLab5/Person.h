#pragma once
#include <string>
class Person
{
	std::string name;
	double age;
public:
	Person(std::string, double);
	~Person();
	std::string getName() { return name;}
	double getAge() { return age; }

};

Person::Person(std::string x, double y) : name(x), age(y)
{
}

Person::~Person()
{
}