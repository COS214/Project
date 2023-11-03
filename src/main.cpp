#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

#include "Bill.h"
#include "BillMemento.h"
#include "Tab.h"
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
#include "Arrived.h"
#include "Observer.h"
#include "Subject.h"
#include "State.h"
#include "Rate.h"
#include "Waiting.h"
#include "Pay.h"
#include "Seated.h"
#include "Leave.h"
#include "Dish.h"
#include "Menu.h"
#include "BasicDish.h"
#include "DishDecorator.h"
#include "AddToDish.h"
#include "RemoveFromDish.h"
#include "SpecialCookingInstructions.h"
#include "Floor.h"
#include "CookStrategy.h"
#include "GrilledStrategy.h"
#include "FriedStrategy.h"
#include "Mediator.h"
#include "concreteMediator.h"

using namespace std;

void testBill()
{

    cout << "Billtest =============================================" << endl;
    /// create a new bill
    Bill bill("OID234H", "CID785K", 50.0, 15, 2, bill.generateTabID("CID785K"), false);

    /// expect a certain amount
    double expectedTotalAmount = 50.0;
    double actualTotalAmount = bill.getTotalAmount(); // check if you get the expected amount back
    if (expectedTotalAmount == actualTotalAmount)
    {
        cout << "getTotalAmount test passed" << endl;
    }
    else
    {
        cout << "getTotalAmount test failed" << endl;
    }

    cout << "Billtest end ===================================================================" << endl;
}

void testTab()
{
    cout << "Tab test ===================================================================" << endl;
    /// create a new tab
    Tab tab;
    BillMemento memento("OID354B", "CID934D", 42.1, 7, 2, "TID149L", false);

    /// add bill to tab
    tab.addBill(memento, memento.getOrderID());
    BillMemento retrievedMemento = tab.getBillMemento("OID354B");

    /// use memento to test memento functionality
    if (retrievedMemento.getOrderID() == "OID354B" && retrievedMemento.getCustomerID() == "CID934D" && retrievedMemento.getTotalAmount() == 42.1)
    {
        cout << "addBill and getBillMemento test passed" << endl;
    }
    else
    {
        cout << "addBill and getBillMemento test failed" << endl;
    }
    cout << "Tab test end ==============================================================" << endl;
}

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

void testCustomer()
{
    cout << "Customer test  ===============================================================" << endl;
    /// Create a customer
    Customer customer;

    /// check to see if the customer has received an id successfully
    string customerID = customer.getCustomerID();
    if (!customerID.empty())
    {
        cout << "Customer creation and customer ID assignment test passed" << endl;
    }
    else
    {
        cout << "Customer creation and customer ID assignment test failed" << endl;
    }
    cout << "Customer test end  ===============================================================" << endl;
}

void testCustomerAndTab()
{
    cout << "Customer test and Tab test ==================================================================" << endl;
    /// Create a customer
    Customer customer;
    string customerID = customer.getCustomerID();

    /// make a new bill using the customerID
    Bill bill1(bill1.generateOrderID(), customerID, 402.4, 24, 3, bill1.generateTabID(customerID), false);

    /// Split the bill into 5 bills
    int splitIntoNBills = 5;
    map<string, BillMemento> splitBills;

    /// Create and add split bills to the map with unique order IDs
    for (int i = 0; i < splitIntoNBills; ++i)
    {
        BillMemento memento = bill1.createBillMemento(bill1.getOrderID(), bill1.getCustomerID(), bill1.getTotalAmount(), bill1.getTableNum(), bill1.getRating(), bill1.getTabID(), bill1.isPaid());
        splitBills[memento.getOrderID()] = memento;
    }

    /// Make a Tab where we add one of the splitbills
    Tab tab;
    tab.addBill(splitBills.begin()->second, splitBills.begin()->first);

    /// make a new customer
    Customer customer2;
    /// Add another bill to the same tab
    Bill bill2(bill2.generateOrderID(), customer2.getCustomerID(), 40.0, 2, 5, bill2.generateTabID(customerID), false);
    tab.addBill(bill2.createBillMemento(bill2.getOrderID(), bill2.getCustomerID(), bill2.getTotalAmount(), bill2.getTableNum(), bill2.getRating(), bill2.getTabID(), bill2.isPaid()), bill2.getOrderID());

    /// Fetch the tab
    BillMemento Tab = tab.getBillMemento(bill2.getOrderID());

    /// Calculate the total payment to pay from the tab
    double totalPayment = 0.0;
    auto it = splitBills.begin();
    while (it != splitBills.end())
    {
        totalPayment += it->second.getTotalAmount();
        ++it;
    }

    /// Display what the customer needs to pay
    cout << "Customer with ID " << customerID << " needs to pay R" << totalPayment << " for their meals." << endl;

    // Add a bill to the tab
    tab.addBill(splitBills.begin()->second, splitBills.begin()->first);

    // Simulate paying all bills in the tab
    tab.payAllBills();

    // Display that all bills in the tab have been paid
    cout << "All bills in the current tab have been paid." << endl;

    /// make the customer pay a bill
    bill1.payBill();

    /// METHOD TO show the functionality of memento and restore
    Bill bill3("OID457P", "CID956M", 59.4, 15, 1, "TID347C", false);

    /// Save the current bill into memento
    BillMemento memento = bill3.createBillMemento(bill3.getOrderID(), bill3.getCustomerID(), bill3.getTotalAmount(), bill3.getTableNum(), bill3.getRating(), bill3.getTabID(), bill3.isPaid());

    /// Restore the bill from the memento
    bill3.restoreFromMemento(memento);

    /// pay the restored bill
    bill3.payBill();

    cout << bill3.toString();

    cout << "Customer test and Tab test end ==================================================================" << endl;
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

    Mediator *cm = new concreteMediator(head, junior, meat, sauce, vegetable);

    junior->setMediator(cm);    // Set the mediator for junior
    vegetable->setMediator(cm); // Set the mediator for vegetable
    meat->setMediator(cm);      // Set the mediator for meat
    sauce->setMediator(cm);     // Set the mediator for sauce
    head->setMediator(cm);      // Set the mediator for head

    junior->setNext(vegetable);
    vegetable->setNext(meat);
    meat->setNext(sauce);
    sauce->setNext(head);

    Waiter *waiter = new Waiter();
    Order *custorder = new Order();
    Command *order = new KitchenOrder(custorder);
    waiter->placeOrder(junior, order);

    std::cout << "<=============================== Command Chain Singleton Mediator Unit Testing Ends ===============================>" << std::endl;

    delete junior;
    delete vegetable;
    delete meat;
    delete sauce;
    delete head;
    delete waiter;
    delete order;
    delete custorder;
}

void StrategyTest()
{
    std::cout << "<=============================== Strategy Unit Testing ===============================>" << std::endl;

    Order *customOrder = new Order();
    KitchenOrder *ko = new KitchenOrder(customOrder);

    std::cout << "Getting state" << std::endl;
    std::cout << ko->getState() << std::endl;

    GrilledStrategy *gs = new GrilledStrategy(ko);
    std::cout << "Getting the state in the GrilledStrategy" << std::endl;
    std::cout << ko->getState() << std::endl;
    gs->cookDish(ko);
    std::cout << "Getting the state after Grilling" << std::endl;
    std::cout << ko->getState() << std::endl;

    FriedStrategy *fs = new FriedStrategy(ko);
    std::cout << "Getting the state in the FriedStrategy" << std::endl;
    std::cout << ko->getState() << std::endl;
    fs->cookDish(ko);
    std::cout << "Getting the state after Frying" << std::endl;
    std::cout << ko->getState() << std::endl;
}

void DecoratorTest()
{

    std::cout << "<=============================== Decorator Unit Testing ===============================>" << std::endl;

    Dish *dish1 = new BasicDish();
    dish1->setName("Pasta");
    dish1->setCost(10.0);
    list<string> ingredients1 = {"Pasta", "Sauce"};
    dish1->setIngredientsList(ingredients1);

    Dish *dish2 = new BasicDish();
    dish2->setName("Pizza");
    dish2->setCost(12.0);
    list<string> ingredients2 = {"Dough", "Cheese", "Tomato"};
    dish2->setIngredientsList(ingredients2);

    Menu menu;
    menu.addDish("1", dish1, 10.0);
    menu.addDish("2", dish2, 12.0);
    menu.printMenu();

    std::pair<Dish *, double> dishInfo = menu.getDish("1");
    if (dishInfo.first)
    {
        std::cout << "Selected Dish: " << dishInfo.first->getName() << " - Cost: $" << dishInfo.second << std::endl;
    }
    else
    {
        std::cout << "Dish not found in the menu." << std::endl;
    }

    DishDecorator *decoratedDish1 = new AddToDish();
    decoratedDish1->setComponent(dish1);
    decoratedDish1->setCostOfIngredient(2.0);
    decoratedDish1->setIngredient("Pickles");
    decoratedDish1->addIngredient("Pickles");
    std::cout << "Updated Add to Dish with Ingredients: \n"
              << decoratedDish1->getIngredientsList() << std::endl;
    std::cout << "Updated Add to Dish Cost: $" << decoratedDish1->totalCost() << std::endl;
    std::cout << endl;

    DishDecorator *decoratedDish2 = new RemoveFromDish();
    decoratedDish2->setComponent(dish1);
    decoratedDish2->setCostOfIngredient(3.0);
    decoratedDish2->setIngredient("Pasta");
    decoratedDish2->removeIngredient("Pasta");
    std::cout << "Updated Remove to Dish with Ingredients: \n"
              << decoratedDish2->getIngredientsList() << std::endl;
    std::cout << "Updated Remove to Dish Cost: $" << decoratedDish2->totalCost() << std::endl;
    std::cout << endl;

    DishDecorator *decoratedDish3 = new SpecialCookingInstructions();
    decoratedDish3->setComponent(dish2);
    decoratedDish3->addSpecialInstruction("No Sauce");
    std::cout << "Special Cooking Instructions - Total Cost: $" << decoratedDish3->totalCost() << "\n"
              << endl;

    delete dish1;
    delete dish2;
    delete decoratedDish1;
    delete decoratedDish2;
    delete decoratedDish3;
}

void TableTest()
{
    srand(time(0));
    int count = 10;

    std::string names[] = {"John", "Sarah", "Mike", "Emma", "Jake", "Olivia", "Daniel", "Sophia", "David", "Ava",
                           "Joseph", "Emily", "Samuel", "Isabella", "Matthew", "Mia", "Lucas", "Charlotte", "Ethan", "Amelia"};
    Table *T = new Table(2); // Need to make these table numbers assigned in Floor composite
    for (size_t i = 0; i < count; i++)
    {
        int randomIndex = rand() % count;
        T->addCustomer(new Customer(names[randomIndex]));
    }
}

void FloorTest()
{
    srand(time(0));
    int count = 10;

    std::string names[] = {"John", "Sarah", "Mike", "Emma", "Jake", "Olivia", "Daniel", "Sophia", "David", "Ava",
                           "Joseph", "Emily", "Samuel", "Isabella", "Matthew", "Mia", "Lucas", "Charlotte", "Ethan", "Amelia"};
    Floor *floor = new Floor();
    for (size_t i = 0; i < count; i++)
    {
        Table *T = new Table(i); // Need to make these table numbers assigned in Floor composite
        for (size_t j = 0; j < count; j++)
        {
            int randomIndex = rand() % count;
            T->addCustomer(new Customer(names[randomIndex]));
        }
        floor->addTable(T);
    }
}

int main()
{
    /// run the tests
    // testBill();
    // testTab();
    // testCustomer();
    // testCustomerAndTab();
    // StateTest();
    CommandChainSingletonTest();
    // StrategyTest();
    // DecoratorTest();
    // StateTest();
    // TableTest();
    // FloorTest();

    return 0;
}
