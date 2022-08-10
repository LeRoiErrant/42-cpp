#include <iostream>
#include "Array.hpp"

int main( void ) {
	int	*a = new int();

	std::cout << "*a: " << *a << std::endl;

	Array<int> test(5);
	std::cout << test.size() << std::endl;
	try {
		std::cout << test[6] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl; 
	}
	try {
		std::cout << test[-3] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl; 
	}
	test[0] = 48;
	test[1] = 32;
	std::cout << "test.size = " << test.size() << std::endl;
	for ( int i = 0 ; i < test.size() ; i++) {
		std::cout << "test[" << i << "] = " << test[i] << std::endl; 
	}
	Array<int> empty;
	empty = test;
	Array<int> Copy(test);
	std::cout << "Test[0] = " << test[0] << std::endl;
	std::cout << "Empty[0] = " << empty[0] << std::endl;
	std::cout << "Copy[0] = " << Copy[0] << std::endl;
	empty[1] = 12;
	Copy[1] = 21;
	std::cout << "Empty[1] = " << empty[1] << std::endl;
	std::cout << "Test[1] = " << test[1] << std::endl;
	std::cout << "Copy[1] = " << Copy[1] << std::endl;
}