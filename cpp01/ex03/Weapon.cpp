#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : type(type) {}

Weapon::~Weapon() {}

std::string &Weapon::getType(void) {
	return this->type;
}

void Weapon::setType(std::string newType) {
	this->type = newType;
}
