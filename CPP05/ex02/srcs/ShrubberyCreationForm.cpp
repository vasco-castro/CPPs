
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("<undefined target>") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
    throw(GradeTooLowException, GradeTooHighException): AForm("ShrubberyCreationForm", 145, 137), target(newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const {
	if (b.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if (!getSignedStatus())
    	throw FormNotSignedException();
}
