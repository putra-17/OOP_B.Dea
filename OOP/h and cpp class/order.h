#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order
{
public:
    enum class Status
    {
        NOT_YET_TAKEN,
        IN_KITCHEN,
        SERVED
    };

    Order(const std::string &description);

    void setStatus(Status newStatus);
    Status getStatus() const;
    std::string statusToString() const;
    std::string toString() const;

private:
    std::string description;
    Status status;
};

#endif
