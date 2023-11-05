#include "VegetableChef.h"

void VegetableChef::prepareOrder(Command* order, Waiter* currWaiter) {
	std::cout << "Vegetable Chef is preparing & removing from Inventory. " << std::endl;

    Dish* dish = order->order->getCustomer()->getDish();
    // cout<<"\n========================\n"<<endl;
    for (string ingredient : dish->getList()) {
        // Check if the ingredient is vegetable-related
        if (isVegetable(ingredient)) {
            // Call the removeFromInventory function to decrement the quantity
            // cout<<"Vegetable Chef is removing "<<ingredient<<" from inventory"<<endl;
             Chefs::inventory->removeFromInventory(ingredient, 1);
        }
    }

    order->execute();
    this->mediator->notify(this, "cook");
    Chefs::prepareOrder(order, currWaiter);
    
}

void VegetableChef::cook(std::string dish) {
    std::cout << "Sauce chef is cooking " << dish << std::endl;
    this->mediator->notify(this, "cook");
}

bool VegetableChef::isVegetable(string item) {
    // Check if the ingredient is vegetable-related
    if (item == "LadyFingers" || item == "Vegetable Broth" || item == "Tomatoes" || item == "Beans" || item == "Spaghetti" || item == "Pancetta" || item == "Pizza Dough" || item == "Lasagna Sheets" || item == "Pasta" || item == "Onions") {
        return true;
    }
    return false;
}