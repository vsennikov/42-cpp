#include "Zombie.hpp"
#include <iostream>

int main() {
  std::cout << "--- Creating Horde ---" << std::endl;
  Zombie *horde = zombieHorde(5, "HordeMember");

  if (horde == NULL) {
    std::cout << "Allocation failed or invalid size" << std::endl;
    return 1;
  }

  std::cout << "\n--- Announcing Horde ---" << std::endl;
  for (int i = 0; i < 5; i++) {
    horde[i].announce();
  }

  std::cout << "\n--- Destroying Horde ---" << std::endl;
  delete[] horde;

  return 0;
}
