
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b1("Bob 1", 42);
    std::cout << b1 << std::endl;

    Form f("O papel", 42, 42);
    std::cout << f << std::endl;

    b1.signForm(f);

    Bureaucrat b2("Bob 2", 150);
    std::cout << b2 << std::endl;

    b2.signForm(f);

	return 0;
}
