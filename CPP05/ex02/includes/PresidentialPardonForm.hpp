
#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target) throw(GradeTooLowException, GradeTooHighException);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    const std::string &getTarget() const;
	void setTarget(const std::string &target);

    void execute(Bureaucrat const& executor) const;
};
