
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

static void	printStats(const ClapTrap& trap) {
	std::cout << "[" << trap.getName() << "] HP: " << trap.getHitPoints()
		<< " | EP: " << trap.getEnergyPoints()
		<< " | AD: " << trap.getAttackDamage() << std::endl;
}

int main(void)
{
	std::cout << "--- Construction ---" << std::endl;
	ClapTrap c("Bob");
	ScavTrap s("Bob 2");
	FragTrap f("Bob 3");
	std::cout << std::endl;

	std::cout << "--- Starting stats ---" << std::endl;
	printStats(c);
	printStats(s);
	printStats(f);
	std::cout << std::endl;

	std::cout << "--- Same call, different trap ---" << std::endl;
	c.attack("Other Trap");
	s.attack("Other Trap");
	f.attack("Other Trap");
	std::cout << std::endl;

	std::cout << "--- What each one can do on its own ---" << std::endl;
	s.guardGate();
	f.highFivesGuys();
	std::cout << std::endl;

	std::cout << "--- Inherited ClapTrap behaviour on a FragTrap ---" << std::endl;
	f.takeDamage(5);
	f.beRepaired(7);
	printStats(f);
	std::cout << std::endl;

	std::cout << "--- Orthodox Canonical Form ---" << std::endl;
	{
		FragTrap copy(f);
		FragTrap assigned;
		assigned = f;
		printStats(copy);
		printStats(assigned);
	}
	std::cout << std::endl;

	std::cout << "--- Running out of energy ---" << std::endl;
	ClapTrap drained("Weakling");
	for (int i = 0; i < 11; i++)
		drained.attack("Other Trap");
	printStats(drained);
	drained.beRepaired(5);
	std::cout << std::endl;

	std::cout << "--- Acting while dead ---" << std::endl;
	ClapTrap doomed("Goner");
	doomed.takeDamage(25);
	printStats(doomed);
	doomed.attack("Other Trap");
	doomed.beRepaired(10);
	std::cout << std::endl;

	std::cout << "--- Destruction ---" << std::endl;
	return 0;
}
