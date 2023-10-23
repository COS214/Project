#include "Rate.h"
#include "Pay.h"

void Rate::handleChange(Customer* c) {
    c->setState(new Pay());
}

std::string Rate::getState() {
    return "Rate";
}