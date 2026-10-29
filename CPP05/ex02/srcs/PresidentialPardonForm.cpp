
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("<undefined target>") {}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget)
    : AForm("PresidentialPardonForm", 25, 5), target(newTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &b) const throw(GradeTooLowException, FormNotSignedException) {
	if (b.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if (!getSignedStatus())
    	throw FormNotSignedException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
