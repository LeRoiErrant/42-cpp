#include <cstdlib>
#include <ctime>
#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

bool verbose = true;

Base *generate ( void ) {
	int	random = std::rand() % 3;

	if (random == 0) {
		if (verbose)
			std::cout << "Randomly generate A Class" << std::endl;
		return (new A());
	}
	else if (random == 1) {
		if (verbose)
			std::cout << "Randoml generate B Class" << std::endl;
		return (new B());
	}
	else {
		if (verbose)
			std::cout << "Randomly generate C Class" << std::endl;
		return (new C());
	}
}

void	identify( Base* p ){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify( Base& p ) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {
		(void) e;
	}
	try {
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {
		(void) e;
	}
	try {
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {
		(void) e;
	}
}

int	main() {
	Base	*_A = new A();
	Base	*_B = new B();
	Base	*_C = new C();
	std::srand(time(NULL));
	Base	*random = generate();
	std::cout << "Base _A Identification by pointer: ";
	identify(_A);
	std::cout << "Base _B Identification by pointer: ";
	identify(_B);
	std::cout << "Base _C Identification by pointer: ";
	identify(_C);
	std::cout << "Base random Identification by pointer: ";
	identify(random);
	std::cout << "Base _A Identification by reference: ";
	identify(*_A);
	std::cout << "Base _B Identification by reference: ";
	identify(*_B);
	std::cout << "Base _C Identification by reference: ";
	identify(*_C);
	std::cout << "Base random Identification by reference: ";
	identify(*random);
	return 0;
}