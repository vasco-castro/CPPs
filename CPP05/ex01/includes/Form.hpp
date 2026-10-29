
#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>
# include <iostream>

class Bureaucrat;

class Form {
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
	const int	signGrade;
	const int	execGrade;
public:
	Form();
	Form(const std::string& newName, int signGrade, int execGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

    const std::string &getName() const;
    bool getSignedStatus() const;
	int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& fixed);

#endif // FORM_HPP
