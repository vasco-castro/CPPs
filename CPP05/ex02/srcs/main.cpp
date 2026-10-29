
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat b1("Bob 1", 42);
    std::cout << b1;

    ShrubberyCreationForm scf("Qual papel?");
    std::cout << std::endl << scf;
    b1.signForm(scf);
    b1.executeForm(scf);

    RobotomyRequestForm rrf("Qual papel?");
    std::cout << std::endl << rrf;
    b1.signForm(rrf);
    b1.executeForm(rrf);

    PresidentialPardonForm ppf("Qual papel?");
    std::cout << std::endl << ppf;
    b1.signForm(ppf);
    b1.executeForm(ppf);

	return 0;
}
