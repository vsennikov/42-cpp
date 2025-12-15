#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();

  void addContact(Contact &contact);
  int size();
  Contact &getContact(int index);

  static std::string formatColumn(const std::string &text);

private:
  static const int kMaxContacts = 8;
  Contact contacts[kMaxContacts];
  int count;
  int nextIndex;
};

#endif
