
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("<undefined>"), grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade)
	: name(newName), grade(newGrade) {
	std::cout << "Name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		setGrade(other.grade);
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor called" << std::endl;
}

void Bureaucrat::setGrade(unsigned int newGrade) {
	grade = newGrade;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

unsigned int Bureaucrat::getGrade() const {
	return grade;
}

// TODO: Change the message outputed by this stream.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	return os << b.getName() << " - " << b.getGrade();
}