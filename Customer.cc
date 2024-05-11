#include "Customer.h"
#include <iostream>

const char Customer::code = 'C';
int Customer::nextId = 1;

Customer::Customer(const std::string& name, const std::string& make, const std::string& model, int year)
    : Entity(code, nextId++, name), car(make, model, year) {}

void Customer::print() const {
    Entity::print();
    car.print();
}

void Customer::resetId() {
    nextId = 1;
}
