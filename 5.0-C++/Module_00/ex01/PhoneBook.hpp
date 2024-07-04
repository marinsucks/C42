#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int contacts_nb;
		int index;
	public:
		PhoneBook(void);
		void addContact(void);
		void searchContact(void);
		void exitPhoneBook(void);
};

#endif