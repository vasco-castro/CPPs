
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::setName(const std::string& name) {
	this.name = name;
}

void ClapTrap::setHitPoints(const std::string hitPoints) {
	this.hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(const std::string energyPoints) {
	this.energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(const std::string attackDamage) {
	this.attackDamage = attackDamage;
}

const std::string& ClapTrap::getName() const {
	return &name;
}

const int ClapTrap::getHitPoints() const {
	return &hitPoints;
}

const int ClapTrap::getEnergyPoints() const {
	return &energyPoints;
}

const int ClapTrap::getAttackDamage() const {
	return &attackDamage;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints <= 0)
		return;
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks "
		<< target << ", causing " << attackDamage
		<< " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= 0)
		return;
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " tooke "
		<< amount << " amount of damage."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints <= 0)
		return;
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repaired "
		<< amount << " hit points."<< std::endl;
}
