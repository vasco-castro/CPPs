
#include <iostream>
#include <string>
#include <cstring>
#include "Contact.hpp"

Contact::Contact(): empty(true) {}

Contact::Contact( std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret): 
    empty(false), first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}

bool Contact::getEmpty() const {
    return (this->empty); 
}

std::string Contact::getFirstName() const {
    return (this->first_name); }

std::string Contact::getLastName() const {
    return (this->last_name);
}

std::string Contact::getNickname() const {
    return (this->nickname);
}

std::string Contact::getPhoneNumber() const {
    return (this->phone_number);
}

std::string Contact::getDarkestSecret() const {
    return (this->darkest_secret);
}

void Contact::setFirstName( std::string first_name ) {
    this->first_name = first_name;
}

void Contact::setLastName( std::string last_name ) {
    this->last_name = last_name;
}

void Contact::setNickname( std::string nickname ) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber( std::string phone_number ) {
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret( std::string darkest_secret ) {
    this->darkest_secret = darkest_secret;
}

void Contact::print_contact_fields() const {
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
