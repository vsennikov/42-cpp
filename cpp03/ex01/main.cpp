#include "ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << "--- Constructing ScavTrap ---" << std::endl;
  ScavTrap s1("S1");
  ScavTrap s2;

  std::cout << "\n--- Testing attack ---" << std::endl;
  s1.attack("dummy");

  std::cout << "\n--- Testing guardGate ---" << std::endl;
  s1.guardGate();

  std::cout << "\n--- Testing Copy ---" << std::endl;
  ScavTrap s3(s1);

  std::cout << "\n--- Destructing ---" << std::endl;
  return 0;
}
