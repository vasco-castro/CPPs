
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c("hey");

	c.attack("Other Trap");
	std::cout << "Energy: " << c.getEnergyPoints() << std::endl;

	c.takeDamage(5);
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl;
	
	c.beRepaired(7);
	std::cout << "Energy: " << c.getEnergyPoints() << std::endl;
	std::cout << "HitPoints: " << c.getHitPoints() << std::endl;
	
	return 0;
}
