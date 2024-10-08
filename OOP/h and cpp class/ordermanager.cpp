#include "OrderManager.h"
#include <iostream>

OrderManager::OrderManager(Kitchen& kitchen, Table& table) : kitchen(kitchen), table(table) {}

void OrderManager::processOrders() {
    const std::vector<Customer*>& customers = table.getCustomers();

    for (size_t i = 0; i < customers.size(); ++i) {
        auto customer = customers[i];
        std::string order = customer->getOrder();
        if (!order.empty()) {
            std::string preparedOrder = kitchen.prepareOrder(order);
            std::string servedOrder = kitchen.giveOrder(preparedOrder);

            std::cout << "Served Customer " << customer->getNumber() << " with: " << servedOrder << std::endl;

            int waitTime = static_cast<int>(i) * 1; 
            customer->decreaseEmotions(waitTime);
        }
    }
}
