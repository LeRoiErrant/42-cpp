#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_Name;
		DiamondTrap( void );
	public:
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap( void );

		DiamondTrap			&operator=( DiamondTrap const & src );

		void				attack(const std::string& target);
		void				whoAmI( void );

		virtual std::string	getName( void ) const;
		virtual	void		setName( std::string const & name);
};

std::ostream	&operator<<( std::ostream & ostream, DiamondTrap const & src );

#endif
