
#include "Zombie.hpp"

Zombie::Zombie() {
	name = "";
}

Zombie::Zombie(std::string name): name(name){}

Zombie::~Zombie() {
	std::cout << "Bye bye " << this->name << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
