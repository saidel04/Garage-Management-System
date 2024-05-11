#include "Repair.h"
#include "Garage.h"
#include <iostream>

const std::string Repair::NOTCOMPLETE = "Not Complete";

Repair::Repair(int repairCode, double cost)
    : repairCode(repairCode), cost(cost), mechanicId(NOTCOMPLETE) {}

bool Repair::isComplete() const {
    return mechanicId != NOTCOMPLETE;
}

void Repair::completeRepair(const std::string& mechanicId) {
    this->mechanicId = mechanicId;
}

void Repair::print() const {
     std::string description = Garage::REPAIRS[this->repairCode];

    cout << "Mechanic ID: "<< mechanicId << "Description: " << description <<endl;
}

