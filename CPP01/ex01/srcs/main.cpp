
#include "Zombie.hpp"

int main(void) {

	int hordeSize = 5;
	Zombie* horde = zombieHorde(hordeSize, "Jonny");
	if (horde == NULL)
		return 1;

    for(int i = 0; i < hordeSize; i++){
        std::cout << i << " : ";
		horde[i].announce();
	}

	delete []horde;
	return 0;
}
