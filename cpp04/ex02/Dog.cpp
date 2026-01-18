#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal() {
  this->_type = "Dog";
  this->_brain = new Brain();
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->_brain = new Brain(*other._brain); // Deep copy
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    delete this->_brain;
    this->_brain = new Brain(*other._brain); // Deep copy
  }
  return *this;
}

Dog::~Dog() {
  delete this->_brain;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "Woof!" << std::endl; }

Brain *Dog::getBrain() const { return this->_brain; }
