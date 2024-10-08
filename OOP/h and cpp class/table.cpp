#include "Table.h"
#include <iostream>

void Table::setCustomer(Customer* customer) {
    customers.push_back(customer);
}

void Table::printTableStatus() const {
    for (const auto& customer : customers) {
        customer->printStatus();
    }
}

const std::vector<Customer*>& Table::getCustomers() const {
    return customers;
}
