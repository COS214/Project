/**
 * @file Order.cpp
 * @brief Contains the declaration of the Order class functions.
 */

#include "Order.h"
#include "Rate.h"

void Order::handleChange(Customer* c) {
    c->setState(new Rate());
}

std::string Order::getState() {
    return "Order";
}

void Order::setCustomer(Customer* c)
{
    this->customer = c;
}

Customer* Order::getCustomer()
{
    return this->customer;
}