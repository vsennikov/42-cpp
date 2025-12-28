#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
  int _fixedPointValue;
  static const int _fractionalBits = 8;

public:
  Fixed();
  Fixed(const int n);
  Fixed(const float n);
  Fixed(const Fixed &src);
  ~Fixed();

  Fixed &operator=(const Fixed &rhs);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
