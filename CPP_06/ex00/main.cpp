#include "Converter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "error: bad arguments" << std::endl;
	else {
		Converter	test(argv[1]);
		Converter	test2(test);
	
		test.PrintValues();
		test2.PrintValues();
	}
	return 0;
}