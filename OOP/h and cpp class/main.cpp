#include <iostream>
#include <string>
#include "Customer.h"
#include "Kitchen.h"
#include "Table.h"
#include "OrderManager.h"

int main() {
    int numberOfCustomers;

    std::cout << "Enter number of customers: ";
    std::cin >> numberOfCustomers;
    std::cin.ignore();  

    Kitchen kitchen;
    Table table;

    for (int i = 0; i < numberOfCustomers; ++i) {
        std::string order;

        Customer* customer = new Customer(i + 1);

        std::cout << "Enter order for Customer " << (i + 1) << ": ";
        std::getline(std::cin, order);

        customer->setOrder(order);
        table.setCustomer(customer);
    }

    OrderManager orderManager(kitchen, table);

    std::cout << "\nInitial Table Status:\n";
    table.printTableStatus();

    std::cout << "\nProcessing Orders:\n";
    orderManager.processOrders();

    std::cout << "\nFinal Table Status:\n";
    table.printTableStatus();

    for (auto customer : table.getCustomers()) {
        delete customer;
    }

    return 0;
}
