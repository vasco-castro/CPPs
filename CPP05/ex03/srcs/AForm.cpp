
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("<undefined>"), signedStatus(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string& newName, int newSignGrade, int newExecGrade)
    : name(newName), signedStatus(false), signGrade(newSignGrade), execGrade(newExecGrade) {
    if (execGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
    if (execGrade < 1 || signGrade < 1)
      throw GradeTooHighException();
}

AForm::AForm(const AForm& other): name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	*this = other;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		signedStatus = other.signedStatus;
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return name;
}

bool AForm::getSignedStatus() const {
	return signedStatus;
}

int AForm::getSignGrade() const {
	return signGrade;
}

int AForm::getExecGrade() const { return execGrade; }

void AForm::beSigned(const Bureaucrat& b) throw(GradeTooLowException) {
	if (b.getGrade() > signGrade)
		throw GradeTooLowException();
    signedStatus = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	return os << f.getName() << ", is signed: " << f.getSignedStatus()
		<< ". Needs a grade of " << f.getSignGrade() << " to be signed and "
    	<< f.getExecGrade() << " to be executed." << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form not signed!";
}
