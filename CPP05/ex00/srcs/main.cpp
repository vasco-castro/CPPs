
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main(void)
{
	Bureaucrat b("My Mom", 150);
	std::cout << b << std::endl;

    try {
  		std::cout << "test 1" << std::endl;
		b--;
		std::cout << "test 2" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
    }
    std::cout << b << std::endl;

   	Bureaucrat c("My Dad", 1);
    std::cout << c << std::endl;

	try {
		c--;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << c << std::endl;

	try {
		c++;
		c++;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << c << std::endl;

	std::cout << "--- invalid constructor grades ---" << std::endl;
	try {
		Bureaucrat tooHigh("Too High", 0);
		std::cout << tooHigh;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat tooLow("Too Low", 151);
		std::cout << tooLow;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat negative("Negative", -1);
		std::cout << negative;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--- copy ---" << std::endl;
	Bureaucrat copy(c);
	std::cout << copy;

	return 0;
}
