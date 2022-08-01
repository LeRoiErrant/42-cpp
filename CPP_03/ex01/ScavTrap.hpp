#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

# define SHP 100
# define SEP 50
# define SDPA 20
# define SSC 5

class ScavTrap : public ClapTrap {
	private:
		bool				_GateKeeper;
		unsigned int		_Absorbed;
		unsigned int		_ShieldCapacity;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & src );
		~ScavTrap( void );

		ScavTrap	&operator=( ScavTrap const & src );

		virtual void			attack(const std::string& target);
		virtual void			takeDamage(unsigned int amount);
		void					absorbDamage( unsigned int amount );
		void					guardGate( void );

		bool					getGateKeeper( void ) const;
		unsigned int			getAbsorbed( void ) const;
		unsigned int			getShieldCapacity( void ) const;

		void					setGateKeeper( bool const value );
		void					setAbsorbed( unsigned int const value );
		void					setShieldCapacity( unsigned int const value );

};

std::ostream	&operator<<( std::ostream & ostream, ScavTrap const & src );

#endif
