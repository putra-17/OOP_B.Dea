#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>  

class Customer {
private:
    int number;      
    int emotions;    
    std::string order;

public:
    Customer(int number, int emotions = 5) : number(number), emotions(emotions) {}

    // Getters and setters for emotions
    int getEmotions() const { return emotions; }
    void setEmotions(int emotionValue) { emotions = std::min(emotionValue, 5); } // max is 5
    void decreaseEmotions(int amount) { emotions = std::max(emotions - amount, 0); }

    // Order-related functionality
    void setOrder(const std::string& newOrder) { order = newOrder; }
    std::string getOrder() const { return order; }

    // Set customer order to empty (after serving)
    void clearOrder() { order = ""; }

    // Get customer number
    int getNumber() const { return number; }

    // Print customer info
    void printStatus() const {
        std::cout << "Customer " << number << " has emotion level: " << emotions << std::endl;
    }
};

class Kitchen {
public:
    // Prepare the order
    std::string prepareOrder(const std::string& order) {
        std::cout << "Kitchen is preparing: " << order << std::endl;
        return order + " is ready!";
    }

    // Give the order
    std::string giveOrder(const std::string& order) {
        std::cout << "Kitchen is giving the order: " << order << std::endl;
        return order;
    }
};

class Table {
private:
    std::vector<Customer*> customers;
    int tableNumber;

public:
    Table(int tableNumber) : tableNumber(tableNumber) {}

    // Set customers for the table
    void setCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    // Get table status
    void printTableStatus() const {
        for (const auto& customer : customers) {
            customer->printStatus();
        }
    }

    // Get all customers
    const std::vector<Customer*>& getCustomers() const { return customers; }

    // Get table number
    int getTableNumber() const { return tableNumber; }
};

class OrderManager {
private:
    Kitchen& kitchen;
    Table& table;

public:
    OrderManager(Kitchen& kitchen, Table& table) : kitchen(kitchen), table(table) {}

    // Set the order from customers and manage the flow
    void processOrders() {
        const std::vector<Customer*>& customers = table.getCustomers();

        for (size_t i = 0; i < customers.size(); ++i) {
            auto customer = customers[i];
            std::string order = customer->getOrder();
            if (!order.empty()) {
                // Prepare and serve the order with a delay
                std::string preparedOrder = kitchen.prepareOrder(order);
                
                std::this_thread::sleep_for(std::chrono::seconds(2)); // Delay of 2 seconds
                
                std::string servedOrder = kitchen.giveOrder(preparedOrder);
                std::cout << "Served Customer " << customer->getNumber() 
                          << " with: " << servedOrder << std::endl;

                // After serving, replace order with table number
                customer->setOrder("Table " + std::to_string(table.getTableNumber()));

                // Decrease emotions based on queue position
                int waitTime = static_cast<int>(i) * 1;  // Change emotional decrease to be 1 per position
                customer->decreaseEmotions(waitTime);
            }
        }
    }
};

// Main function to simulate the game with user input
int main() {
    int numberOfCustomers, tableNumber;

    // Ask for the number of customers
    std::cout << "Enter number of customers: ";
    std::cin >> numberOfCustomers;
    std::cin.ignore();  // Ignore newline after input

    // Create a kitchen and a table
    Kitchen kitchen;
    Table table(tableNumber);

    // Collect input for each customer
    for (int i = 0; i < numberOfCustomers; ++i) {
        std::string order;

        // Create customer object using their number
        Customer* customer = new Customer(i + 1); // Customer number starts from 1

        // Get customer order
        std::cout << "Enter table and order for Customer " << (i + 1) << ": ";
        std::getline(std::cin, order);

        // Set the order for the customer
        customer->setOrder(order);

        // Add customer to the table
        table.setCustomer(customer);
    }

    // Create an order manager to manage the orders
    OrderManager orderManager(kitchen, table);

    // Print initial table status
    std::cout << "\nInitial Table Status:\n";
    table.printTableStatus();

    // Process orders
    std::cout << "\nProcessing Orders:\n";
    orderManager.processOrders();

    // Print final table status
    std::cout << "\nFinal Table Status:\n";
    table.printTableStatus();

    // Clean up dynamically allocated customers
    for (auto customer : table.getCustomers()) {
        delete customer;
    }

    return 0;
}
