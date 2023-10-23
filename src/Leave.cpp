#include "Leave.h"

void Leave::handleChange(Customer* c) {
    c->setState(new Leave());
}

std::string Leave::getState() {
    return "Leave";
}