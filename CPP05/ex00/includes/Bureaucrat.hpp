
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {

	std::string name;
	unsigned int grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string newName, unsigned int newGrade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		void setGrade(unsigned int newGrade);

		const std::string& getName() const;
		unsigned int getGrade() const;

		
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& fixed);

#endif // BUREAUCRAT_HPP
