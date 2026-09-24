
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap " << name << " Constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	std::cout << "FragTrap " << name << " Copy Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap " << name << " Copy Assignment Operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() const {
	std::cout << name << " requests a high five!" << std::endl;
}
