#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal copy assignment operator called" << std::endl;
  if (this != &other) {
    this->_type = other._type;
  }
  return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}
