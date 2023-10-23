#include "Order.h"
#include "Rate.h"

void Order::handleChange(Customer* c) {
    c->setState(new Rate());
}

std::string Order::getState() {
    return "Order";
}