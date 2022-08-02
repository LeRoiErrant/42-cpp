#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	private:

	protected:
		bool	_HighFived;
		static const unsigned int		_FragHitPoints = 100;
		static const unsigned int		_FragEnergyPoints = 100;
		static const unsigned int		_FragAttackDamage = 30;
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
