#pragma once
#include <string>
class Particle
{
	std::string name;
	double mass;
public:
	Particle(std::string, double);
	~Particle();
	std::string getName() { return name; }
	double getMass() { return mass; }
};

Particle::Particle(std::string x, double y) : name(x), mass(y) 
{

}

Particle::~Particle()
{
}

