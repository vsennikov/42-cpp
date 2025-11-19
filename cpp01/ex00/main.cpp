#include "Zombie.hpp"

int main() {
  std::cout << "--- Stack Zombie ---" << std::endl;
  randomChump("Stacker");

  std::cout << "\n--- Heap Zombie ---" << std::endl;
  Zombie *heapZombie = newZombie("Heaper");
  heapZombie->announce();
  delete heapZombie;

  return 0;
}
