
#include <iostream>
#include <string>
#include <stdexcept>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string input;

	try {
		while(true) {
			std::cout << "Command > ";
			if (!std::getline(std::cin, input))
				throw std::runtime_error("Interrupted!");
			else if (input == "ADD")
				pb.add();
			else if (input == "SEARCH")
				pb.search();
			else if (input == "EXIT")
				break;
			else
				std::cout << "Command is not recognized!" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << std::endl << e.what() << std::endl;
	}

	return 0;
}
