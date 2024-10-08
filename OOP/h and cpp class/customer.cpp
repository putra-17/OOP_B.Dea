#include "Customer.h"
#include <iostream>
#include <algorithm>

Customer::Customer(int number, int emotions) : number(number), emotions(emotions) {}

int Customer::getEmotions() const { return emotions; }

void Customer::setEmotions(int emotionValue) { emotions = std::min(emotionValue, 5); }

void Customer::decreaseEmotions(int amount) { emotions = std::max(emotions - amount, 0); }

void Customer::setOrder(const std::string& newOrder) { order = newOrder; }

std::string Customer::getOrder() const { return order; }

int Customer::getNumber() const { return number; }

void Customer::printStatus() const {
    std::cout << "Customer " << number << " has emotion level: " << emotions
              << " and ordered: " << order << std::endl;
}
