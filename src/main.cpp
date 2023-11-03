#include <list>
#include <string>
#include <iostream>
#include "Bill.h"
#include "Tab.h"
#include "Customer.h"
#include <algorithm>
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
    std::cout << "<=============================== Command Chain Singleton Mediator Unit Testing ===============================>" << std::endl;

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

int main()
{
    /// run the tests
    // testBill();
    // testTab();
    // testCustomer();
    // testCustomerAndTab();
    //  StateTest();
    CommandChainSingletonTest();
    // StrategyTest();
    // DecoratorTest();
    return 0;
}
