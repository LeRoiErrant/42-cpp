#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:

	protected:
		bool				_GateKeeper;
		unsigned int		_Absorbed;
		unsigned int		_ShieldCapacity;
		
		static const unsigned int		_MaxShieldCapacity = 10;
		static const unsigned int		_ScavHitPoints = 100;
		static const unsigned int		_ScavEnergyPoints = 50;
		static const unsigned int		_ScavAttackDamage = 20;
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
		
		virtual std::string		getLog();
};

std::ostream	&operator<<( std::ostream & ostream, ScavTrap const & src );

#endif
