#include <iostream>
#include "Customer.h"
#include "Waiter.h"
#include "JuniorChef.h"
#include "VegetableChef.h"
#include "MeatChef.h"
#include "SauceChef.h"
#include "HeadChef.h"
#include "Order.h"
#include "Chefs.h"
#include "KitchenOrder.h"
#include "Inventory.h"

void StateTest(){
    std::cout << "<=============================== State Unit Testing ===============================>" << std::endl;

    Customer* customer = new Customer();
    for (int i = 0; i < 10; i++) {
        std::string currentTLcolour = customer->getState();
        std::cout << "Customer is currently: " << currentTLcolour << std::endl;
        customer->change();
    }
    delete customer;
}

void CommandChainSingletonTest(){
    std::cout << "<=============================== Command Chain Singleton Unit Testing ===============================>" << std::endl;

    Inventory* inventory = Inventory::getInstance();
    map<string, int> inv;
    inv["Tomato"] = 10;
    inv["Lettuce"] = 10;
    inv["Bacon"] = 10;
    inventory->initializeInventory(inv);


    JuniorChef* junior = new JuniorChef();
    VegetableChef* vegetable = new VegetableChef();
    MeatChef* meat = new MeatChef();
    SauceChef* sauce = new SauceChef();
    HeadChef* head = new HeadChef();

    junior->setNext(vegetable);
    vegetable->setNext(meat);
    meat->setNext(sauce);
    sauce->setNext(head);

    Waiter* waiter = new Waiter();
    Order* custorder = new Order();
    Command* order = new KitchenOrder(custorder);
    waiter->placeOrder(junior, order);

    delete junior;
    delete vegetable;
    delete meat;
    delete sauce;
    delete head;
    delete waiter;
    delete order;
    delete custorder;
}




int main(){

    //StateTest();
    CommandChainSingletonTest();

    return 0;
}