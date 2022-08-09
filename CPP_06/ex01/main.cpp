#include "Data.hpp"
#include <iomanip>

uintptr_t	serialize( Data *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}


int	main( void ) {
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr->test = "Ceci est un test";
	std::cout << std::setw(15) << std::left << "ptr->test: " << ptr->test << std::endl;
	raw = serialize(ptr);
	std::cout << std::setw(15) << std::left << "Raw ptr: " << raw << std::endl; 
	new_ptr = deserialize(raw);
	std::cout << std::setw(15) << std::left << "new_ptr->test: " << new_ptr->test << std::endl;
	raw = serialize(new_ptr);
	std::cout << std::setw(15) << std::left << "Raw new_ptr: " << raw << std::endl; 
	Data *copy(deserialize(raw));
	std::cout << std::setw(15) << std::left << "copy->test: " << copy->test << std::endl;
	raw = serialize(copy);
	std::cout << std::setw(15) << std::left << "Raw copy: " << raw << std::endl; 
}