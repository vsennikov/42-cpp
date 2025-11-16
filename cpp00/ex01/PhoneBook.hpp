#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact &contact);
	int size() const;
	const Contact &getContact(int index) const;

	static std::string formatColumn(const std::string &text);

private:
	PhoneBook(const PhoneBook &);
	PhoneBook &operator=(const PhoneBook &);

	static const int kMaxContacts = 8;
	Contact contacts[kMaxContacts];
	int count;
	int nextIndex;
};

#endif
