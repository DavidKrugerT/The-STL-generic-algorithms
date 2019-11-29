#pragma once
#include <string>
class Elementary
{
	std::string school;
	double grade;
public:
	Elementary(std::string, double);
	~Elementary();
	std::string getSchool() { return school; }
	double getGrade() { return grade; }

};

Elementary::Elementary(std::string x, double y) : school(x), grade(y)
{
}

Elementary::~Elementary()
{
}