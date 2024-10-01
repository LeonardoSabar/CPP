#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include "Colors.hpp"
#include "Contact.hpp"
#include "Utils.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:

		PhoneBook(void);
		~PhoneBook(void);

		int		contactCount;
		int		_index;
		void	addContact();
		void	searchContact();
		void	displayContact(Contact contact);
		void	displayMain();
};



#endif
