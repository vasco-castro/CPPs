
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("<undefined target>") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
    throw(GradeTooLowException, GradeTooHighException): AForm("ShrubberyCreationForm", 145, 137), target(newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const throw(GradeTooLowException, FormNotSignedException) {
	if (b.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if (!getSignedStatus())
          throw FormNotSignedException();

    std::string target_file(target + "_shrubbery");
    std::ofstream file(target_file.c_str(), std::ios::app);

    if (!file.is_open())
    	throw std::runtime_error("Unable to open file!");

    file << "ASCII trees" << std::endl;

    file.close();
}
