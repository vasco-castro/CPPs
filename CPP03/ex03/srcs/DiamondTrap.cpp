
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("<undefined>_clap_name"),
	ScavTrap(), FragTrap(), name("<undefined>") {

	std::cout << "DiamondTrap Default Constructor called" << std::endl;

	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(std::string newName): ClapTrap(newName + "_clap_name"),
	ScavTrap(newName), FragTrap(newName), name(newName) {

	std::cout << "DiamondTrap " << name << " Constructor called" << std::endl;

	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	std::cout << "DiamondTrap " << name << " Copy Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		name = other.name;
	}
	std::cout << "DiamondTrap " << name << " Copy Assignment Operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << name << " Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() const {
	std::cout << "I am " << name
		<< " and my ClapTrap name is "
		<< ClapTrap::name << std::endl;
}
