#include "Car.h"
#include <iostream>		//cout
#include <vector>		//vector
#include <algorithm>	//for each adje find_if a
#include <functional>
#include <string>
#include <numeric>

/*-----------------------------------------
	structs: Compare - findOp - myPrint - MyBinOp
------------------------------------------*/

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

struct MyBinOp
{
	double operator()(const Car & lhs, const Car & rhs) const{
		return lhs.getSpeed() + rhs.getSpeed();
	};
};


int main() {

	std::vector<Car> cars;
	

	// Arrays
	std::string models[6] = { "Volvo ", "Volvo ", "BMW ", "Saab ", "Zeat ", "Mercedes " };
	double speeds[6] = {50, 50, 100, 150, 200, 220};

	
	// Array with class Car 
	Car carss[] = { Car("Volvo ", speeds[0]), Car(models[1], speeds[1]), Car(models[2], speeds[2]), 
		Car(models[3], speeds[3]), Car(models[4], speeds[4]), Car(models[5], speeds[5])};

	//vector class Car
	for (unsigned int a = 0; a < sizeof(models) / sizeof(models[0]); a = a + 1){
		Car f(models[a], speeds[a]);
		cars.push_back(f);
	}
	
	/*------------------------------------------
		std::for_each - Krav: 
	------------------------------------------*/
	std::for_each(cars.begin(), cars.end(), myPrint("cars"));
	std::cout << std::endl;

	/*------------------------------------------
		std::find_if - Krav: 
	------------------------------------------*/
	myPrint("find if less than 150")(*std::find_if(cars.begin(), cars.end(), findOp(150.f)));
	std::cout << std::endl;

	/*------------------------------------------
		std::ajdacent_find - Krav:
	------------------------------------------*/
	myPrint("adjacent cars")(*std::adjacent_find(cars.begin(), cars.end(), adja()));
	std::cout << std::endl;

	/*------------------------------------------
		std::equal - Krav:
	------------------------------------------*/
	if ((std::equal(cars.begin(), cars.end(), carss, adja())))
	{
		std::cout << "They are equal" << std::endl;
	}
	else
	{
		std::cout << "they are not equal" << std::endl;
	}
	std::cout << '\n';


	/*------------------------------------------
		std::search - Krav:
	------------------------------------------*/
	std::vector<Car>::iterator it;
	Car carNeelde[] = { Car(models[4], speeds[4]), Car(models[5], speeds[5]) };

	it = std::search(cars.begin(), cars.end(), carNeelde, carNeelde + 2, adja());
	if (it!=cars.end())
	{
		std::cout << "needle1 found at position " << (it - cars.begin()) << '\n';
	}
	else
	{
		std::cout << "carNeedle not found" << '\n';
	}
	/*------------------------------------------
		std::accumulate - Krav: Operator+, samt en init double value.
	------------------------------------------*/
	double i = 0;
	double sum = std::accumulate(cars.begin(), cars.end(), i, MyBinOp());
	std::cout << "vector sum: " << sum << std::endl;



	system("PAUSE");
	return EXIT_SUCCESS;
}

