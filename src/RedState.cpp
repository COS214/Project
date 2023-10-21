#include "RedState.h"
#include "GreenState.h"

void RedState::handleChange(Context* c) {
    c->setState(new GreenState());
}

std::string RedState::getColor() {
    return "Red";
}