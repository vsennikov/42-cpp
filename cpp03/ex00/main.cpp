#include "ClapTrap.hpp"

int main() {
  ClapTrap a("Alice");
  ClapTrap b("Bob");

  a.attack("Bob");
  b.takeDamage(0); // Testing 0 damage
  b.beRepaired(5);

  // Test energy depletion
  for (int i = 0; i < 11; ++i)
    a.attack("Bob");

  // Test damage and death
  ClapTrap c("Charlie");
  c.takeDamage(9);
  c.beRepaired(1);
  c.takeDamage(100); // Should die
  c.attack("Bob");   // Should fail
  c.beRepaired(10);  // Should fail

  return 0;
}
