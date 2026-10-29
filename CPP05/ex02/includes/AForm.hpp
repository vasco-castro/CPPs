
#ifndef AFORM_HPP
# define AFORM_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
    	const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
private:
	const std::string	name;
  	bool				signedStatus;
	const int	signGrade;
	const int	execGrade;
public:
	AForm();
	AForm(const std::string& newName, int signGrade, int execGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

    const std::string &getName() const;
    bool getSignedStatus() const;
	int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &b) throw(GradeTooLowException);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& fixed);

#endif // AFORM_HPP
