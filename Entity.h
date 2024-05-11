#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "RepairList.h" // Ensure RepairList class follows the private member variable requirement

class Entity {
private:
    std::string name;
    std::string id;
    RepairList repairs;

public:
    std::string getName() const;
    std::string getId() const;
    Entity(char code, int num, const std::string& name);
    bool hasRepairs() const;
    void addRepair(Repair* repair);
    Repair* getNextRepair();
    virtual void print() const;
    void printRepairs() const;
};

#endif // ENTITY_H
