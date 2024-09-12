#include <iostream>

enum class OrderStatus {
    NotYetTaken,
    InKitchen,
    Served
};

class Order {
private:
    std::string details;
    OrderStatus status;

public:
    Order(const std::string& details) : details(details), status(OrderStatus::NotYetTaken) {}
    void setStatus(OrderStatus status) { this->status = status; }
    OrderStatus getStatus() const { return status; }

    std::string getDetails() const { return details; }
};

class Customer {
private:
    Order order;
    int emotionLevel;  // Ranges from 1 (unhappy) to 5 (very happy)
    
public:
    Customer(const std::string& orderDetails) 
        : order(orderDetails), emotionLevel(5) {}

    void placeOrder(const std::string& orderDetails) {
        order = Order(orderDetails);
    }
    Order getOrder() const { return order; }

    void decreaseEmotion() {
        if (emotionLevel > 1) {
            emotionLevel--;
        }
    }
    void resetEmotion() { emotionLevel = 5; }
    int getEmotionLevel() const { return emotionLevel; }
    void displayEmotion() const {
        std::cout << "Customer Emotion: " << emotionLevel << "/5" << std::endl;
    }
};


class Table {
private:
    int tableNumber;
    Customer* customer;

public:
    Table(int number) : tableNumber(number), customer(nullptr) {}
    void assignCustomer(Customer* cust) { customer = cust; }
    Customer* getCustomer() const { return customer; }
    int getTableNumber() const { return tableNumber; }

    void displayOrderStatus() const {
        if (customer == nullptr) {
            std::cout << "Table " << tableNumber << " has no customer." << std::endl;
            return;
        }

        OrderStatus status = customer->getOrder().getStatus();
        std::string statusMessage;
        switch (status) {
            case OrderStatus::NotYetTaken:
                statusMessage = "Not Yet Taken";
                break;
            case OrderStatus::InKitchen:
                statusMessage = "In Kitchen";
                break;
            case OrderStatus::Served:
                statusMessage = "Served";
                break;
        }

        std::cout << "Table " << tableNumber << " - Order: " << customer->getOrder().getDetails() 
                  << " - Status: " << statusMessage << std::endl;
    }
};

class Waiter {
public:
    void takeOrder(Table& table) {
        Customer* customer = table.getCustomer();
        if (customer != nullptr && customer->getOrder().getStatus() == OrderStatus::NotYetTaken) {
            customer->getOrder().setStatus(OrderStatus::InKitchen);
            std::cout << "Waiter has taken order from Table " << table.getTableNumber() 
                      << " and sent it to the kitchen: " << customer->getOrder().getDetails() << std::endl;
        }
    }

    void prepareOrder() {
        std::cout << "Kitchen is preparing the order..." << std::endl;
        for (int i = 0; i < 5; ++i) {
            std::cout << ".";
            simulateTimePassing(); // Simulate time passing
        }
        std::cout << "\nOrder is ready!" << std::endl;
    }

    void deliverOrder(Table& table) {
        Customer* customer = table.getCustomer();
        if (customer != nullptr && customer->getOrder().getStatus() == OrderStatus::InKitchen) {
            customer->getOrder().setStatus(OrderStatus::Served);
            customer->resetEmotion();  // Reset customer emotion to 5
            std::cout << "Waiter has delivered the order to Table " << table.getTableNumber() 
                      << ": " << customer->getOrder().getDetails() << std::endl;
            customer->displayEmotion();  // Display reset emotion level
        }
    }

private:
    void simulateTimePassing() {
        for (int i = 0; i < 100000000; ++i) {}  // Simple busy loop to simulate time delay
    }
};

int main() {
    Customer customer1("Pasta");
    Table table1(1);
    table1.assignCustomer(&customer1);
    Waiter waiter;
    table1.displayOrderStatus();  // Not Yet Taken

    for (int i = 0; i < 4; ++i) {  // Simulate customer waiting for 4 "seconds"
        waiter.takeOrder(table1);  // Take the order and send to the kitchen
        table1.displayOrderStatus();  // In Kitchen
        customer1.decreaseEmotion();  // Decrease emotion as customer waits
        customer1.displayEmotion();
    }

    waiter.prepareOrder();
    waiter.deliverOrder(table1);
    table1.displayOrderStatus();  // Served

    return 0;
}
