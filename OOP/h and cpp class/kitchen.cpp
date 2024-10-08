#include "Kitchen.h"
#include <iostream>

std::string Kitchen::prepareOrder(const std::string& order) {
    std::cout << "Kitchen is preparing: " << order << std::endl;
    return order + " is ready!";
}

std::string Kitchen::giveOrder(const std::string& order) {
    std::cout << "Kitchen is giving the order: " << order << std::endl;
    return order;
}
