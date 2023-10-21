#include "GreenState.h"
#include "AmberState.h"

void GreenState::handleChange(Context* c) {
    c->setState(new AmberState());
}

std::string GreenState::getColor() {
    return "Green";
}