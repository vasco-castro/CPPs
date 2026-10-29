
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	srand(time(NULL));

	Bureaucrat b1("Bob 1", 42);
    std::cout << b1;

    PresidentialPardonForm ppf("Qual papel?");
    std::cout << std::endl << ppf;
    b1.signForm(ppf);
    b1.executeForm(ppf);

    ShrubberyCreationForm scf("O papel");
    std::cout << std::endl << scf;
    b1.signForm(scf);
    b1.executeForm(scf);

    RobotomyRequestForm rrf("Mas qual papel?");
    std::cout << std::endl << rrf;
    b1.signForm(rrf);
    b1.executeForm(rrf);

    std::cout << std::endl << "--- executing an unsigned form ---" << std::endl;
    RobotomyRequestForm unsignedForm("Unsigned");
    b1.executeForm(unsignedForm);

    std::cout << std::endl << "--- signed, but grade too low to execute ---" << std::endl;
    Bureaucrat b2("Bob 2", 140);
    std::cout << b2;
    ShrubberyCreationForm scf2("O papel");
    b2.signForm(scf2);
    b2.executeForm(scf2);

    std::cout << std::endl << "--- grade 1 can do everything ---" << std::endl;
    Bureaucrat boss("Boss", 1);
    std::cout << boss;
    boss.signForm(ppf);
    boss.executeForm(ppf);

    std::cout << std::endl << "--- shrubbery file can't be created ---" << std::endl;
    ShrubberyCreationForm badTarget("no_such_dir/tree");
    boss.signForm(badTarget);
    boss.executeForm(badTarget);

	return 0;
}
