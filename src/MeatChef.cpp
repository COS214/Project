#include "MeatChef.h"

void MeatChef::prepareOrder(Command order) {
	// TODO - implement MeatChef::prepareOrder
	throw "Not yet implemented";
}

void MeatChef::cook(std::string dish) {
        std::cout << "Meat chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}