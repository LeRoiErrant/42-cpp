#include <cstdlib>
#include <ctime>
#include "iter.hpp"

int main( void ) {
	int			*i = new int[5];
	char		*c = new char[5];
	std::string	str[] = { "Test1" , "Test2", "Test3" };

	std::srand(time(NULL));
	::iter<int>(i, 5, &setrandomvalue);
	::iter<int>(i, 5, &display);
	::iter<int>(i, 5, &addTwo);
	std::cout << std::endl;
	::iter<int>(i, 5, &display);
	std::cout << std::endl;
	::iter<char>(c, 5, &setrandomvalue);
	::iter<char>(c, 5, &display);
	::iter<char>(c, 5, &addTwo);
	std::cout << std::endl;
	::iter<char>(c, 5, &display);
	std::cout << std::endl;
	::iter<std::string>(str, 3, &display);
	delete [] i;
	delete [] c;
	return 0;
}