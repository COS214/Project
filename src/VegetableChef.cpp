#include "VegetableChef.h"

void VegetableChef::prepareOrder(Command order) {
	// TODO - implement VegetableChef::prepareOrder
	throw "Not yet implemented";
}

void VegetableChef::cook(std::string dish) {
        std::cout << "Sauce chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}