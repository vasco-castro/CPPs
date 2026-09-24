
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("<undefined>"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string newName)
	: name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		setName(other.name);
		setHitPoints(other.hitPoints);
		setEnergyPoints(other.energyPoints);
		setAttackDamage(other.attackDamage);
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::setName(const std::string& newName) {
	name = newName;
}

void ClapTrap::setHitPoints(unsigned int newHitPoints) {
	hitPoints = newHitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int newEnergyPoints) {
	energyPoints = newEnergyPoints;
}

void ClapTrap::setAttackDamage(unsigned int newAttackDamage) {
	attackDamage = newAttackDamage;
}

const std::string& ClapTrap::getName() const {
	return name;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::attack(const std::string& target) {
	if (isDead() || isOutOfEnergy())
		return;

	std::cout << name << " fires at " << target
		<< ", causing " << attackDamage << " points of damage!" << std::endl;

	setEnergyPoints(energyPoints - 1);
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDead())
		return;

	std::cout << name << " took " << amount << " amount of damage!"<< std::endl;

	setHitPoints(amount < hitPoints ? hitPoints - amount : 0);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (isDead() || isOutOfEnergy())
		return;

	std::cout << name << " repaired " << amount << " hit points."<< std::endl;

	setHitPoints(hitPoints + amount);
	setEnergyPoints(energyPoints - 1);
}

bool ClapTrap::isDead() const {
	if (hitPoints == 0)
		return (std::cout << name << " is already dead." << std::endl, true);
	return false;
}

bool ClapTrap::isOutOfEnergy() const {
	if (energyPoints == 0)
		return (std::cout << name << " is out of energy." << std::endl, true);
	return false;
}
