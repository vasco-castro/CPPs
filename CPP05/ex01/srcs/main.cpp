
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b1("Bob 1", 42);
    std::cout << b1;

    Form f("O papel", 42, 42);
    std::cout << f;

    b1.signForm(f);

    Bureaucrat b2("Bob 2", 150);
    std::cout << std::endl << b2;

    b2.signForm(f);

    std::cout << std::endl << "--- invalid constructor grades ---" << std::endl;
    try {
        Form tooHigh("Too High", 0, 42);
        std::cout << tooHigh;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Form tooLow("Too Low", 42, 151);
        std::cout << tooLow;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat b3("Bob 3", 151);
        std::cout << b3;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
