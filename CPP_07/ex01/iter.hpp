#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template< typename T>
void	iter(T *array, size_t size, void (*fct)(T &)) {
	for (size_t i = 0; i < size ; i++)
		(*fct)(array[i]);
}

template< typename T >
void	setrandomvalue(T &i) {
	i = std::rand() % 100;
}

template<>
void	setrandomvalue(char &i) {
	i = 32 + std::rand() % 92;
}

template< typename T >
void	addTwo(T &i) {
	i += 2;
}

template< typename T>
void	display(T & value) {
	std::cout << "Value is: " << value << std::endl;
}

#endif