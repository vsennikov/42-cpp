#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
  // std::cout << "Int constructor called" << std::endl;
  this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
  // std::cout << "Float constructor called" << std::endl;
  this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  // std::cout << "Copy assignment operator called" << std::endl;
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

/* Comparison operators */
bool Fixed::operator>(const Fixed &rhs) const {
  return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
  return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
  return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return this->getRawBits() != rhs.getRawBits();
}

/* Arithmetic operators */
Fixed Fixed::operator+(const Fixed &rhs) const {
  return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  return Fixed(this->toFloat() / rhs.toFloat());
}

/* Increment/Decrement operators */
Fixed &Fixed::operator++(void) {
  this->_fixedPointValue++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  this->_fixedPointValue++;
  return tmp;
}

Fixed &Fixed::operator--(void) {
  this->_fixedPointValue--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  this->_fixedPointValue--;
  return tmp;
}

/* Static member functions */
Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return a;
  return b;
}
