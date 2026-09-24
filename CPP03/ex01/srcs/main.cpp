
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap s("Bob 2");

	s.attack("Other Trap");
	std::cout << "Energy: " << s.getEnergyPoints() << std::endl << std::endl;

	s.takeDamage(5);
	std::cout << "HitPoints: " << s.getHitPoints() << std::endl << std::endl;

	s.beRepaired(7);
	std::cout << "Energy: " << s.getEnergyPoints() << std::endl;
	std::cout << "HitPoints: " << s.getHitPoints() << std::endl << std::endl;

	s.takeDamage(8);
	std::cout << "HitPoints: " << s.getHitPoints() << std::endl << std::endl;

	s.takeDamage(2);
	std::cout << "HitPoints: " << s.getHitPoints() << std::endl;
	s.takeDamage(4);
	std::cout << "HitPoints: " << s.getHitPoints() << std::endl << std::endl;
	
	s.beRepaired(7);
	std::cout << "Energy: " << s.getEnergyPoints() << std::endl;
	std::cout << "HitPoints: " << s.getHitPoints() << std::endl << std::endl;

	s.attack("Other Trap");
	std::cout << "Energy: " << s.getEnergyPoints() << std::endl;
	
	return 0;
}
