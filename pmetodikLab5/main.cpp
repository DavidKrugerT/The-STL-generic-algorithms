#include "Car.h"
#include <iostream>		//cout
#include <vector>		//vector
#include <algorithm>	//for each
#include <functional>
//template<class E>
//void myPrint(const std::vector<E>& rhs) {
//	for (E a : rhs) {
//		std::cout << a << '\n';
//	}
//}


struct myPrint  {
	void operator()(Car& car) const{
		std::cout << car;
	}
};

// binary
//struct myPrint {
//	void operator()(Car& car, Car& car2) const {
//		std::cout << car;
//	}
//};
void print(Car & car) {
	std::cout << car;
}


struct printClass {
	static void print(Car&car) {
		std::cout << car;
	}
};
int main() {

	Car b("Zeat", 150);
	Car c("Volvo", 170);
	
	std::vector<Car> cars;
	


	std::string models[] = { "Volvo", "BMW", "Saab", "Zeat", "Mercedes" };
	double speeds[] = { 50, 100, 150, 200, 220 };

	for (unsigned int a = 0; a < sizeof(models) / sizeof(models[0]); a = a + 1){
		Car f(models[a], speeds[a]);
		cars.push_back(f);
	}
	
	// 1)
	std::cout << "Vector cars : ";
	std::for_each(cars.begin(), cars.end(), myPrint());
	std::for_each(std::begin(cars), std::end(cars), [&](Car & car) {
		myPrint()(car);
	});
	std::function<void(Car&)> f = std::bind(myPrint(), std::placeholders::_1);
	std::for_each(cars.begin(), cars.end(), f);
	std::for_each(cars.begin(), cars.end(), std::bind(print, std::placeholders::_1));
	std::function<void(Car&)> f2 = std::bind(printClass::print, std::placeholders::_1);
	for (int i = 0; i < cars.size(); i++) {
		myPrint()(cars[i]);
	}
	for (auto e : cars)
		myPrint()(e);
	system("PAUSE");
	return 0;
}
