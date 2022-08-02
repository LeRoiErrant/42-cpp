#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"

# define FHP 100
# define FEP 100
# define FDPA 30

class FragTrap : public ClapTrap {
	private:
		bool	_HighFived;
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap( void );

		FragTrap		&operator=( FragTrap const & src );

		virtual void	attack(const std::string& target);

		void			highFivesGuys( void );

		bool			getHighFived() const;

};

std::ostream	&operator<<( std::ostream & ostream, FragTrap const & src );

#endif
