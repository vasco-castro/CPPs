
#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <string>
# include <iostream>

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
private:
	const std::string	name;
  	bool				signedStatus;
	const unsigned int	signGrade;
	const unsigned int	execGrade;
public:
	AForm();
	AForm(const std::string& newName, unsigned int signGrade, unsigned int execGrade) throw(GradeTooLowException, GradeTooHighException);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	~AForm();

    const std::string &getName() const;
    bool getSignedStatus() const;
	unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;

    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const AForm& fixed);

#endif // AFORM_HPP
