
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
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

void PhoneBook::print_table() const {
	int i = 0;
	if (contacts[i].getEmpty()) {
		std::cout << "Contact List is Empty!" << std::endl;
		return;
	}
	while (!contacts[i].getEmpty())
	{
		// TODO: FINISH
		std::cout << i << "|" << contacts[i].getFirstName() << "|" << contacts[i].getLastName() << std::endl;
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

void PhoneBook::search() {
	print_table();

	std::string index;
	std::cout << "Insert Contact Index > ";
	
	if (!std::getline(std::cin, index))
            throw std::runtime_error("Interrupted!");

	if (std::atoi(index.c_str()) > last_id){
		std::cout << "Index out of range!";
		return;
	}

	contacts[std::atoi(index.c_str())].print_contact_fields();
}
