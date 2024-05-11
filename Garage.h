#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include <string>
#include "Customer.h"
#include "Mechanic.h"

using namespace std;

class Garage {
public:
    static const int NUM_REPAIRS = 10;
    static const string REPAIRS[NUM_REPAIRS]; 

private:
    vector<Customer*> customers;
    vector<Mechanic*> mechanics;

public:
    Garage();
    ~Garage();

    void addMechanic(const string& name);
    void addCustomer(const string& name, const string& make, const string& model, int year);
    void addRepair(const string& customerId, int repairCode, double cost);
    void makeNextRepair(const string& mechanicId, const string& customerId);
    void printMechanics() const;
    void printCustomers() const;
    void printMechanicRepairs(const std::string& id) const;
    void printCustomerRepairs(const std::string& id) const;
    Mechanic* getMechanic(const std::string& id) const;
    Customer* getCustomer(const std::string& id) const;


    static void resetIds();
};

#endif // GARAGE_H
