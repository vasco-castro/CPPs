
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	
	std::cout << "Scope is closed and destructors are called." << std::endl << std::endl;

	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	
	std::cout << "Scope is closed and destructors are called." << std::endl << std::endl;

	{
		HumanB dave("Dave");
		dave.attack(); // No weapon set, should handle gracefully
		Weapon spear = Weapon("long spear");
		dave.setWeapon(spear);
		dave.attack();
	}
	
	std::cout << "Scope is closed and destructors are called." << std::endl;

	return 0;
}
