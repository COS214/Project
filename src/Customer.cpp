#include "Customer.h"
#include "Arrived.h"

Customer::Customer() {
	std::cout << "Customer has arrived!" << std::endl;
    state = new Arrived();
}

Customer::~Customer() {
    std::cout << "Destructor called" << std::endl;
    delete state;
    state = 0;
}


void Customer::setState(State* state_) {
    std::cout << "setState called" << std::endl;
    delete state;
    state = state_;
}

void Customer::change() {
    state->handleChange(this);
}

std::string Customer::getState() {
    return state->getState();
}