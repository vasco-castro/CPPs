
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("<undefined target>") {}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget)
    throw(GradeTooLowException, GradeTooHighException): AForm("PresidentialPardonForm", 25, 5), target(newTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &b) const {
	if (b.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if (!getSignedStatus())
    	throw FormNotSignedException();
}
