#include "Car.h"
#include <iostream>

Car::Car(const std::string& make, const std::string& model, int year)
    : make(make), model(model), year(year) {}

void Car::print() const {
    std::cout << "Car: " << make << " " << model << " Year: " << year << std::endl;
}
