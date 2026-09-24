
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap {

	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
    	ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		void setName(const std::string& name);
		void setHitPoints(unsigned int hitPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setAttackDamage(unsigned int attackDamage);

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
