/**
 * @file Rate.cpp
 * @brief Contains the declaration of the Rate class functions.
 */

#include "Rate.h"
#include "Pay.h"

void Rate::handleChange(Customer* c) {
    c->setState(new Pay());
}

std::string Rate::getState() {
    return "Rate";
}