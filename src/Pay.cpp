/**
 * @file Pay.cpp
 * @brief Contains the declaration of the Pay class functions.
 */

#include "Pay.h"
#include "Leave.h"

void Pay::handleChange(Customer* c) {
    c->setState(new Leave());
}

std::string Pay::getState() {
    return "Pay";
}