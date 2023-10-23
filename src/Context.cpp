#include "Context.h"
#include "RedState.h"

Context::Context() {
	std::cout << "Constructor 1 called" << std::endl;
    state = new RedState();
}

Context::~Context() {
    std::cout << "Destructor called" << std::endl;
    delete state;
    state = 0;
}


void Context::setState(State* state_) {
    std::cout << "setState called" << std::endl;
    delete state;
    state = state_;
}

void Context::change() {
    state->handleChange(this);
}

std::string Context::getColor() {
    return state->getColor();
}