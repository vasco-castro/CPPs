
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat b1("Bob 1", 42);
    std::cout << b1 << std::endl;

    AForm f("O papel", 42, 42);
    std::cout << f << std::endl;

    b1.signForm(f);
	
	return 0;
}
