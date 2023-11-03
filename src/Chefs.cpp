#include "Chefs.h"

Chefs::Chefs() {
	this->nextHandler = nullptr;
}

void Chefs::prepareOrder(Command* order, Waiter* currWaiter) {
	if (nextHandler) {
        nextHandler->prepareOrder(order, currWaiter);
    }
}

void Chefs::setNext(Chefs* next) {
	this->nextHandler = next;
}

void Chefs::cook(std::string dish){
	
};

void Chefs::setMediator(Mediator* mediator) {
        this->mediator = mediator;
}
