#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setFirstName(const std::string &value)
{ 
	this->firstName = value; 
}

void Contact::setLastName(const std::string &value) 
{
	this->lastName = value; 
}

void Contact::setNickname(const std::string &value) 
{
	this->nickname = value; 
}

void Contact::setPhoneNumber(const std::string &value) 
{ 
	this->phoneNumber = value; 
}

void Contact::setDarkestSecret(const std::string &value) 
{ 
	this->darkestSecret = value; 
}

const std::string &Contact::getFirstName() const 
{ 
	return this->firstName;
}

const std::string &Contact::getLastName() const 
{ 
	return this->lastName; 
}

const std::string &Contact::getNickname() const 
{ 
	return this->nickname; 
}

const std::string &Contact::getPhoneNumber() const 
{ 
	return this->phoneNumber; 
}

const std::string &Contact::getDarkestSecret() const 
{ 
	return this->darkestSecret; 
}

bool Contact::isEmpty() const
{
	return this->firstName.empty()
		&& this->lastName.empty()
		&& this->nickname.empty()
		&& this->phoneNumber.empty()
		&& this->darkestSecret.empty();
}
