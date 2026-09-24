
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name("<undefined>"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap " << name << " Copy Constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap " << name << " Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " Destructor called" << std::endl;
}

void ClapTrap::setName(const std::string& name) {
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage = attackDamage;
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

	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isDead())
		return;

	std::cout << name << " took " << amount << " amount of damage!"<< std::endl;

	while (amount > 0 && hitPoints > 0) {
		hitPoints--;
		amount--;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (isDead() || isOutOfEnergy())
		return;

	std::cout << name << " repaired " << amount << " hit points."<< std::endl;

	hitPoints += amount;
	energyPoints--;
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
