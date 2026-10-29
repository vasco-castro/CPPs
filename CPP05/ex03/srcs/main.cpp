
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat b1("Bob 1", 42);
    std::cout << b1;

    Intern someRandomIntern;

    AForm* scf;
    scf = someRandomIntern.makeForm("shrubbery creation", "Bob 2");
    if (scf) {
		std::cout << std::endl << *scf;

		b1.signForm(*scf);
		b1.executeForm(*scf);
		delete scf;
    }

	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bob 3");
	if (rrf) {
	    std::cout << std::endl << *rrf;

	    b1.signForm(*rrf);
	    b1.executeForm(*rrf);
		delete rrf;
	}

	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Bob 4");
	if (ppf) {
		std::cout << std::endl << *ppf;

	    b1.signForm(*ppf);
        b1.executeForm(*ppf);
        delete ppf;
	}

	AForm* none;
	none = someRandomIntern.makeForm("none form", "Bob 5");
	if (none) {
		std::cout << std::endl << *none;

	    b1.signForm(*none);
        b1.executeForm(*none);
        delete none;
	}

	return 0;
}
