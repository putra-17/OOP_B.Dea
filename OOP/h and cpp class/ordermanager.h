#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "Kitchen.h"
#include "Table.h"

class OrderManager {
private:
    Kitchen& kitchen;
    Table& table;

public:
    OrderManager(Kitchen& kitchen, Table& table);
    void processOrders();
};

#endif
