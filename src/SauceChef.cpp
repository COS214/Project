#include "SauceChef.h"

void SauceChef::prepareOrder(Command* order, Waiter* currWaiter) {
	std::cout << "Sauce Chef is preparing & removing from Inventory. " << std::endl;
    //inventory.removeFromInventory(item, int);
    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter);
}

bool SauceChef::isSauce(string item)
{
    // Check if the ingredient is sauce-related
    if (item == "Tomato Sauce" || item == "Bolognese Sauce " || item == "Black Pepper" || item == "Fresh Basil" || item == "Espresso" || item == "Cocoa Powder") {
        return true;
    }
}

void SauceChef::cook(std::string dish){
        std::cout << "Sauce chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}
