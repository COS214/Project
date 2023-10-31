#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

#include "Customer.h"
#include "Table.h"
#include "Waiter.h"
#include "JuniorChef.h"
#include "VegetableChef.h"
#include "MeatChef.h"
#include "SauceChef.h"
#include "HeadChef.h"
#include "Order.h"
#include "Chefs.h"
#include "Kitchen.h"
#include "KitchenOrder.h"
#include "Inventory.h"
#include "Dish.h"
#include "BasicDish.h"
#include "DishDecorator.h"
#include "AddToDish.h"
#include "RemoveFromDish.h"
#include "SpecialCookingInstructions.h"

void StateTest()
{
    std::cout << "<=============================== State and Observer Unit Testing ===============================>" << std::endl;

    Customer *customer = new Customer();
    Waiter *waiter1 = new Waiter();
    customer->attach(waiter1);
    for (int i = 0; i < 10; i++)
    {
        std::string currentTLcolour = customer->getState();
        std::cout << "Customer is currently: " << currentTLcolour << std::endl;
        customer->change();
    }
    customer->detach(waiter1);
    delete customer;
    delete waiter1;
}

void CommandChainSingletonTest()
{
    std::cout << "<=============================== Command Chain Singleton Unit Testing ===============================>" << std::endl;

    Inventory *inventory = Inventory::getInstance();
    map<string, int> inv;
    inv["Tomato"] = 10;
    inv["Lettuce"] = 10;
    inv["Bacon"] = 10;
    inventory->initializeInventory(inv);

    JuniorChef *junior = new JuniorChef();
    VegetableChef *vegetable = new VegetableChef();
    MeatChef *meat = new MeatChef();
    SauceChef *sauce = new SauceChef();
    HeadChef *head = new HeadChef();

    junior->setNext(vegetable);
    vegetable->setNext(meat);
    meat->setNext(sauce);
    sauce->setNext(head);

    Waiter *waiter = new Waiter();
    Order *custorder = new Order();
    Command *order = new KitchenOrder(custorder);
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

void DecoratorTest()
{

    std::cout << "<=============================== Decorator Unit Testing ===============================>" << std::endl;

    Dish *basicDish = new BasicDish("cheeseburger");
    std::cout << "Ingredient list: \n"
              << basicDish->getIngredientsList() << std::endl;
    std::cout << "Basic Dish - Total Cost: $" << basicDish->totalCost() << "\n"
              << std::endl;

    AddToDish *addToDish = new AddToDish("cheeseburger");
    addToDish->setCostOfIngredient(2.0);
    addToDish->setIngredient("Pickles");
    addToDish->addIngredient("Pickles");
    std::cout << "Ingredient list after adding pickles: \n"
              << addToDish->getIngredientsList() << std::endl;
    std::cout << "Add To Dish - Total Cost: $" << addToDish->totalCost() << "\n"
              << std::endl;

    RemoveFromDish *removeFromDish = new RemoveFromDish("cheeseburger");
    removeFromDish->setCostOfIngredient(1.0);
    removeFromDish->setIngredient("Lettuce");
    removeFromDish->removeIngredient("Lettuce");
    std::cout << "Ingredient list after removing lettuce: \n"
              << removeFromDish->getIngredientsList() << std::endl;
    std::cout << "Remove From Dish - Total Cost:: $" << removeFromDish->totalCost() << "\n"
              << std::endl;

    SpecialCookingInstructions *specialInstructions = new SpecialCookingInstructions("cheeseburger");
    specialInstructions->addSpecialInstruction("No Sauce");
    std::cout << "Special Cooking Instructions - Total Cost: $" << specialInstructions->totalCost() << "\n"
              << endl;

    delete basicDish;
    delete addToDish;
    delete removeFromDish;
    delete specialInstructions;
}

void TableTest()
{
    srand(time(0));
    int count = 10;

    std::string names[] = {"John", "Sarah", "Mike", "Emma", "Jake", "Olivia", "Daniel", "Sophia", "David", "Ava",
                           "Joseph", "Emily", "Samuel", "Isabella", "Matthew", "Mia", "Lucas", "Charlotte", "Ethan", "Amelia"};
    Table *T = new Table();
    for (size_t i = 0; i < count; i++)
    {
        int randomIndex = rand() % count;
        T->addCustomer(new Customer(names[randomIndex]));
    }
}

int main()
{

    // StateTest();
    // CommandChainSingletonTest();
    // DecoratorTest();
    TableTest();
    return 0;
}
