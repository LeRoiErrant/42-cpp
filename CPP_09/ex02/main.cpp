#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	std::string input;


	try {
		if (argc == 1)
			throw std::invalid_argument("No argument.");
		for (int i = 1; i < argc; i++) {
			input.append(argv[i]);
			input.append(" ");
		}
		std::vector c_vector(fillVector())
		std::cout << input << std::endl;
	} catch(std::runtime_error const &e) {
		std::cout << "FAILURE\t" << e.what() << std::endl;
	} catch(std::exception const &e) {
		std::cout << "ERROR\t" << e.what() << std::endl;
	}

}
