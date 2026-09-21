
#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(): empty(true) {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret):
	empty(false), firstName(firstName), lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

bool Contact::getEmpty() const {
	return (this->empty);
}

const std::string &Contact::getFirstName() const {
	return (this->firstName);
}

const std::string &Contact::getLastName() const {
	return (this->lastName);
}

const std::string &Contact::getNickname() const {
	return (this->nickname);
}

const std::string &Contact::getPhoneNumber() const {
	return (this->phoneNumber);
}

const std::string &Contact::getDarkestSecret() const {
	return (this->darkestSecret);
}

void Contact::printContactFields() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
