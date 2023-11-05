/**
 * @file Waiting.cpp
 * @brief Contains the declaration of the Waiting class functions.
 */

#include "Waiting.h"
#include "Seated.h"

void Waiting::handleChange(Customer* c) {
    c->setState(new Seated());
}

std::string Waiting::getState() {
    return "Waiting";
}