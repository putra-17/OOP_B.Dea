#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int number;
    int emotions;
    std::string order;

public:
    Customer(int number, int emotions = 5);

    // Getters and setters for emotions
    int getEmotions() const;
    void setEmotions(int emotionValue);
    void decreaseEmotions(int amount);

    // Order-related functionality
    void setOrder(const std::string& newOrder);
    std::string getOrder() const;

    // Get customer number
    int getNumber() const;

    // Print customer info
    void printStatus() const;
};

#endif
