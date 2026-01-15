#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
  _name = "Default";
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 30;
  std::cout << "DiamondTrap Default Constructor called for " << _name
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  _name = name;
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 30;
  std::cout << "DiamondTrap Constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  _name = other._name;
  std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap Copy Assignment Operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    _name = other._name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap name: " << _name
            << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
