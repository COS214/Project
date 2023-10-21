#include "AmberState.h"
#include "RedState.h"

void AmberState::handleChange(Context* c) {
    c->setState(new RedState());
}

std::string AmberState::getColor() {
    return "Amber";
}