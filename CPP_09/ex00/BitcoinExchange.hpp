#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <ctime>
# include <sstream>
# include <map>
# include <string>

# define DATABASE "data.csv"

struct compare_tm
{
	bool operator()(const std::tm &a, const std::tm &b) const
	{
		std::time_t	ta = std::mktime(const_cast<tm *>(&a));
		std::time_t tb = std::mktime(const_cast<tm *>(&b));
		return (ta < tb);
	}
};

class BitcoinExchange {
public:
	BitcoinExchange( void );
	BitcoinExchange( std::string & infile );
    ~BitcoinExchange();

	void	process_file( const std::string & inflie );




private:
	std::map<std::tm, float, compare_tm>	_db;
	static const std::time_t				one_day = 24 * 60 * 60;

	BitcoinExchange( BitcoinExchange & src );
	BitcoinExchange &operator=( BitcoinExchange & src );

	void	read_database( void );
	float	find_date(std::tm t);


};

#endif
