
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string newName);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void setName(const std::string& newName);
		void setHitPoints(unsigned int newHitPoints);
		void setEnergyPoints(unsigned int newEnergyPoints);
		void setAttackDamage(unsigned int newAttackDamage);

		const std::string& getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		bool isDead() const;
		bool isOutOfEnergy() const;
};

#endif // CLAPTRAP_HPP
