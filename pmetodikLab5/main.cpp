#include "Car.h"
#include <iostream>		//cout
#include <vector>		//vector
#include <algorithm>	//for each adje find_if
#include <functional>
#include <string>

struct adja
{
	bool operator()(const Car &lhs, const Car &rhs){
		return lhs == rhs;
	}
};

struct findOp
{
	int n;
	findOp(int n) : n(n) {}
		bool operator()(const Car&car) {
			return car < n;
		}
};

struct myPrint  {
	std::string str;
	myPrint(std::string str = "") : str(str) {};
	void operator()(Car& car) const{
		std::cout << str + ": "<< car << std::endl;
	}
};

void print(Car & car) {
	std::cout << car;
}

struct printClass {
	static void print(Car&car) {
		std::cout << car;
	}
};

int main() {

	std::vector<Car> cars;
	
	std::string models[6] = { "Volvo", "Volvo", "BMW", "Saab", "Zeat", "Mercedes" };
	double speeds[6] = { 50, 50, 100, 150, 200, 220 };

	for (unsigned int a = 0; a < sizeof(models) / sizeof(models[0]); a = a + 1){
		Car f(models[a], speeds[a]);
		cars.push_back(f);
	}
	
	// 1)
	std::for_each(cars.begin(), cars.end(), myPrint("cars"));
	std::cout << std::endl;

	// 2)
	myPrint("find if less than 150")(*std::find_if(cars.begin(), cars.end(), findOp(150.f)));
	std::cout << std::endl;

	// 3) 
	myPrint("adjacent cars")(*std::adjacent_find(cars.begin(), cars.end(), adja()));
	std::cout << std::endl;

	system("PAUSE");
	return EXIT_SUCCESS;
}

