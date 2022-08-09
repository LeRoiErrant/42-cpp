#include "Bureaucrat.hpp"

int	main( void ) {
	Bureaucrat	Tom("Tom", 25);
	Bureaucrat	Bobby("Bobby", 52);
	Form		a38("A-38", 38, 26);
	Form		b51("B-51", 51, 45);

	try {
		Form	Nonsense("WTF", 0, 1553);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form	Confidential("WTF", 0, 1);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form	NotOurService("WTF", 150, 222);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << Tom << std::endl;
	std::cout << Bobby << std::endl;
	Tom.signForm(a38);
	Bobby.signForm(b51);
	Bobby.promote();
	Bobby.signForm(b51);
	return (0);
}