#include "Seated.h"
#include "Order.h"

void Seated::handleChange(Customer* c) {
    c->setState(new Order());
}

std::string Seated::getState() {
    return "Seated";
}