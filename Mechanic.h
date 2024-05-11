#ifndef MECHANIC_H
#define MECHANIC_H

#include "Entity.h"

class Mechanic : public Entity {
public:
    static const char code;
    static int nextId;

    Mechanic(const std::string& name);
    void print() const override;

    static void resetId();
};

#endif // MECHANIC_H
