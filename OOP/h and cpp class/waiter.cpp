#include "Waiter.h"
#include <iostream>

void Waiter::deliverOrderToTable(std::shared_ptr<Table> table, std::shared_ptr<Customer> customer)
{
    auto order = table->getOrder();
    if (order && order->getStatus() == Order::Status::SERVED)
    {
        std::cout << "Pelayan mengantarkan pesanan ke meja " << table->getTableNumber() << ": " << order->toString() << std::endl;
        customer->setMaxSatisfaction();
    }
    else
    {
        std::cout << "Pesanan belum siap untuk diantarkan ke meja " << table->getTableNumber() << std::endl;
    }
}

void Waiter::pickUpOrderFromKitchen(std::shared_ptr<Order> order, Kitchen &kitchen)
{
    if (order->getStatus() == Order::Status::SERVED)
    {
        std::cout << "Pelayan mengambil pesanan dari dapur: " << order->toString() << std::endl;
    }
    else
    {
        std::cout << "Pesanan belum siap untuk diambil dari dapur." << std::endl;
    }
}
