
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

	return 0;
}
