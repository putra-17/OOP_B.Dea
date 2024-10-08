#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include "Customer.h"

class Table {
private:
    std::vector<Customer*> customers;

public:
    void setCustomer(Customer* customer);
    void printTableStatus() const;
    const std::vector<Customer*>& getCustomers() const;
};

#endif
