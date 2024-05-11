#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Entity.h"
#include "Car.h"

class Customer : public Entity {
public:
    static const char code;
    static int nextId;

    Car car; // Each customer has a single car

    Customer(const std::string& name, const std::string& make, const std::string& model, int year);
    void print() const override;

    static void resetId();
};

#endif // CUSTOMER_H
