
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>
#include <string>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string formTarget) {
	const std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    size_t i = 0;
    while (i < 3 && formName.compare(forms[i]) != 0) {
    	i++;
    }

	switch (i) {
		case 0: return new ShrubberyCreationForm(formTarget);
		case 1: return new RobotomyRequestForm(formTarget);
		case 2: return new PresidentialPardonForm(formTarget);
    }

    std::cerr << "Form '" << formName << "' not found" << std::endl;
    return NULL;
}
