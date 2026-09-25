
#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal() {
	std::cout << "Dog Constructor called." << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Assignment operator called." << std::endl;
	if (this != &other) {
		setType(other.type);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called." << std::endl;
}

const std::string Dog::getType() const {
	return type;
}

void Dog::setType(const std::string& newType) {
	type = newType;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}
