#include "Chefs.h"

Inventory* Chefs::inventory = nullptr;


Chefs::Chefs() {
	this->nextHandler = nullptr;
}

void Chefs::prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) {
	if (nextHandler) {
        nextHandler->prepareOrder(order, currWaiter, cookStrategy);
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
