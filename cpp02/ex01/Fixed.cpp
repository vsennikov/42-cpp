#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
  std::cout << "Int constructor called" << std::endl;
  this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
  std::cout << "Float constructor called" << std::endl;
  this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    this->_fixedPointValue = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }

void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const {
  return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
  return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
  o << i.toFloat();
  return o;
}
