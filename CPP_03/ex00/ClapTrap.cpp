#include "ClapTrap.hpp"

ClapTrap	*ClapTrap::FirstBot = NULL;
ClapTrap	*ClapTrap::LastBot = NULL;

ClapTrap::ClapTrap( void ) : _Name("Unamed Bot"), _HitPoints(10), _InitialHP(_HitPoints), _EnergyPoints(10), _AttackDamage(0) {
	if (!ClapTrap::FirstBot) {
		this->Previous = NULL;
		ClapTrap::FirstBot = this;
		ClapTrap::LastBot = this;
	}
	else {
		ClapTrap::LastBot->Next = this;
		this->Previous = ClapTrap::LastBot;
		this->Next = NULL;
		ClapTrap::LastBot = this;
	}
	std::cout << this->_Name << " is ready to fight!" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _Name(name), _HitPoints(10), _InitialHP(_HitPoints), _EnergyPoints(10), _AttackDamage(0) {
	if (!ClapTrap::FirstBot) {
		this->Previous = NULL;
		ClapTrap::FirstBot = this;
		ClapTrap::LastBot = this;
	}
	else {
		ClapTrap::LastBot->Next = this;
		this->Previous = ClapTrap::LastBot;
		this->Next = NULL;
		ClapTrap::LastBot = this;
	}
	std::cout << this->_Name << " is ready to fight!" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) {
	this->_Name = src.getName();
	this->_HitPoints = src.getHitPoints();
	this->_InitialHP = src.getInitialHP();
	this->_EnergyPoints = src.getEnergyPoints();
	this->_AttackDamage = src.getAttackDamage();
	if (!ClapTrap::FirstBot) {
		this->Previous = NULL;
		ClapTrap::FirstBot = this;
		ClapTrap::LastBot = this;
	}
	else {
		ClapTrap::LastBot->Next = this;
		this->Previous = ClapTrap::LastBot;
		this->Next = NULL;
		ClapTrap::LastBot = this;
	}
	std::cout << this->_Name << " is ready to fight!" << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << this->_Name << " is not usefull anymore. Self-destruct initiated." << std::endl;
	if (this->Previous and this->Next) {
		this->Previous->Next = this->Next;
		this->Next->Previous = this->Previous;
	}
	else if (this->Previous)
		this->Previous->Next = NULL;
	else if (this->Next)
		this->Next->Previous = NULL;
	if (this == ClapTrap::FirstBot)
		ClapTrap::FirstBot = this->Next;
	if (this == ClapTrap::LastBot)
		ClapTrap::LastBot = this->Previous;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const & src ) {
	(void) src;
	return (*this);
}

void	ClapTrap::setName( std::string const value ) {
	this->_Name = value;
}

std::string	ClapTrap::getName( void ) const {
	return (this->_Name);
}

void	ClapTrap::setHitPoints( unsigned int const value ) {
	this->_HitPoints = value;
}

unsigned int	ClapTrap::getHitPoints( void ) const {
	return (this->_HitPoints);
}

void	ClapTrap::setInitialHP( unsigned int const value ) {
	this->_InitialHP = value;
}

unsigned int	ClapTrap::getInitialHP( void ) const {
	return (this->_InitialHP);
}

void	ClapTrap::setEnergyPoints( unsigned int const value ) {
	this->_EnergyPoints = value;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {
	return (this->_EnergyPoints);
}

void	ClapTrap::setAttackDamage( unsigned int const value ) {
	std::cout << *this << " has been reprogrammed. " << *this << "'s Attack Damage is set from " << this->_AttackDamage;
	this->_AttackDamage = value;
	std::cout << " to " << this->_AttackDamage << std::endl;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	return (this->_AttackDamage);
}

void	ClapTrap::attack(const std::string& target) {
	ClapTrap	*bot;

	if (this->_HitPoints and this->_EnergyPoints) {
		std::cout << "[ " << *this << " ] ";
		bot = ClapTrap::FirstBot;
		while (bot and target.compare(bot->getName()))
			bot = bot->Next;
		if (bot) {
			std::cout << RE << *this << " attack " << target << " for " << this->_AttackDamage << " Damages!" << RC << std::endl;
			bot->takeDamage(this->_AttackDamage);
		}
		else {
			std::cout << YE << "No Target named " << target << " on the Battlefield. The attack failed !" << RC << std::endl;
		}
		this->_EnergyPoints--;
	}
	else {
		std::cout << "[ " << *this << " ] ";
		if (!this->_HitPoints)
			std::cout << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			std::cout << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->_HitPoints) {
		std::cout << "[ " << *this << " ] ";
		std::cout << RE << "OVERKILL! " << *this << " took " << amount << " when having only " << this->_HitPoints << " HP left!" << RC << std::endl;
		this->_HitPoints = 0;
	}
	else {
		std::cout << "[ " << *this << " ] ";
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

void	ClapTrap::beRepaired( unsigned int amount) {
	if (this->_HitPoints and this->_EnergyPoints) {
		std::cout << "[ " << *this << " ] ";
		if (this->_HitPoints + amount >= this->_InitialHP) {
			std::cout << GR << *this << " repaired himself for " << amount << " Damages and and is back to max Health (Any extra HP is loss)" << RC << std::endl;
			this->_HitPoints = this->_InitialHP;
		}
		else {
			this->_HitPoints += amount;
			std::cout << GR << *this << " repaired himself for " << amount << " Damages and has now " << this->_HitPoints << " HP left!" << RC << std::endl;
		}
		this->_EnergyPoints--;
	}
	else {
		std::cout << "[ " << *this << " ] ";
		if (!this->_HitPoints)
			std::cout << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			std::cout << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
}

std::ostream	&operator<<( std::ostream & ostream, ClapTrap const & src ) {
	ostream << src.getName();
	return (ostream);
}