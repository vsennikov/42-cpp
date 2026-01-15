#include "FragTrap.hpp"
#include <iostream>

int main() {
  std::cout << "--- Constructing FragTrap ---" << std::endl;
  FragTrap f1("F1");

  std::cout << "\n--- Testing attack (Inherited) ---" << std::endl;
  f1.attack("target"); // Uses ClapTrap::attack with damage 30

  std::cout << "\n--- Testing highFivesGuys ---" << std::endl;
  f1.highFivesGuys();

  std::cout << "\n--- Testing Copy ---" << std::endl;
  FragTrap f2(f1);

  std::cout << "\n--- Destructing ---" << std::endl;
  return 0;
}
