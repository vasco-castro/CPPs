
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>
#include <exception>

Bureaucrat::Bureaucrat(): name("<undefined>"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& newName, unsigned int newGrade) throw(GradeTooLowException, GradeTooHighException)
    : name(newName) {
    setGrade(newGrade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		setGrade(other.grade);
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::setGrade(unsigned int newGrade) throw(GradeTooLowException, GradeTooHighException) {
	if (newGrade < 1) {
		throw(GradeTooHighException());
	} else if (newGrade > 150) {
		throw(GradeTooLowException());
	}
	grade = newGrade;
}

void Bureaucrat::operator++(int) throw(GradeTooHighException) {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::operator--(int) throw(GradeTooLowException) {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

unsigned int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::signForm(AForm& form) {
	try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
