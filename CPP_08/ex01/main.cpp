#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <time.h>



int main( void ) {
	Span				sp(10000);
	std::vector<int>	vec;

	std::srand(time(NULL));
	try {
		for ( int i = 0; i < 9997 ; i++)
			sp.addNumber(std::rand() % 100000000);
		std::cout << "Size: " << sp.getSize() << " Storage: " << sp.getMaxStorage() << std::endl;
		vec.push_back(1);
		vec.push_back(12);
		vec.push_back(23);
		sp.addNumbers< std::vector<int>::iterator >(vec.begin(), vec.end());
		for (unsigned int i = 0; i < 10 ; i++) {
			std::cout << "Span[" << i << "]: " << sp[i] << std::endl;
		}
		std::cout << "[...]" << std::endl;
		for (unsigned int i = 9997; i < sp.getSize() ; i++) {
			std::cout << "Span[" << i << "]: " << sp[i] << std::endl;
		}
		std::cout << "Shortest Range: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Range: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Time elapsed: " << clock() << std::endl;
	return 0;
}
