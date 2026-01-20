#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define N_ANIMALS 10

int main() {
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  delete j;
  delete i;

  std::cout << "\n--- Array of Animals ---" << std::endl;
  Animal *animals[N_ANIMALS];

  for (int i = 0; i < N_ANIMALS / 2; i++) {
    animals[i] = new Dog();
  }
  for (int i = N_ANIMALS / 2; i < N_ANIMALS; i++) {
    animals[i] = new Cat();
  }

  std::cout << "\n--- Deleting Animals ---" << std::endl;
  for (int i = 0; i < N_ANIMALS; i++) {
    delete animals[i];
  }

  std::cout << "\n--- Deep Copy Test ---" << std::endl;
  Dog basic;
  Dog tmp = basic;

  tmp.makeSound();
  basic.makeSound();

  return 0;
}
