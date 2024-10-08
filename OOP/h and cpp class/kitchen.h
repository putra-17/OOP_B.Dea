#ifndef KITCHEN_H
#define KITCHEN_H

#include <string>

class Kitchen {
public:
    // Prepare the order
    std::string prepareOrder(const std::string& order);

    // Give the order
    std::string giveOrder(const std::string& order);
};

#endif