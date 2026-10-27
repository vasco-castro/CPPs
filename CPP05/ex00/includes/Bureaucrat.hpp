
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include <iostream>

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
	
    class GradeTooLowException : public std::exception {
    public:
    	const char* what() const throw();
    };  
private:
	const std::string	name;
	unsigned int		grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& newName, unsigned int newGrade) throw(GradeTooLowException, GradeTooHighException);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void operator++(int) throw(GradeTooHighException);
	void operator--(int) throw(GradeTooLowException);

    void setGrade(unsigned int newGrade) throw(GradeTooLowException, GradeTooHighException);

	const std::string& getName() const;
	unsigned int getGrade() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& fixed);

#endif // BUREAUCRAT_HPP
