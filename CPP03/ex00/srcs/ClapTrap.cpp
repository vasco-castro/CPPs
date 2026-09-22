
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	// TODO: Copy Constructor
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	// TODO: Copy Assignment Overloader
	name = other.name;

}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::setName(const std::string& name) {}
void ClapTrap::setHitPoints(const std::string hitPoints) {}
void ClapTrap::setEnergyPoints(const std::string energyPoints) {}
void ClapTrap::setAttackDamage(const std::string attackDamage) {}
const std::string& ClapTrap::getType() const {}
const int ClapTrap::getHitPoints() const {}
const int ClapTrap::getEnergyPoints() const {}
const int ClapTrap::getAttackDamage() const {}

void ClapTrap::attack(const std::string& target) {
	// TODO: Validate energyPoints first
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks "
		<< target << ", causing " << attackDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	// TODO: Validate hitPoints first
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " tooke "
		<< amount << " amount of damage."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	// TODO: Validate energyPoints and hitPoints first
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaired "
		<< amount << " hit points."<< std::endl;
}
