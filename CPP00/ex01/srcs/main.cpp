
#include <iostream>
#include <string>
#include <cstring>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook pb;
    std::string input;

    while(true) {
        std::cout << "Command > ";
        if (!std::getline(std::cin, input))
            return 1;
        else if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
            pb.search();
        else if (input == "EXIT")
            break;
        else 
            continue;
    }

    return 0;
}
