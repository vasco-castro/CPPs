
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {

	Contact contacts[MAX_CONTACTS];
		
	void addContact(Contact);

	public:
		PhoneBook();
		void search();
		void add();
		void exit();
};

#endif