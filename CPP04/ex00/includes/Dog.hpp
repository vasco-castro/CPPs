
#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		const std::string getType() const;
		void setType(const std::string& newType);

		void makeSound() const;
};

#endif // DOG_HPP
