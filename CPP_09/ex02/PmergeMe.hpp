#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <sstream>
# include <cctype>
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <stdexcept>
# include <exception>
# include <time.h>
# include <type_traits>
# include <list>


# define INSERT_THRESHOLD 64

template<typename Container>
Container	fillContainer(const std::string& input) {
	Container			result;
	std::istringstream	iss(input);
	std::string			token;
	typedef std::vector<typename Container::value_type> vector_type;
	typedef std::deque<typename Container::value_type> deque_type;
	typedef std::list<typename Container::value_type> list_type;
	
	if (typeid(result) != typeid(vector_type) and typeid(result) != typeid(deque_type) and typeid(result) != typeid(list_type))
		throw std::invalid_argument ("Invalid container");
	while (std::getline(iss, token, ' ')) {
		size_t pos;
		int	value = std::stoi(token, &pos);
		if (pos != token.size()) {
			throw std::invalid_argument("Invalid integer found in input");
		}
		if (value < 0) {
			throw std::invalid_argument("Negative integer found in input");
		}
		result.push_back(value);
	}
	return result;
}

template<typename Container>
Container	fillContainer(const std::string& input, int size) {
	Container			result;
	std::istringstream	iss(input);
	std::string			token;

	result.resize(size);

	for (int i = 0; i < size && std::getline(iss, token, ' '); i++) {
		size_t pos;
		int	value = std::stoi(token, &pos);
		if (pos != token.size()) {
			throw std::invalid_argument("Invalid integer found in input");
		}
		if (value < 0) {
			throw std::invalid_argument("Negative integer found in input");
		}
		result[i] = value;
	}
	return result;
}

template<typename Container>
void	printContainer(const Container& output) {
	for (size_t i = 0; i < output.size(); i++) {
		std::cout << output[i] << " ";
	}
	std::cout << std::endl;
}

#endif
