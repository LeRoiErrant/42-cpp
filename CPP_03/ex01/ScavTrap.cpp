#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap(), _GateKeeper(false), _Absorbed(0), _ShieldCapacity(SSC) {
	this->_HitPoints = SHP;
	this->_InitialHP = this->_HitPoints;
	this->_EnergyPoints = SEP;
	this->_AttackDamage = SDPA;
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been upgraded and now is a ScavTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name), _GateKeeper(false), _Absorbed(0), _ShieldCapacity(SSC) {
	this->_HitPoints = SHP;
	this->_InitialHP = this->_HitPoints;
	this->_EnergyPoints = SEP;
	this->_AttackDamage = SDPA;
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been upgraded and now is a ScavTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}


ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src) {
	this->_GateKeeper = src.getGateKeeper();
	this->_Absorbed = src.getAbsorbed();
	this->_ShieldCapacity = src.getShieldCapacity();
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been succesfully cloned as a ScavTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

ScavTrap::~ScavTrap( void ) {
	if (ClapTrap::_Verbose)
		std::cout << *this << " is no longer a ScavTrap." << std::endl;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const & src ) {
	if (ClapTrap::_Verbose)
		std::cout << *this << " is being reassignated from:\n\tHit Points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
	this->setName(src.getName());
	this->_HitPoints = src.getHitPoints();
	this->_InitialHP = src.getInitialHP();
	this->_EnergyPoints = src.getEnergyPoints();
	this->_AttackDamage = src.getAttackDamage();
	this->_GateKeeper = src.getGateKeeper();
	this->_Absorbed = src.getAbsorbed();
	this->_ShieldCapacity = src.getShieldCapacity();
	if (ClapTrap::_Verbose) {
		std::cout << "to:\n\tHit Points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << "He is now " << *this << std::endl;
	}
	return (*this);
}

void	ScavTrap::setGateKeeper( bool const value ) {
	this->_GateKeeper = value;
}

bool	ScavTrap::getGateKeeper( void ) const {
	return (this->_GateKeeper);
}

void	ScavTrap::setAbsorbed( unsigned int const value ) {
	this->_Absorbed = value;
}

unsigned int	ScavTrap::getAbsorbed( void ) const {
	return (this->_Absorbed);
}

void	ScavTrap::setShieldCapacity( unsigned int const value ) {
	this->_ShieldCapacity = value;
}

unsigned int	ScavTrap::getShieldCapacity( void ) const {
	return (this->_ShieldCapacity);
}

void	ScavTrap::attack(const std::string& target) {
	ClapTrap	*bot;

	if (this->_HitPoints and this->_EnergyPoints) {
		std::cout << "[ " << *this << " ]\t";
		bot = ClapTrap::FirstBot;
		while (bot and target.compare(bot->getName()))
			bot = bot->Next;
		if (bot) {
			std::cout << RE << *this << " slam " << target << " with his " << CY << "SHIELD" << RE << " for " << this->_AttackDamage << " Damages!" << RC << std::endl;
			bot->takeDamage(this->_AttackDamage);
		}
		else {
			std::cout << YE << "No Target named " << target << " on the Battlefield. The attack failed !" << RC << std::endl;
		}
		this->_EnergyPoints--;
	}
	else {
		std::cout << "[ " << *this << "\t";
		if (!this->_HitPoints)
			std::cout << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			std::cout << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
}

void	ScavTrap::absorbDamage( unsigned int amount ) {
	unsigned int	absorbed;
	unsigned int	damage;
	
	if ( this->_Absorbed + amount <= this->_ShieldCapacity and this->_EnergyPoints >= amount ) {
		this->_EnergyPoints -= amount;
		this->_Absorbed += amount;
		std::cout << CY << *this << "'s Energy Shield absorbed " << amount << " Damages.\n\t\tShield capacity left: " << (this->_ShieldCapacity - this->_Absorbed) << "\n\t\tEnergy left: " << this->_EnergyPoints << RC << std::endl;
		if (this->_Absorbed == this->_ShieldCapacity) {
			std::cout << "[ " << *this << " ]\t" << CY << "Maximum Shield Capacity reached.\n\t\tEnding GATE KEEPER mode." << RC << std::endl;
			this->_GateKeeper = false;
			this->_Absorbed = 0;
		}
		else if (!this->_EnergyPoints) {
			std::cout << "[ " << *this << "\t" << CY << *this << "has no Energy left.\n\t\tEnding GATE KEEPER mode." << RC << std::endl;
			this->_GateKeeper = false;
			this->_Absorbed = 0;
		}
	}
	else if ( this->_Absorbed + amount > this->_ShieldCapacity and (this->_ShieldCapacity - this->_Absorbed) <= this->_EnergyPoints) {
		absorbed = this->_ShieldCapacity - this->_Absorbed;
		damage = amount - absorbed;
		this->_EnergyPoints -= absorbed;
		std::cout << CY << "Maximum Shield Capacity exceeded. " << absorbed << " Damages absorbed and " << damage << " Damages pierced.\n\t\tEnding GATE KEEPER mode." << RC << std::endl;
		this->_GateKeeper = false;
		this->_Absorbed = 0;
		this->takeDamage(damage);
	}
	else if ( this->_Absorbed + amount > this->_ShieldCapacity and (this->_ShieldCapacity - this->_Absorbed) > this->_EnergyPoints) {
		absorbed = this->_EnergyPoints;
		damage = amount - absorbed;
		this->_EnergyPoints = 0;
		std::cout << CY << "No more Energy to withstand Damages. " << absorbed << " Damges absorbed and " << damage << " Dame pierced.\n\t\tEnding GATE KEEPER mode." << RC << std::endl;
		this->_GateKeeper = false;
		this->_Absorbed = 0;
		this->takeDamage(damage);
	}
}

void	ScavTrap::takeDamage(unsigned int amount) {
	std::cout << "[ " << *this << " ]\t";
	if (!this->_HitPoints){
		std::cout << RE << *this << " has already been destroyed!" << RC << std::endl;
	}
	else if (this->_GateKeeper)
		absorbDamage(amount);
	else {
		if (amount > this->_HitPoints) {
			std::cout << RE << "OVERKILL! " << *this << " took " << amount << " when having only " << this->_HitPoints << " HP left!" << RC << std::endl;
			this->_HitPoints = 0;
		}
		else {
			if (amount == 0)
				std::cout << YE << *this << " was attacked but took no Damage!" << RC << std::endl;
			else {
				this->_HitPoints -= amount;
			if (!this->_HitPoints)
				std::cout << RE << "Final blow! " << *this << " took " << amount << " Damages and has no HP left!" << RC << std::endl;
			else
				std::cout << YE << "Ouch! " << *this << " took " << amount << " Damages! " << *this << " got " << this->_HitPoints << " HP left!" << RC << std::endl;
			}
		}
	}
}

void	ScavTrap::guardGate( void ) {
	if (!this->_GateKeeper) {
		std::cout << "[ " << *this << " ]\t";
		std::cout << CY << "Engaging GATE KEEPER mode. Energy Shield (" << this->_ShieldCapacity << ") deployed" << RC << std::endl;
		this->_GateKeeper = true;
	}
	else {
		std::cout << "[ " << *this << " ]\t";
		std::cout << CY << "GATE KEEPER mode already engaged. Energy Shield Capacity left: " << this->_ShieldCapacity - this->_Absorbed << RC << std::endl;
	}
		
}

std::ostream	&operator<<( std::ostream & ostream, ScavTrap const & src ) {
	ostream << src.getName();
	return (ostream);
}