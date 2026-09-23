
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c("Bob");

	c.attack("Other Trap");
	std::cout << "Energy: " << c.getEnergyPoints() << std::endl << std::endl;

	c.takeDamage(5);
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl << std::endl;

	c.beRepaired(7);
	std::cout << "Energy: " << c.getEnergyPoints() << std::endl;
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl << std::endl;

	c.takeDamage(8);
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl << std::endl;

	c.takeDamage(2);
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl;
	c.takeDamage(4);
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl << std::endl;
	
	c.beRepaired(7);
	std::cout << "Energy: " << c.getEnergyPoints() << std::endl;
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl << std::endl;

	c.attack("Other Trap");
	std::cout << "Energy: " << c.getEnergyPoints() << std::endl;
	
	return 0;
}
