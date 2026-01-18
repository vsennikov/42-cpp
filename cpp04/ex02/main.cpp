#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 10

int main() {
  std::cout << "--- Abstract Class Test ---" << std::endl;

  // Uncommenting the following line should cause a compilation error:
  // Animal* test = new Animal();

  std::cout << "Creating Dog and Cat objects..." << std::endl;
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << "Testing Types:" << std::endl;
  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  std::cout << "Testing Sounds:" << std::endl;
  i->makeSound(); // will output the cat sound!
  j->makeSound();

  delete j;
  delete i;

  std::cout << "\n--- Array of Animals Test (Deep Copy Check) ---" << std::endl;
  // Re-using Ex01 tests logic to ensure everything still works
  Animal *animals[N_ANIMALS];

  for (int k = 0; k < N_ANIMALS / 2; k++) {
    animals[k] = new Dog();
  }
  for (int k = N_ANIMALS / 2; k < N_ANIMALS; k++) {
    animals[k] = new Cat();
  }

  for (int k = 0; k < N_ANIMALS; k++) {
    delete animals[k];
  }

  std::cout << "\n--- Success ---" << std::endl;
  return 0;
}
