
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap " << name << " Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	std::cout << "ScavTrap " << name << " Copy Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap " << name << " Copy Assignment Operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (isDead() || isOutOfEnergy())
		return;

	std::cout << name << " fires at " << target
		<< ", dealing " << attackDamage << " points of damage!" << std::endl;

	energyPoints--;
}

void ScavTrap::guardGate() const {
	std::cout << name << " is now in Gate keeper mode." << std::endl;
}
