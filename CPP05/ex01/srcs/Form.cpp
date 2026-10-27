
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("<undefined>"), signedStatus(false), signGrade(150), execGrade(150) {}

Form::Form(const std::string& newName, unsigned int newSignGrade, unsigned int newExecGrade) throw(GradeTooLowException, GradeTooHighException)
    : name(newName), signedStatus(false), signGrade(newSignGrade), execGrade(newExecGrade) {
    if (execGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
    if (execGrade < 1 || signGrade < 1)
      throw GradeTooHighException();
}

Form::Form(const Form& other): name(other.name), signGrade(other.signGrade), execGrade(other.execGrade) {
	*this = other;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		signedStatus = other.signedStatus;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return name;
}

bool Form::getSignedStatus() const {
	return signedStatus;
}

unsigned int Form::getSignGrade() const {
	return signGrade;
}

unsigned int Form::getExecGrade() const { return execGrade; }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= signGrade)
        signedStatus = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	return os << f.getName() << ", is signed: " << f.getSignedStatus()
		<< ". Needs a grade of " << f.getSignedStatus() << " to be signed and "
    	<< f.getExecGrade() << " to be executed." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
