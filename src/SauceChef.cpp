#include "SauceChef.h"

void SauceChef::prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) {
	std::cout << "Sauce Chef is preparing & removing from Inventory. " << std::endl;

    Dish* dish = order->order->getCustomer()->getDish();
    for (const std::string& ingredient : dish->getList()) {
        // Check if the ingredient is vegetable-related
        if (isSauce(ingredient)) {
            // Call the removeFromInventory function to decrement the quantity
            // cout<<"Sauce Chef is removing "<<ingredient<<" from inventory"<<endl;
             Chefs::inventory->removeFromInventory(ingredient, 1);
        }
    }

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter, cookStrategy);
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
