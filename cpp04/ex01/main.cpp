#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 10

int main() {
  std::cout << "--- Subject Test ---" << std::endl;
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j;
  delete i;

  std::cout << "\n--- Array of Animals Test ---" << std::endl;
  Animal *animals[N_ANIMALS];

  for (int k = 0; k < N_ANIMALS / 2; k++) {
    animals[k] = new Dog();
  }
  for (int k = N_ANIMALS / 2; k < N_ANIMALS; k++) {
    animals[k] = new Cat();
  }

  std::cout << "\n--- Deleting Animals ---" << std::endl;
  for (int k = 0; k < N_ANIMALS; k++) {
    delete animals[k];
  }

  std::cout << "\n--- Deep Copy Test ---" << std::endl;
  Dog basic;
  {
    Dog tmp = basic;
  } // tmp is destroyed here, basic should still maintain its Brain

  std::cout << "Check if basic is still valid:" << std::endl;
  basic.makeSound();

  std::cout << "\n--- Deep Copy Modification Test ---" << std::endl;
  Dog original;
  original.getBrain()->ideas[0] = "Original Idea";

  Dog copy(original);
  std::cout << "Original Idea: " << original.getBrain()->ideas[0] << std::endl;
  std::cout << "Copy Idea: " << copy.getBrain()->ideas[0] << std::endl;

  copy.getBrain()->ideas[0] = "New Idea";
  std::cout << "Modified Copy Idea to 'New Idea'" << std::endl;

  std::cout << "Original Idea: " << original.getBrain()->ideas[0] << std::endl;
  std::cout << "Copy Idea: " << copy.getBrain()->ideas[0] << std::endl;

  if (original.getBrain()->ideas[0] == "Original Idea") {
    std::cout << "SUCCESS: Deep copy confirmed!" << std::endl;
  } else {
    std::cout << "FAILED: Shallow copy detected!" << std::endl;
  }

  return 0;
}
