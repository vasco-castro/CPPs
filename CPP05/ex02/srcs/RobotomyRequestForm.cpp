
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("<undefined target>") {}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget)
    : AForm("RobotomyRequestForm", 72, 45), target(newTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &b) const throw(GradeTooLowException, FormNotSignedException) {
	if (b.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if (!getSignedStatus())
        throw FormNotSignedException();
    std::cout << "DRILLING NOISES!!!" << std::endl;
    if (rand() % 2)
    	std::cout << target << " has been robotomized successfully." << std::endl;
    else
    	std::cout << "The robotomy failed." << std::endl;
}
