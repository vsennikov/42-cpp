#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap Default Constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap Constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor called for " << _name << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (_energyPoints == 0 || _hitPoints == 0) {
    std::cout << "ScavTrap " << _name
              << " can't attack. No energy or hit points left." << std::endl;
    return;
  }
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " attacks " << target
            << " vigorously, causing " << _attackDamage << " points of damage!"
            << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode."
            << std::endl;
}
