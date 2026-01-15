#include "DiamondTrap.hpp"

int main() {
  std::cout << "--- Constructing DiamondTrap ---" << std::endl;
  DiamondTrap d("Monster");

  std::cout << "\n--- Testing whoAmI ---" << std::endl;
  d.whoAmI();

  std::cout << "\n--- Testing attack (ScavTrap) ---" << std::endl;
  d.attack("Target");

  std::cout << "\n--- Testing Attributes ---" << std::endl;
  std::cout << "Wait, I can't access private/protected attributes directly "
               "here to verify values unless I add getters or trust debug "
               "print/behavior. I'll rely on behavior."
            << std::endl;
  d.highFivesGuys();
  d.guardGate();

  std::cout << "\n--- Destructing ---" << std::endl;
  return 0;
}
