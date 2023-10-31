#include "Chefs.h"

Chefs::Chefs() {
	this->nextHandler = nullptr;
}

void Chefs::prepareOrder(Command* order) {
	if (nextHandler) {
        nextHandler->prepareOrder(order);
    }
}

void Chefs::setNext(Chefs* next) {
	this->nextHandler = next;
}

void Chefs::cook(std::string dish){
	
};
