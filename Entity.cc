#include "Entity.h"
#include <iostream>

Entity::Entity(char code, int num, const std::string& name)
    : name(name), id(std::string(1, code) + std::to_string(num)) {}

bool Entity::hasRepairs() const {
    return !repairs.isEmpty();
}

void Entity::addRepair(Repair* repair) {
    repairs.add(repair);
}

Repair* Entity::getNextRepair() {
    return repairs.getNext();
}

void Entity::print() const {
    std::cout << "Entity ID: " << id << " Name: " << name << " Repair Count: " << repairs.size() << std::endl;
}

void Entity::printRepairs() const {
    repairs.print();
}

std::string Entity::getId() const {
    return id;
}

std::string Entity::getName() const {
    return name;
}
