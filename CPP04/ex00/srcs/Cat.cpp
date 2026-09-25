
#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal() {
	std::cout << "Cat Constructor called." << std::endl;
	setType("Cat");
}

Cat::Cat(const Cat& other): Animal(other) {
	std::cout << "Cat Copy Constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Assignment operator called." << std::endl;
	if (this != &other) {
		setType(other.type);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat Destructor called." << std::endl;
}

const std::string Cat::getType() const {
	return type;
}

void Cat::setType(const std::string& newType) {
	type = newType;
}

void Cat::makeSound() const {
	std::cout << "Meoowww!" << std::endl;
}
