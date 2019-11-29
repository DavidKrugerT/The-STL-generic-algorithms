#include "Car.h"
#include <iostream>

int main() {

	Car a("BMW", 200);
	Car b("Zeat", 150);
	std::cout << a.getName() << " " << a.getSpeed() << std::endl;
	
	

	system("PAUSE");
	return 0;
}