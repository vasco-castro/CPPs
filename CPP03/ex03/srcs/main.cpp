
#include "DiamondTrap.hpp"
#include <iostream>

static void	printStats(const ClapTrap& trap) {
	std::cout << "[" << trap.getName() << "] HP: " << trap.getHitPoints()
		<< " | EP: " << trap.getEnergyPoints()
		<< " | AD: " << trap.getAttackDamage() << std::endl;
}

int main(void)
{
	std::cout << "--- Construction ---" << std::endl;
	DiamondTrap d("Bob");
	std::cout << std::endl;

	std::cout << "--- Stats (HP/AD from FragTrap, EP from ScavTrap) ---" << std::endl;
	printStats(d);
	std::cout << std::endl;

	std::cout << "--- Abilities ---" << std::endl;
	d.whoAmI();
	d.attack("Enemy");
	d.guardGate();
	d.highFivesGuys();
	d.takeDamage(40);
	d.beRepaired(10);
	printStats(d);
	std::cout << std::endl;

	std::cout << "--- Copy constructor ---" << std::endl;
	{
		DiamondTrap copy(d);
		copy.whoAmI();
		printStats(copy);
	}
	std::cout << std::endl;

	std::cout << "--- Copy assignment operator ---" << std::endl;
	{
		DiamondTrap assigned;
		assigned.whoAmI();
		assigned = d;
		assigned.whoAmI();
		printStats(assigned);
	}
	std::cout << std::endl;

	std::cout << "--- Destruction ---" << std::endl;
	return 0;
}
