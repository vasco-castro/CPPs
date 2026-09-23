
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "Copy constructor called" << std::endl;
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
	this->name = name;
}

void ClapTrap::setHitPoints(int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	this->attackDamage = attackDamage;
}

const std::string& ClapTrap::getName() const {
	return name;
}

int ClapTrap::getHitPoints() const {
	return hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::attack(const std::string& target) {
	if (isDead() || isOutOfEnergy())
		return;

	std::cout << "ClapTrap " << name << " attacks "
		<< target << ", causing " << attackDamage
		<< " points of damage!" << std::endl;

	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDead())
		return;

	std::cout << "ClapTrap " << name << " took "
		<< amount << " amount of damage!"<< std::endl;

	while (amount > 0 && hitPoints > 0) {
		hitPoints--;
		amount--;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (isDead() || isOutOfEnergy())
		return;

	std::cout << "ClapTrap " << name << " repaired "
		<< amount << " hit points."<< std::endl;

	hitPoints += amount;
	energyPoints--;
}

bool ClapTrap::isDead() const {
	if (hitPoints <= 0)
		return (std::cout << name << " is already dead." << std::endl, true);
	return false;
}

bool ClapTrap::isOutOfEnergy() const {
	if (energyPoints <= 0)
		return (std::cout << name << " is out of energy." << std::endl, true);
	return false;
}
