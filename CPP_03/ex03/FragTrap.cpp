#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	this->_HitPoints = FragTrap::_FragHitPoints;
	this->_InitialHP = this->_HitPoints;
	this->_EnergyPoints = FragTrap::_FragEnergyPoints;
	this->_AttackDamage = FragTrap::_FragAttackDamage;
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been upgraded and now is a FragTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->_HitPoints = FragTrap::_FragHitPoints;
	this->_InitialHP = this->_HitPoints;
	this->_EnergyPoints = FragTrap::_FragEnergyPoints;
	this->_AttackDamage = FragTrap::_FragAttackDamage;
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been upgraded and now is a FragTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}


FragTrap::FragTrap( FragTrap const & src ) : ClapTrap(src) {
	if (ClapTrap::_Verbose) {
		std::cout << *this << " has been succesfully cloned as a FragTrap!" << std::endl;
		std::cout << "\tHit points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
		std::cout << *this << " is ready to fight!" << std::endl;
	}
}

FragTrap::~FragTrap( void ) {
	if (ClapTrap::_Verbose)
		std::cout << *this << " is no longer a FragTrap." << std::endl;
}

FragTrap	&FragTrap::operator=( FragTrap const & src ) {
	if (ClapTrap::_Verbose)
		std::cout << *this << " is being reassignated from:\n\tHit Points:\t" << this->_HitPoints << "\n\tEnergy Points:\t" << this->_EnergyPoints << "\n\tAttack Damages:\t" << this->_AttackDamage << std::endl;
	this->setName(src.getName());
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

void	FragTrap::attack(const std::string& target) {
	ClapTrap	*bot;
	
	if (this->_HitPoints and this->_EnergyPoints) 
		this->_EnergyPoints--;
	std::cout << this->getLog();
	if (this->_HitPoints and this->_EnergyPoints) {
		bot = ClapTrap::FirstBot;
		while (bot and target.compare(bot->getName()))
			bot = bot->Next;
		if (bot) {
			std::cout << RE << *this << BL << " HIGH FIVED " << RE << target << ", in his head, with a chair, for " << this->_AttackDamage << " Damages!" << RC << std::endl;
			bot->takeDamage(this->_AttackDamage);
		}
		else {
			std::cout << YE << "No Target named " << target << " on the Battlefield. The attack failed !" << RC << std::endl;
		}
	}
	else {
		if (!this->_HitPoints)
			std::cout << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			std::cout << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
}

void	FragTrap::highFivesGuys( void ) {
	std::string cmd;
	bool		ask;
	int			res;

	this->_HighFived = false;
	if (this->_EnergyPoints and this->_HitPoints) {
		ask = true;
		res = (std::rand() % 6) + 1;
	}
	else {
		ask = false;
		if (!this->_HitPoints)
			std::cout << RE << *this << " has been destroyed and can't move anymore..." << RC << std::endl;
		else
			std::cout << CY << *this << " has no Energy left and can't move anymore. Go back to Base." << RC << std::endl;
	}
	while (ask) {
		std::cout << this->getLog();
		std::cout << BL << *this << " is asking for a HIGH FIVE ( SURE MAN / MEH ): " << RC;
		std::getline(std::cin, cmd);
		if (!cmd.compare("SURE MAN")) {
			this->_EnergyPoints += res;
			std::cout << this->getLog();
			std::cout << BL << *this << " is Ecstatic and regain " << res << " Energy Point" << RC << std::endl;
			this->_HighFived = true;
			ask = false;
		}
		else if (!cmd.compare("MEH")) {
			std::cout << this->getLog();
			std::cout << RE << *this << " is really sad and suffer Emotional Damages " << RC << std::endl;
			this->takeDamage(res);
			ask = false;
		}
		else
			std::cout << RE << "Invalid answer" << RC << std::endl;
	}
}

bool	FragTrap::getHighFived() const {
	return (this->_HighFived);
}

std::ostream	&operator<<( std::ostream & ostream, FragTrap const & src ) {
	ostream << src.getName();
	return (ostream);
}