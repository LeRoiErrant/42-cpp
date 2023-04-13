#include "RPN.hpp"

int main(int argc, char **argv) {
    std::string exp;

    try {
		if (argc == 2) {
			std::string	tmp(argv[1]);
			exp = tmp;
		} else if (argc > 2) {
			std::ostringstream ss;
			for (int i = 1; i < argc; i++) {
				ss << argv[i] << " ";
			}
			exp = ss.str();
		} else {
			throw ParametersErrorException();
		}
        RPN solver(exp);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
