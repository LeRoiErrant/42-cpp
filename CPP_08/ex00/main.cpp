#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>



int	main( void ) {
	std::vector<int>			cont(5, 1);
	std::vector<int>::iterator	it;
	std::list<int>				container;
	int							value = 7;


	std::cout << "--------------Vector--------------" << std::endl;
	for (size_t i = 0; i < cont.size(); i++) {
		cont[i] = i;
	}
	for (size_t i = 0; i < cont.size(); i++) {
		std::cout << cont[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "---------------List---------------" << std::endl;
	for (int i = 0; i < 10; i++) {
		container.push_back(i);
	}
    for (std::list<int>::iterator iter = container.begin(); iter != container.end(); iter++) {
        std::cout << *iter << " ";
    }
	std::cout << "\n" << std::endl;
	std::cout << "Searching value: " << value << std::endl;
	it = easyfind(cont, value);
	if (it == cont.end())
		std::cout << "Didn't find value in vector" << std::endl;
	else
		std::cout << "Value found in vector" << std::endl;
	if (easyfind< std::list<int> >(container, value) == container.end())
		std::cout << "Didn't find value in list" << std::endl;
	else
		std::cout << "Value found in list" << std::endl;
	std::cout << "\n" << std::endl;
	value = 2;
	std::cout << "Searching value: " << value << std::endl;
	it = easyfind(cont, value);
	if (it == cont.end())
		std::cout << "Didn't find value in vector" << std::endl;
	else
		std::cout << "Value found in vector" << std::endl;
	if (easyfind< std::list<int> >(container, value) == container.end())
		std::cout << "Didn't find value in list" << std::endl;
	else
		std::cout << "Value found in list" << std::endl;
	std::cout << "\n" << std::endl;
	value = 15;
	std::cout << "Searching value: " << value << std::endl;
	it = easyfind(cont, value);
	if (it == cont.end())
		std::cout << "Didn't find value in vector" << std::endl;
	else
		std::cout << "Value found in vector" << std::endl;
	if (easyfind< std::list<int> >(container, value) == container.end())
		std::cout << "Didn't find value in list" << std::endl;
	else
		std::cout << "Value found in list" << std::endl;
	return 0;
}