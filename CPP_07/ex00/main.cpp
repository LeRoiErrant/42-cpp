#include "whatever.hpp"
#include <iomanip>

int	main( void ) {
	int			x = 9;
	int 		y = 42;
	char		c1 = 'e';
	char		c2 = 'j';
	float		f1 = 42.42;
	float		f2 = 66.6;

	std::cout << "x: " << std::setw(5) << std::left << x << "\ty: " << std::setw(5) << std::left << y << std::endl;
	swap<int>(x, y);
	std::cout << "x: " << std::setw(5) << std::left << x << "\ty: " << std::setw(5) << std::left << y << std::endl;
	std::cout << "c1: " << std::setw(5) << std::left << c1 << "\tc2: " << std::setw(5) << std::left << c2 << std::endl;
	swap<char>(c1, c2);
	std::cout << "c1: " << std::setw(5) << std::left << c1 << "\tc2: " << std::setw(5) << std::left << c2 << std::endl;
	std::cout << "f1: " << std::setw(5) << std::left << f1 << "\tf2: " << std::setw(5) << std::left << f2 << std::endl;
	swap<float>(f1, f2);
	std::cout << "f1: " << std::setw(5) << std::left << f1 << "\tf2: " << std::setw(5) << std::left << f2 << std::endl;

	std::cout << "\nMin between " << x << " and " << y << " is " << min<int>(x, y) << std::endl;
	std::cout << "Min between " << c1 << " and " << c2 << " is " << min<char>(c1, c2) << std::endl;
	std::cout << "Min between " << f1 << " and " << f2 << " is " << min<float>(f1, f2) << std::endl;

	std::cout << "\nMax between " << x << " and " << y << " is " << max<int>(x, y) << std::endl;
	std::cout << "Max between " << c1 << " and " << c2 << " is " << max<char>(c1, c2) << std::endl;
	std::cout << "Max between " << f1 << " and " << f2 << " is " << max<float>(f1, f2) << std::endl;
	
	std::cout << "\n\n" << std::endl;
	
	int	a = 2;
	int b = 3;

	::swap( a,b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string	d = "chaine2";

	::swap( c,d );
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}