#include "JuniorChef.h"

void JuniorChef::prepareOrder(Command order) {
	// TODO - implement JuniorChef::prepareOrder
	throw "Not yet implemented";
}

void JuniorChef::cook(std::string dish) {
        std::cout << "Junior chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}