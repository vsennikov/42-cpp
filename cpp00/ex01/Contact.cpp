#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(const std::string &value) {
  this->firstName = value;
}

void Contact::setLastName(const std::string &value) { this->lastName = value; }

void Contact::setNickname(const std::string &value) { this->nickname = value; }

void Contact::setPhoneNumber(const std::string &value) {
  this->phoneNumber = value;
}

void Contact::setDarkestSecret(const std::string &value) {
  this->darkestSecret = value;
}

std::string &Contact::getFirstName() { return this->firstName; }

std::string &Contact::getLastName() { return this->lastName; }

std::string &Contact::getNickname() { return this->nickname; }

std::string &Contact::getPhoneNumber() { return this->phoneNumber; }

std::string &Contact::getDarkestSecret() { return this->darkestSecret; }

bool Contact::isEmpty() {
  return this->firstName.empty() && this->lastName.empty() &&
         this->nickname.empty() && this->phoneNumber.empty() &&
         this->darkestSecret.empty();
}
