#include "./BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("not enough arguments");

		std::string		infile(argv[1]);
		BitcoinExchange	BTC(infile);
	}
	catch(std::runtime_error const &e)
	{
		std::cerr << "[FAILED]\t" << e.what() << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << "[EXCEPTION]\t" <<  e.what() << std::endl;
	}
	return (0);
}
