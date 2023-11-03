#include "Waiting.h"
#include "Seated.h"

void Waiting::handleChange(Customer* c) {
    c->setState(new Seated());
}

std::string Waiting::getState() {
    return "Waiting";
}