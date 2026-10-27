
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("<undefined>"), grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade) throw(GradeTooLowException, GradeTooHighException)
    : name(newName) {
    setGrade(newGrade);
	std::cout << "Name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) throw(GradeTooLowException, GradeTooHighException) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) throw(GradeTooLowException, GradeTooHighException) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		setGrade(other.grade);
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

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

unsigned int Bureaucrat::getGrade() const {
	return grade;
}

// TODO: Change the message outputed by this stream.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
