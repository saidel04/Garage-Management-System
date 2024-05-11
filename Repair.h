#ifndef REPAIR_H
#define REPAIR_H

#include <string>

class Repair {
private:
    int repairCode;
    double cost;
    std::string mechanicId;
    static const std::string NOTCOMPLETE;

public:
    Repair(int repairCode, double cost);
    bool isComplete() const;
    void completeRepair(const std::string& mechanicId);
    void print() const;
};

#endif // REPAIR_H
