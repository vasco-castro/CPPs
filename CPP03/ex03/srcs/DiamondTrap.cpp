
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"),
	ScavTrap(name), FragTrap(name), name(name) {
	std::cout << "DiamondTrap " << name << " Constructor called" << std::endl;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap " << name << " Copy Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap " << name << " Copy Assignment Operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap " << name << " Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "I am " << name
		<< " and my ClapTrap name is "
		<< ClapTrap::name << std::endl;
}
