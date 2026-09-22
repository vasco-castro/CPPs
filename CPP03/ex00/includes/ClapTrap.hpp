
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
    	ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void setName(const std::string& name);
		void setHitPoints(const std::string hitPoints);
		void setEnergyPoints(const std::string energyPoints);
		void setAttackDamage(const std::string attackDamage);
		const std::string& getType() const;
		const int getHitPoints() const;
		const int getEnergyPoints() const;
		const int getAttackDamage() const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
