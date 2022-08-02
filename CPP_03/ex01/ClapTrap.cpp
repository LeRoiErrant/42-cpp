#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ClapTrap	*ClapTrap::FirstBot = NULL;
ClapTrap	*ClapTrap::LastBot = NULL;
bool		ClapTrap::_Verbose = true;

ClapTrap::ClapTrap( void ) : _Name("Unamed Bot"), _HitPoints(HP), _InitialHP(_HitPoints), _EnergyPoints(EP), _AttackDamage(DPA) {
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
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been succesfully created as a ClapTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

ClapTrap::ClapTrap( std::string name ) : _Name(name), _HitPoints(HP), _InitialHP(_HitPoints), _EnergyPoints(EP), _AttackDamage(DPA) {
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
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been succesfully created as a ClapTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
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
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been succesfully cloned as a ClapTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

ClapTrap::~ClapTrap( void ) {
	if (ClapTrap::_Verbose) {
		std::cout << this->_Name << " is not usefull anymore. Self-destruct initiated." << std::endl;
		std::cout << "\t\tEnd states:\n\t\tHit points: " << this->_HitPoints << "\n\t\tEnergy points: " << this->_EnergyPoints << std::endl;
	}
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
	if (ClapTrap::_Verbose)
		std::cout << *this << " is being reassignated from:\n\tHit Points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
	this->_Name = src.getName();
	this->_HitPoints = src.getHitPoints();
	this->_InitialHP = src.getInitialHP();
	this->_EnergyPoints = src.getEnergyPoints();
	this->_AttackDamage = src.getAttackDamage();
	if (ClapTrap::_Verbose) {
		std::cout << "to:\n\tHit Points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << "He is now " << *this << std::endl;
	}
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
	if (ClapTrap::_Verbose)
		std::cout << *this << " has been reprogrammed. " << *this << "'s Attack Damage is set from " << this->_AttackDamage;
	this->_AttackDamage = value;
	if (ClapTrap::_Verbose)
		std::cout << " to " << this->_AttackDamage << std::endl;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {
	return (this->_AttackDamage);
}

void	ClapTrap::attack(const std::string& target) {
	ClapTrap	*bot;

	std::cout << "[ " << std::setw(12) << std::left << *this << RE << " " << std::setw(3) << std::right << this->_HitPoints << "  " << CY << std::setw(3) << std::right << this->_EnergyPoints << RC << " ]\t";
	if (this->_HitPoints and this->_EnergyPoints) {
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
		if (!this->_HitPoints)
			std::cout << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			std::cout << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::stringstream	ss;

	ss.str(std::string());
	if (!this->_HitPoints)
		ss << RE << *this << " has already been destroyed!" << RC << std::endl;
	else if (amount > this->_HitPoints) {
		ss << RE << "OVERKILL! " << *this << " took " << amount << " when having only " << this->_HitPoints << " HP left!" << RC << std::endl;
		this->_HitPoints = 0;
	}
	else {
		if (amount == 0)
			ss << YE << *this << " was attacked but took no Damage!" << RC << std::endl;
		else {
			this->_HitPoints -= amount;
			if (!this->_HitPoints)
				ss << RE << "Final blow! " << *this << " took " << amount << " Damages and has no HP left!" << RC << std::endl;
			else
				ss << YE << "Ouch! " << *this << " took " << amount << " Damages! " << *this << " got " << this->_HitPoints << " HP left!" << RC << std::endl;
		}
	}
	if (!this->_HitPoints)
		this->_EnergyPoints = 0;
	std::cout << "[ " << std::setw(12) << std::left << *this << RE << " " << std::setw(3) << std::right << this->_HitPoints << "  " << CY << std::setw(3) << std::right << this->_EnergyPoints << RC << " ]\t" << ss.str();
}

void	ClapTrap::beRepaired( unsigned int amount) {
	std::stringstream	ss;
	
	if (this->_HitPoints and this->_EnergyPoints) {
		if (this->_HitPoints == this->_InitialHP) {
			ss << GR << *this << " try to repair himself for " << amount << " Damages but already his at his max Health (Any extra HP is loss)" << RC << std::endl;
		}
		else if (this->_HitPoints + amount >= this->_InitialHP) {
			ss << GR << *this << " repaired himself for " << amount << " Damages and is back to max Health (Any extra HP is loss)" << RC << std::endl;
			this->_HitPoints = this->_InitialHP;
		}
		else {
			this->_HitPoints += amount;
			ss << GR << *this << " repaired himself for " << amount << " Damages and has now " << this->_HitPoints << " HP left!" << RC << std::endl;
		}
		this->_EnergyPoints--;
	}
	else {
		if (!this->_HitPoints)
			ss << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			ss << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
	std::cout << "[ " << std::setw(12) << std::left << *this << RE << " " << std::setw(3) << std::right << this->_HitPoints << "  " << CY << std::setw(3) << std::right << this->_EnergyPoints << RC << " ]\t" << ss.str();
}

std::ostream	&operator<<( std::ostream & ostream, ClapTrap const & src ) {
	ostream << src.getName();
	return (ostream);
}

void	ClapTrap::setVerbose(bool const value) {
	ClapTrap::_Verbose = value;
}