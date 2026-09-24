
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap: public ScavTrap, public FragTrap {

	std::string name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
    	DiamondTrap(const DiamondTrap& other);
    	DiamondTrap& operator=(const DiamondTrap& other);
    	~DiamondTrap();

	    using ScavTrap::attack;
		void whoAmI();
};

#endif // DIAMONDTRAP_HPP
