
#include "Garage.h"
#include <iostream>
using namespace std;


const string Garage::REPAIRS[NUM_REPAIRS] = {"Oil Change", "Brake Check", "Tire Rotation", "Battery Check", "Air Filter Replacement", "Coolant Flush", "Transmission Flush", "A/C Recharge", "Engine Diagnostic", "Brake Pad Replacement"};


Garage::Garage() {}

Garage::~Garage() {
    for (auto& customer : customers) {
        delete customer;
    }
    customers.clear();
    for (auto& mechanic : mechanics) {
        delete mechanic;
    }
    mechanics.clear();
}

void Garage::addMechanic(const string& name) {
    mechanics.push_back(new Mechanic(name));
}

void Garage::addCustomer(const string& name, const string& make, const string& model, int year) {
    customers.push_back(new Customer(name, make, model, year));
}

void Garage::addRepair(const string& customerId, int repairCode, double cost) {
    // Find the customer by string ID
    Customer* foundCustomer = getCustomer(customerId);
    if (foundCustomer == nullptr) {
        cout << "Customer ID " << customerId << " not found." << endl;
        return;
    }

    // Create a new repair and add it to the found customer
    Repair* repair = new Repair(repairCode, cost);
    foundCustomer->addRepair(repair);
}


void Garage::makeNextRepair(const string& mechanicId, const string& customerId) {
    // Find the mechanic by string ID
    Mechanic* foundMechanic = nullptr;
    for (auto& mechanic : mechanics) {
        if (mechanic->getId() == mechanicId) {
            foundMechanic = mechanic;
            break;
        }
    }

    if (foundMechanic == nullptr) {
        cout << "Mechanic ID " << mechanicId << " not found." << endl;
        return;
    }

    // Find the customer by string ID
    Customer* foundCustomer = nullptr;
    for (auto& customer : customers) {
        if (customer->getId() == customerId) {
            foundCustomer = customer;
            break;
        }
    }

    if (foundCustomer == nullptr) {
        cout << "Customer ID " << customerId << " not found." << endl;
        return;
    }

    // Get the next repair for the found customer
    Repair* repair = foundCustomer->getNextRepair();
    if (repair == nullptr) {
        cout << "No repairs for the customer." << endl;
        return;
    }

    // Complete the repair and add it to the found mechanic's list of repairs
    repair->completeRepair(foundMechanic->getId());
    foundMechanic->addRepair(repair);
}


Customer* Garage::getCustomer(const std::string& id) const {
    for (const auto& customer : customers) {
        if (customer->getId() == id) {
            return customer;
        }
    }
    return nullptr;
}


Mechanic* Garage::getMechanic(const std::string& id) const {
    for (const auto& mechanic : mechanics) {
        if (mechanic->getId() == id) {
            return mechanic;
        }
    }
    return nullptr;
}


void Garage::printMechanics() const {
    cout << "Mechanics:" << endl;
    for (const auto& mechanic : mechanics) {
        mechanic->print();
    }
}

void Garage::printCustomers() const {
    cout << "Customers:" << endl;
    for (const auto& customer : customers) {
        customer->print();
    }
}

void Garage::printMechanicRepairs(const std::string& id) const {
    Mechanic* mechanic = getMechanic(id);
    if (mechanic) {
        mechanic->printRepairs();
    } else {
        cout << "Mechanic with ID " << id << " not found." << endl;
    }
}

void Garage::printCustomerRepairs(const std::string& id) const {
    Customer* customer = getCustomer(id);
    if (customer) {
        customer->print(); // This should print customer details
        customer->printRepairs(); // This should print all repair details
    } else {
        cout << "Customer with ID " << id << " not found." << endl;
    }
}



void Garage::resetIds() {
    Customer::resetId();
    Mechanic::resetId();
}