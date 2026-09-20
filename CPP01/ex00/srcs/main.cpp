
#include "Zombie.hpp"

int main(void) {

	Zombie dude("Duuuuuuude");
	dude.announce();

	randomChump("Ze");

	Zombie *carlos = newZombie("Carlos");
	carlos->announce();
	delete carlos;

	return 0;
}
