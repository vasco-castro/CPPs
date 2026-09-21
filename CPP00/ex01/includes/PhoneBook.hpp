
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {

	Contact contacts[MAX_CONTACTS];
	int	lastId;

	public:
		PhoneBook();
		void add();
		void search();

		void printTable() const;
};

#endif // PHONEBOOK_HPP
