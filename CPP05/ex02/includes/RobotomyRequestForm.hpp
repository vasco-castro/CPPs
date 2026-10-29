

#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm: public AForm {
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target) throw(GradeTooLowException, GradeTooHighException);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

    const std::string &getTarget() const;
	void setTarget(const std::string &target);

    void execute(Bureaucrat const& executor) const;
};
