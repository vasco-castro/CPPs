
#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm: public AForm {
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target) throw(GradeTooLowException, GradeTooHighException);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

    const std::string &getTarget() const;
	void setTarget(const std::string &target);

    void execute(Bureaucrat const& executor) const throw(GradeTooLowException, FormNotSignedException);
};
