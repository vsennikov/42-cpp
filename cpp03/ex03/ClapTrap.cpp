#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap Default Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "ClapTrap Copy Constructor called" << std::endl;
  *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor called for " << _name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout << "ClapTrap " << _name
              << " can't attack. No energy or hit points left." << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
    return;
  }
  if (amount >= _hitPoints)
    _hitPoints = 0;
  else
    _hitPoints -= amount;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " damage! Current HP: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout << "ClapTrap " << _name
              << " can't be repaired. No energy or hit points left."
              << std::endl;
    return;
  }
  _energyPoints--;
  _hitPoints += amount;
  std::cout << "ClapTrap " << _name << " repairs itself by " << amount
            << " points! Current HP: " << _hitPoints << std::endl;
}
