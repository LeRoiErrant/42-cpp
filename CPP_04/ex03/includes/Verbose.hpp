#ifndef VERBOSE_HPP
# define VERBOSE_HPP

# include <iostream>

# define BLINK "\033[1;5m"
# define BOLD "\033[1m"
# define ITAL "\033[3m"
# define UNDRL "\033[4m"
# define HDDN "\033[8m"
# define GR "\033[32;1m"
# define RE "\033[31;1m"
# define DR "\033[31;1;2m"
# define YE "\033[33;1m"
# define CY "\033[36;1m"
# define LG "\033[37;1;3m"
# define DG "\033[90;1;3m"
# define DGB "\033[90;1m"
# define LB "\033[94;1m"
# define WH "\033[97m"
# define MA "\001\033[1;95m\002"
# define BL "\001\033[1;94m\002"
# define RC "\033[0m"

class Verbose {
	private:

	public:
		Verbose( void );
		Verbose( Verbose const & src );
		~Verbose( void );

		Verbose	&operator=( Verbose const & src );

		static bool	On;

		static void	msg(std::string const & msg);

};

#endif
