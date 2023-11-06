/**
 * @file Leave.cpp
 * @brief Contains the declaration of the Leave class functions.
 */
#include "Leave.h"

void Leave::handleChange(Customer* c) {
    c->setState(new Leave());
}

std::string Leave::getState() {
    return "Leave";
}