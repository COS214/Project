#include "MeatChef.h"

void MeatChef::prepareOrder(Command* order, Waiter* currWaiter) {
	std::cout << "Meat Chef is preparing & removing from Inventory. " << std::endl;
    Dish* dish = order->order->getCustomer()->getDish();
    for (const std::string& ingredient : dish->getList()) {
        // Check if the ingredient is vegetable-related
        if (isMeat(ingredient)) {
            // Call the removeFromInventory function to decrement the quantity
            // cout<<"Meat Chef is removing "<<ingredient<<" from inventory"<<endl;
            inventory->removeFromInventory(ingredient, 1);
        }
    }
    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter);
}

bool MeatChef::isMeat(string item)
{
    // Check if the ingredient is meat-related
    if ( item == "Parmesan Cheese" || item == "Mozzarella Cheese" || item == "Mascarpone Cheese" ||item == "Chicken" || item == "Beef" || item == "Pork" || item == "Lamb" || item == "Turkey") {
        return true;
    }   
}

void MeatChef::cook(std::string dish) {
        std::cout << "Meat chef is cooking " << dish << std::endl;
        this->mediator->notify(this, "cook");
}