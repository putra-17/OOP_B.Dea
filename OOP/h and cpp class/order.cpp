#include "Order.h"
#include <iostream>

Order::Order(const std::string &description) : description(description), status(Status::NOT_YET_TAKEN) {}

void Order::setStatus(Status newStatus)
{
    status = newStatus;
}

Order::Status Order::getStatus() const
{
    return status;
}

std::string Order::statusToString() const
{
    switch (status)
    {
    case Status::NOT_YET_TAKEN:
        return "Belum Diambil \n";
    case Status::IN_KITCHEN:
        return "Sedang dimasak \n";
    case Status::SERVED:
        return "Disajikan \n";
    default:
        return "Tidak Diketahui \n";
    }
}

std::string Order::toString() const
{
    return "Pesanan: " + description + "\nStatus: " + statusToString();
}
