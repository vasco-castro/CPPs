
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c("hey");

	c.takeDamage(5);

	std::cout << "HitPoints: " << c.getHitPoints() << std::endl;
	return 0;
}
