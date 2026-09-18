
#include "Contact.hpp"

Contact::Contact(
    std::string first_nameP,
    std::string last_nameP,
    std::string nicknameP,
    int phone_numberP, 
    std::string darkest_secretP
): 
    first_name(first_nameP),
    last_name(last_nameP),
    nickname(nicknameP),
    phone_number(phone_numberP),
    darkest_secret(darkest_secretP)
{}

