
#include <iostream>
#include <string>
#include <cstring>
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

void PhoneBook::add() {

	std::string first_name = prompt_field("first_name");
	std::string last_name = prompt_field("last_name");
	std::string nickname = prompt_field("nickname");
	std::string phone_number = prompt_field("phone_number");
	std::string darkest_secret = prompt_field("darkest_secret");

	if (last_id++ == MAX_CONTACTS)
		last_id = 0;
	
	contacts[last_id] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void PhoneBook::search() {
	
}
