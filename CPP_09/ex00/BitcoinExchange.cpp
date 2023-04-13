#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	this->read_database();
}

BitcoinExchange::BitcoinExchange( std::string & infile )
{
	this->read_database();
	this->process_file(infile);
}

BitcoinExchange::~BitcoinExchange( void )
{

}

void	BitcoinExchange::read_database( void )
{
	float 								value;
	std::tm								t = {};
	std::string 						line;
	std::ifstream						file;

	this->_db.clear();
	file.open(DATABASE);
	if (file.bad())
		throw std::runtime_error("to open databases");
	getline(file, line);
	while (getline(file, line))
	{
		char 				c;
		std::istringstream	flux(line);
		flux >> t.tm_year >> c >> t.tm_mon >> c >> t.tm_mday >> c >> value;
		t.tm_mon -= 1;
		if (mktime(&t) == -1)
			throw std::runtime_error("wrong time in database");
		this->_db[t] = value;
	}
	file.close();
}


void BitcoinExchange::process_file(const std::string & infile)
{
	float 				value;
	std::string 		line;
	std::ifstream		file;
	std::tm				t = {};

	file.open(infile, std::ifstream::in);
	if (file.bad() or !file.is_open())
		throw std::runtime_error("cannot open input file");
	while (getline(file, line))
	{
		char				c;
		std::istringstream	flux(line);

		flux >> t.tm_year >> c >> t.tm_mon >> c >> t.tm_mday >> c >> value;
		if (flux.fail()) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		t.tm_mon -= 1;
		if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (mktime(&t) == -1)
			std::cout << "Error: bad input => " << line << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large number" << std::endl;
		else
		{
			float 	price;
			c = '-';
			if ((price = find_date(t)) < 0)
				std::cout << "Error: not in database" << std::endl;
			else
				std::cout << t.tm_year << c << (t.tm_mon + 1) << c << t.tm_mday << " => " << value << " = " << (value * price) << std::endl;
		}
	}
}

float	BitcoinExchange::find_date(std::tm t)
{
	std::map<std::tm, float, compare_tm>::iterator	iter;
	std::time_t										tmp_value;
	std::time_t										begin_date;

	tmp_value = mktime(&t);
	begin_date = mktime(const_cast<std::tm *>(&(this->_db.begin()->first)));
	while ((iter = this->_db.find(t)) == this->_db.end() && begin_date <= tmp_value)
	{
		tmp_value = mktime(&t) - BitcoinExchange::one_day;
		t = *localtime(&tmp_value);
	}
	if (begin_date > tmp_value)
		return (-1);
	return (iter->second);
}
