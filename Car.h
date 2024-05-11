#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    Car(const std::string& make, const std::string& model, int year);
    void print() const;
};

#endif // CAR_H
