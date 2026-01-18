#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal() {
  this->_type = "Cat";
  this->_brain = new Brain();
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->_brain = new Brain(*other._brain); // Deep copy
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    delete this->_brain;
    this->_brain = new Brain(*other._brain); // Deep copy
  }
  return *this;
}

Cat::~Cat() {
  delete this->_brain;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }

Brain *Cat::getBrain() const { return this->_brain; }
