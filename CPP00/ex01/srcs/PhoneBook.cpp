
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <stdexcept>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): lastId(0) {}

static bool strIsEmpty(std::string str) {
	std::string::const_iterator it;

	for (it = str.begin(); it != str.end(); it++)
		if (!std::isspace(static_cast<unsigned char>(*it))) return false;
	return true;
}

static std::string promptField(std::string fieldName) {
	std::string field("");
	while (strIsEmpty(field)) {
		std::cout << "Insert " << fieldName << " > ";

		if (!std::getline(std::cin, field))
			throw std::runtime_error("Interrupted!");
	}
	return field;
}

void PhoneBook::add() {
	// Prompt the User for the Contact fields
	std::string firstName = promptField("First Name");
	std::string lastName = promptField("Last Name");
	std::string nickname = promptField("Nickname");
	std::string phoneNumber = promptField("Phone Number");
	std::string darkestSecret = promptField("Darkest Secret");

	contacts[lastId] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	lastId++;
	if (lastId == MAX_CONTACTS)
		lastId = 0;
}

static std::string trimColumn(std::string column) {
	if (column.length() > 10)
		return column.substr(0, 9) + '.';
	return column;
}

void PhoneBook::printTable() const {
	int i = 0;
	if (contacts[0].getEmpty()) {
		std::cout << "Contact List is Empty!" << std::endl;
		return;
	}

	// Print header
	std::cout << "|" << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;

	while (i < MAX_CONTACTS && !contacts[i].getEmpty())
	{
		// Print actual Contact content
		std::cout << "|" << std::setw(10) << i << "|"
			<< std::setw(10) << trimColumn(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << trimColumn(contacts[i].getLastName()) << "|"
			<< std::setw(10) << trimColumn(contacts[i].getNickname()) << "|" << std::endl;
		i++;
	}
}

static bool numberHasChars(std::string str) {
	std::string::const_iterator it;

	for (it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(static_cast<unsigned char>(*it))) return true;
	return false;
}

void PhoneBook::search() {
	printTable();

	std::string index;
	std::cout << "Insert Contact Index > ";

	if (!std::getline(std::cin, index))
			throw std::runtime_error("Interrupted!");

	if (numberHasChars(index) || index.empty() || index.length() > 2){
		std::cout << "None valid index!" << std::endl;
		return;
	}

	int id = std::atoi(index.c_str());
	if (id < 0 || id >= MAX_CONTACTS || contacts[id].getEmpty()){
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	contacts[id].printContactFields();
}
