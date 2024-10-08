#ifndef WAITER_H
#define WAITER_H

#include <memory>
#include "Table.h"
#include "Customer.h"
#include "Kitchen.h"

class Waiter
{
public:
    void deliverOrderToTable(std::shared_ptr<Table> table, std::shared_ptr<Customer> customer);
    void pickUpOrderFromKitchen(std::shared_ptr<Order> order, Kitchen &kitchen);
};

#endif
