#include "Zombie.hpp"
# include <iostream>

int main() {
  std::cout << "--- Stack Zombie ---" << std::endl;
  randomChump("Stack'er");

  std::cout << "\n--- Heap Zombie ---" << std::endl;
  Zombie *heapZombie = newZombie("Heap'er");
  heapZombie->announce();
  delete heapZombie;

  return 0;
}
