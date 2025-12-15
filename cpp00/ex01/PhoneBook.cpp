#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), nextIndex(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(Contact &contact) {
  this->contacts[this->nextIndex] = contact;
  this->nextIndex = (this->nextIndex + 1) % kMaxContacts;
  if (this->count < kMaxContacts)
    this->count++;
}

int PhoneBook::size() { return this->count; }

Contact &PhoneBook::getContact(int index) { return this->contacts[index]; }

std::string PhoneBook::formatColumn(const std::string &text) {
  if (text.size() <= 10u) {
    std::string padding;
    if (text.size() < 10u)
      padding.assign(10u - text.size(), ' ');
    return padding + text;
  }
  return text.substr(0, 9) + ".";
}
