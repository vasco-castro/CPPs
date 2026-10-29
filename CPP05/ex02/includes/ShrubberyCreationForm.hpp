
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <stdexcept>

class ShrubberyCreationForm: public AForm {
private:
	std::string target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

    void execute(Bureaucrat const& executor) const throw(GradeTooLowException, FormNotSignedException, std::runtime_error);
};

#endif // SHRUBBERYCREATIONFORM_HPP
