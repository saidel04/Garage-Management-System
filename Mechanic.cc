#include "Mechanic.h"
#include <iostream>

const char Mechanic::code = 'M';
int Mechanic::nextId = 1;

Mechanic::Mechanic(const std::string& name) : Entity(code, nextId++, name) {}

void Mechanic::print() const {
    std::cout << "Mechanic: ";
    Entity::print();
}

void Mechanic::resetId() {
    nextId = 1;
}
