#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
	ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HitPoints = FragTrap::_FragHitPoints;
	this->_InitialHP = this->_HitPoints;
	this->_EnergyPoints = ScavTrap::_ScavEnergyPoints;
	this->_AttackDamage = FragTrap::_FragAttackDamage;
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been upgraded and now is a DiamondTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), ScavTrap(name), FragTrap(name), _Name(name) {
	ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HitPoints = FragTrap::_FragHitPoints;
	this->_InitialHP = this->_HitPoints;
	this->setEnergyPoints(ScavTrap::_ScavEnergyPoints);
	this->_AttackDamage = FragTrap::_FragAttackDamage;
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been upgraded and now is a DiamondTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}


DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	ClapTrap::_Name = this->_Name + "_clap_name";
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been succesfully cloned as a DiamondTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

DiamondTrap::~DiamondTrap( void ) {
	if (ClapTrap::_Verbose)
		std::cout << *this << " is no longer a DiamondTrap." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const & src ) {
	if (ClapTrap::_Verbose)
		std::cout << *this << " is being reassignated from:\n\tHit Points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
	this->setName(src.getName());
	ClapTrap::_Name = this->_Name + "_clap_name";
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

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "Please allow me to introduce myself, I'm a Diamond named " << *this << ", also known as " << ClapTrap::_Name << std::endl;
}

std::string	DiamondTrap::getName( void ) const {
	return (this->_Name);
}

void	DiamondTrap::setName( std::string const & name ) {
	this->_Name = name;
}

std::ostream	&operator<<( std::ostream & ostream, DiamondTrap const & src ) {
	ostream << src.getName();
	return (ostream);
}