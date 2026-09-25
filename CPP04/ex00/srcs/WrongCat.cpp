
#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "WrongCat Constructor called." << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat Assignment operator called." << std::endl;
	if (this != &other) {
		setType(other.type);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called." << std::endl;
}

const std::string WrongCat::getType() const {
	return type;
}

void WrongCat::setType(const std::string& newType) {
	type = newType;
}

void WrongCat::makeSound() const {
	std::cout << "Meoowww!" << std::endl;
}
