
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): last_id(0) {}

static const std::string prompt_field(std::string fieldName) {
	std::string field("");
	while(field.empty()) {
        std::cout << "Insert " << fieldName << " > ";

        if (!std::getline(std::cin, field))
            throw std::runtime_error("Interrupted!");
		if (!field.empty())
			break;
    }
    return field;
}

static std::string trim_column(std::string column) {
	if (column.length() > 10)
		return column.substr(0, 9) + '.';
	return column;
}

void PhoneBook::print_table() const {
	int i = 0;
	if (contacts[0].getEmpty()) {
		std::cout << "Contact List is Empty!" << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << "|" << std::endl;

	while (!contacts[i].getEmpty())
	{
		// TODO: FINISH
		std::cout << "|" << std::setw(10) << i << "|"
			<< std::setw(10) << trim_column(contacts[i].getFirstName()) << "|"
			<< std::setw(10) << trim_column(contacts[i].getLastName()) << "|"
			<< std::setw(10) << trim_column(contacts[i].getNickname()) << "|" << std::endl;
		i++;
	}
}

void PhoneBook::add() {

	std::string first_name = prompt_field("first_name");
	std::string last_name = prompt_field("last_name");
	std::string nickname = prompt_field("nickname");
	std::string phone_number = prompt_field("phone_number");
	std::string darkest_secret = prompt_field("darkest_secret");

	contacts[last_id] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	last_id++;
	if (last_id == MAX_CONTACTS)
		last_id = 0;
}

static bool number_has_chars(std::string str) {
	std::string::const_iterator it;

	for (it = str.begin(); it != str.end(); it++)
		if (!std::isdigit(*it)) return true;
	return false;
}

void PhoneBook::search() {
	print_table();

	std::string index;
	std::cout << "Insert Contact Index > ";

	if (!std::getline(std::cin, index))
            throw std::runtime_error("Interrupted!");

	if (number_has_chars(index)){
		std::cout << "None valid index!" << std::endl;
		return;
	}

	int id = std::atoi(index.c_str());
	if (id < 0 || id >= MAX_CONTACTS || contacts[id].getEmpty()){
		std::cout << "Index out of range!" << std::endl;
		return;
	}

	contacts[id].print_contact_fields();
}
