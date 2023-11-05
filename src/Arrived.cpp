/**
 * @file Arrived.cpp
 * @brief Contains the implementation of the Arrived class.
 */

#include "Arrived.h"
#include "Waiting.h"

void Arrived::handleChange(Customer* c) {
    c->setState(new Waiting());
}

std::string Arrived::getState() {
    return "Arrived";
}