#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <sstream>
#include <chrono>

#include "Bill.h"
#include "BillMemento.h"
#include "Tab.h"
#include "Customer.h"
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
#include "Table.h"

using namespace std;

void testBill()
{

    cout << "Billtest =============================================" << endl;
    /// create a new bill
    Bill temp = Bill();
    Bill bill("OID234H", "CID785K", 50.0, 15, 2, temp.generateTabID("CID785K"), false);

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
    Bill temp = Bill();
    Bill bill1(temp.generateOrderID(), customerID, 402.4, 24, 3, temp.generateTabID(customerID), false);

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
    Bill bill2(temp.generateOrderID(), customer2.getCustomerID(), 40.0, 2, 5, temp.generateTabID(customerID), false);
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
    junior->setInventory(inventory);
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
    waiter->placeOrder(junior, order, 1);

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

void FloorTest()
{
    srand(time(0));
    size_t count = 10;

    std::string names[] = {"John", "Sarah", "Mike", "Emma", "Jake", "Olivia", "Daniel", "Sophia", "David", "Ava",
                           "Joseph", "Emily", "Samuel", "Isabella", "Matthew", "Mia", "Lucas", "Charlotte", "Ethan", "Amelia"};
    Floor *floor = new Floor();
    int customerID = 101;
    for (size_t i = 0; i < count; i++)
    {
        Table *T = new Table(i); // Need to make these table numbers assigned in Floor composite
        for (size_t j = 0; j < count; j++)
        {
            int randomIndex = rand() % count;
            T->addCustomer(new Customer(names[randomIndex], customerID));
        }
        customerID++;
        floor->addTable(T);
    }
}

void IteratorTest()
{

    std::string names[] = {"John", "Sarah", "Mike", "Emma", "Jake", "Olivia", "Daniel", "Sophia", "David", "Ava",
                           "Joseph", "Emily", "Samuel", "Isabella", "Matthew", "Mia", "Lucas", "Charlotte", "Ethan", "Amelia"};

    int count = 5;
    std::list<Table *> floor; // Not actually a floor object
    for (int i = 0; i < count; i++)
    {
        floor.push_back(new Table(i));
    }
    std::list<Table *>::iterator it = floor.begin();
    int customerID = 101;
    for (int i = 0; i < count; i++)
    {
        srand(0);
        Table *ithTable = *it;
        for (int j = 0; j < count; j++)
        {
            int randomIndex = rand() % count;
            ithTable->addCustomer(new Customer(names[randomIndex], customerID));
        }
        customerID++;
        std::advance(it, 1);
    }

    // Need to populate tables with customers before instantiating Waiter
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

    Waiter *waiter = new Waiter(floor);
    Order *custorder = new Order();
    Command *order = new KitchenOrder(custorder);
    // waiter->placeOrder(junior, order);
    waiter->serveCustomers(junior, order);
}

void newFloorTest()
{
    srand(time(0));               /// make the seed use time
    int numTables = 5;            /// Number of tables in the restaurant
    int numCustomersPerTable = 5; /// Number of customers at each table

    std::string names[] = {"Siya", "Troy", "Kurt-Lee", "Eben", "Luke", "Olivia", "Daniel", "Ryan", "Hamza", "Luca",
                           "Mapimpi", "Deetlef", "Luke", "Mihir", "Piery", "Jimmy", "Lucas", "Aliyah", "Saeed", "Bongi", "Pieter-Steph", "Frans",
                           "Trevor", "Vincent", "RG", "Jean", "Franco", "Marco", "Kwagga", "Duane", "Jasper", "Faf", "Handre", "Grant", "Cobus", "Manie", "Cheslin", "Willie", "Tabraiz",
                           "Keshav", "Temba", "Marco", "Aiden", "Reeza", "Kagiso", "Lungi", "Lizaad"};

    Floor *floor = new Floor(); /// make a new floor
    int customerID = 101;
    /// Create tables and add customers to them
    for (int i = 1; i <= numTables; i++)
    {
        Table *table = new Table(i); /// make new table
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::default_random_engine generator2(seed);
        std::uniform_int_distribution<int> dist(1, 10);
        // Add customers to the table
        for (int j = 0; j < numCustomersPerTable; j++)
        {
            int randomIndex = rand() % numCustomersPerTable;
            table->addCustomer(new Customer(names[randomIndex], customerID));
        }
        customerID++;
        /// Add the newly created table to the floor
        floor->addTable(table);
    }

    /// Print information about the floor
    cout << "Restaurant Floor Config:" << endl;

    /// Iterate over tables and their customers
    for (auto &table : floor->getTables())
    {
        cout << "Table: " << table->getTableNumber() << ":" << endl;
        for (auto &customer : table->getCustomers())
        {
            cout << "  Customer: " << customer->getName() << endl;
        }
    }
}

string generateUniqueOrderID(int orders)
{

    std::ostringstream idStream;
    idStream << "ORD" << orders;
    return idStream.str();
}

void FinalMain()
{
    cout << "\033[32m-------------------------------------------STOCKING UP RESTAURANT INVENTORY-----------------------------------------------\n\033[0m" << endl;

    Inventory *inventory = Inventory::getInstance();
    map<string, int> inv;

    inv["Spaghetti"] = 20;         //
    inv["Pancetta"] = 10;          //
    inv["Parmesan Cheese"] = 30;   //
    inv["Black Pepper"] = 40;      //
    inv["Pizza Dough"] = 25;       //
    inv["Tomato Sauce"] = 20;      //
    inv["Mozzarella Cheese"] = 35; //
    inv["Fresh Basil"] = 15;       //
    inv["Lasagna Sheets"] = 10;    //
    inv["Bolognese Sauce"] = 18;   //
    inv["Ladyfingers"] = 25;       //
    inv["Mascarpone Cheese"] = 20; //
    inv["Espresso"] = 30;          //
    inv["Cocoa Powder"] = 40;      //
    inv["Vegetable Broth"] = 20;   //
    inv["Tomatoes"] = 30;          //
    inv["Beans"] = 25;
    inv["Pasta"] = 30;

    inventory->initializeInventory(inv);
    inventory->printInventory();
    cout << endl;

    cout << "\033[32m--------------------------------------------------PREPARING KITCHEN STAFF-----------------------------------------------\n\033[0m" << endl;

    JuniorChef *junior = new JuniorChef();
    Chefs::inventory = inventory;
    VegetableChef *vegetable = new VegetableChef();
    MeatChef *meat = new MeatChef();
    SauceChef *sauce = new SauceChef();
    HeadChef *head = new HeadChef();

    Mediator *cm = new concreteMediator(head, junior, meat, sauce, vegetable);

    junior->setMediator(cm);
    vegetable->setMediator(cm);
    meat->setMediator(cm);
    sauce->setMediator(cm);
    head->setMediator(cm);

    junior->setNext(vegetable);
    vegetable->setNext(meat);
    meat->setNext(sauce);
    sauce->setNext(head);
    cout << endl;

    cout << "\033[32m-------------------------------------------SETTING UP THE RESTAURANT FLOOR-----------------------------------------------\n\033[0m" << endl;

    srand(time(0));
    int numTables = 5;
    int numCustomersPerTable = 5;
    size_t numCustomers = numTables * numCustomersPerTable;
    std::string names[] = {
        "Siya", "Troy", "Kurt-Lee", "Eben", "Luke", "Olivia", "Daniel", "Ryan", "Hamza", "Luca", "Mapimpi", "Deetlef",
        "Luke", "Mihir", "Piery", "Jimmy", "Lucas", "Aliyah", "Saeed", "Bongi", "Pieter-Steph", "Frans", "Trevor", "Vincent",
        "RG", "Jean", "Franco", "Marco", "Kwagga", "Duane", "Jasper", "Faf", "Handre", "Grant", "Cobus", "Manie", "Cheslin", "Willie",
        "Tabraiz", "Keshav", "Temba", "Marco", "Aiden", "Reeza", "Kagiso", "Lungi", "Lizaad"};

    if (numCustomers > sizeof(names) / sizeof(names[0]))
    {
        cerr << "\033[1;31mError: Not enough unique names for customers.\n\033[0m";
        return;
    }

    Floor *floor = new Floor(); 
    Waiter *waiter1 = new Waiter();
    Waiter *waiter2 = new Waiter();
    Waiter *waiter3 = new Waiter();
    Waiter *waiter4 = new Waiter();
    Waiter *waiter5 = new Waiter();

    random_shuffle(&names[0], &names[numCustomers]);
    int customerIndex = 0;

    int customerID = 101;

    for (int i = 1; i <= numTables; i++)
    {
        Table *table = new Table(i);
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::default_random_engine generator2(seed);
        std::uniform_int_distribution<int> dist(1, 10);
        for (int j = 0; j < dist(generator2); j++)
        {

            Customer *customer = new Customer(names[customerIndex], customerID); // state = arrived
            table->addCustomer(customer);
            if (i == 1)
            {
                customer->attach(waiter1);
            }
            if (i == 2)
            {
                customer->attach(waiter2);
            }
            if (i == 3)
            {
                customer->attach(waiter3);
            }
            if (i == 4)
            {
                customer->attach(waiter4);
            }
            if (i == 5)
            {
                customer->attach(waiter5);
            }
            customer->change(); // state = waiting
            customerIndex++;
            customerID++;
        }
        floor->addTable(table);
    }
    cout << endl;
    cout << "\033[32m--------------------------------------------LAYOUT OF THE RESTAURANT FLOOR:----------------------------------------------------\n\033[0m" << endl;
    cout << endl;
    for (auto &table : floor->getTables())
    {
        cout << "\033[93mMaitre D shows customers to their table: Table " << table->getTableNumber() << ":\033[0m" << endl;
        for (auto &customer : table->getCustomers())
        {
            customer->change(); // state = seated
            cout << " Customer " << customer->getCustomerID() << " " << customer->getName() << endl;
        }
        cout << endl;
    }

    cout << "\033[32m-----------------------------------------------PRESENTING MENU TO CUSTOMERS------------------------------------------------------\n\033[0m" << endl;
    Dish *dish1 = new BasicDish();
    dish1->setName("Spaghetti Carbonara");
    dish1->setCost(140.0);
    list<string> ingredients1 = {"Spaghetti", "Pancetta", "Parmesan Cheese", "Black Pepper"};
    dish1->setIngredientsList(ingredients1);

    Dish *dish2 = new BasicDish();
    dish2->setName("Margherita Pizza");
    dish2->setCost(120.0);
    list<string> ingredients2 = {"Pizza Dough", "Tomato Sauce", "Mozzarella Cheese", "Basil"};
    dish2->setIngredientsList(ingredients2);

    Dish *dish3 = new BasicDish();
    dish3->setName("Lasagna");
    dish3->setCost(160.0);
    list<string> ingredients3 = {"Lasagna Sheets", "Bolognese Sauce", "Parmesan Cheese"};
    dish3->setIngredientsList(ingredients3);

    Dish *dish4 = new BasicDish();
    dish4->setName("Tiramisu");
    dish4->setCost(80.0);
    list<string> ingredients4 = {"Ladyfingers", "Mascarpone Cheese", "Espresso", "Cocoa Powder"};
    dish4->setIngredientsList(ingredients4);

    Dish *dish5 = new BasicDish();
    dish5->setName("Minestrone Soup");
    dish5->setCost(90.0);
    list<string> ingredients5 = {"Vegetable Broth", "Tomatoes", "Beans", "Pasta"};
    dish5->setIngredientsList(ingredients5);

    Menu menu;
    menu.addDish("1", dish1, 140.0);
    menu.addDish("2", dish2, 120.0);
    menu.addDish("3", dish3, 160.0);
    menu.addDish("4", dish4, 80.0);
    menu.addDish("5", dish5, 90.0);
    menu.printMenu();
    cout << endl;

    cout << "\033[32m-------------------------------------------CUSTOMERS READY TO ORDER DISHES-----------------------------------------------\n\033[0m" << endl;

    std::map<int, double> tableTotalCosts;
    std::map<int, string> tableOrderIDs;
    int orders = 2034;
    for (auto &table : floor->getTables())
    {
        cout << "\033[93m Table " << table->getTableNumber() << ":\033[0m" << endl;
        string orderID = generateUniqueOrderID(orders);
        tableOrderIDs[table->getTableNumber()] = orderID;
        int count = 0;
        double tableTotalCost = 0.0;

        for (auto &customer : table->getCustomers())
        {
            count++;
            customer->change(); // state = order
            cout << "Customer number " << count;

            double customerTotalCost = 0.0;

            int randomDish = (rand() % 5) + 1;
            if (randomDish == 1)
            {
                DishDecorator *decoratedDish1 = new AddToDish();
                decoratedDish1->setComponent(dish1);
                decoratedDish1->setCostOfIngredient(15.0);
                decoratedDish1->addIngredient("Pickles");
                cout << " chose Spaghetti Carbonara and added Pickles: ";
                cout << "Dish price changes from R" << dish1->getCost() << " to R" << decoratedDish1->getCost() << endl;
                customer->setDish(decoratedDish1);
                customerTotalCost += decoratedDish1->getCost();
            }

            if (randomDish == 2)
            {
                DishDecorator *decoratedDish2 = new RemoveFromDish();
                decoratedDish2->setComponent(dish2);
                decoratedDish2->setCostOfIngredient(10.0);
                decoratedDish2->removeIngredient("Basil");
                cout << " chose Margherita Pizza and removed Basil: ";
                cout << "Dish price changes from R" << dish2->getCost() << " to R" << decoratedDish2->getCost() << endl;
                customer->setDish(decoratedDish2);
                customerTotalCost += decoratedDish2->getCost();
            }

            if (randomDish == 3)
            {
                DishDecorator *decoratedDish3 = new SpecialCookingInstructions();
                decoratedDish3->setComponent(dish3);
                cout << " chose Lasagna and requested Special instructions : ";
                decoratedDish3->addSpecialInstruction("Make sure cheese does not burn. ");
                cout << "Dish price remains the same: R" << decoratedDish3->getCost() << endl;
                customer->setDish(decoratedDish3);
                customerTotalCost += decoratedDish3->getCost();
            }

            if (randomDish == 4)
            {
                cout << " chose Tiramisu: ";
                cout << "Dish price remains the same: R" << dish4->getCost() << endl;
                customer->setDish(dish4);
                customerTotalCost += dish4->getCost();
            }

            if (randomDish == 5)
            {
                cout << " chose Minestrone Soup: ";
                cout << "Dish price remains the same: R" << dish5->getCost() << endl;
                customer->setDish(dish5);
                customerTotalCost += dish5->getCost();
            }
            tableTotalCost += customerTotalCost;
        }
        tableTotalCosts[table->getTableNumber()] = tableTotalCost;
        cout << "Total cost for Table " << table->getTableNumber() << ": R" << tableTotalCost << endl;
        cout << "Order ID for this table: " << orderID << endl;
        orders++;
        cout << endl;
    }

    cout << "\033[32m------------------------------------------ORDERS ARE SENT TO THE KITCHEN-----------------------------------------------\n\033[0m" << endl;
    cout << endl;
    for (auto &table : floor->getTables())
    {
        cout << "\033[93m Table " << table->getTableNumber() << ":\033[0m" << endl;

        for (auto &customer : table->getCustomers())
        {
            Order *custorder = new Order();
            custorder->setCustomer(customer);
            Command *order = new KitchenOrder(custorder);
            int cookStrategy = (rand() % 2) + 1;

            if (table->getTableNumber() == 1)
            {
                waiter1->placeOrder(junior, order, cookStrategy);
            }

            if (table->getTableNumber() == 2)
            {
                waiter2->placeOrder(junior, order, cookStrategy);
            }

            if (table->getTableNumber() == 3)
            {
                waiter3->placeOrder(junior, order, cookStrategy);
            }

            if (table->getTableNumber() == 4)
            {
                waiter4->placeOrder(junior, order, cookStrategy);
            }

            if (table->getTableNumber() == 5)
            {
                waiter5->placeOrder(junior, order, cookStrategy);
            }
            delete custorder;
            delete order;
        }
    }

    cout << "\033[32m----------------------------FOOD IS SERVED TO CUSTOMERS & MAITRE D CHECKS UP ON THEM----------------------------\n\033[0m" << endl;
    for (auto &table : floor->getTables())
    {
        cout << "\033[93mMaitre D checks up on Table " << table->getTableNumber() << "\033[0m" << endl;
        for (auto &customer : table->getCustomers())
        {
            customer->getName();
        }
    }
    cout << endl;

    cout << "\033[32m-----------------------------------------------UPDATED INVENTORY----------------------------------------------------\n\033[0m" << endl;
    inventory->printInventory();
    cout << endl;

    cout << "\033[32m-------------------------------------------CUSTOMERS RATE THEIR MEALS-----------------------------------------------\n\033[0m" << endl;

    std::map<int, double> averageTableRating;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1, 5);
    for (auto &table : floor->getTables())
    {
        double average = 0;
        cout << "\033[93m Table " << table->getTableNumber() << ":\033[0m" << endl;

        for (auto &customer : table->getCustomers())
        {
            customer->change(); // state = rate
            int randomRating = distribution(generator);
            average += randomRating;
            customer->setRating(randomRating);
            cout << "Customer " << customer->getCustomerID() << " " << customer->getName() << " rated food " << customer->getRating() << " stars" << endl;
        }
        averageTableRating[table->getTableNumber()] = average / table->getCustomers().size();
        cout << "Overall table rating: " << averageTableRating[table->getTableNumber()] << endl;
        cout << endl;
    }

    cout << "\033[32m--------------------------------------CUSTOMERS ARE READY TO PAY THEIR BILLS----------------------------------------\n\033[0m" << endl;

    int order = 881;
    for (auto &table : floor->getTables())
    {
        cout << "\033[93m Table " << table->getTableNumber() << ":\033[0m" << endl;

        int split = (rand() % 3) + 1;
        int size = table->getCustomers().size();
        string customerIDs[size];
        for(int i = 0 ; i < size ; i++){
            customerIDs[i] = "";
        }
        string payingCustomer = "";
        int i = 0;
        for (auto &customer : table->getCustomers())
        {
            customer->change(); // state = bill
            customerIDs[i] = customer->getCustomerID();
            payingCustomer = customer->getCustomerID();
            i++;
        }

        if (split == 1)
        {
            Bill temp = Bill();
            cout << "Bill will be split: " << endl;
            Bill bill(tableOrderIDs[table->getTableNumber()], payingCustomer, tableTotalCosts[table->getTableNumber()], table->getTableNumber(), averageTableRating[table->getTableNumber()], temp.generateTabID("CID785K"), false);
            int splitIntoNBills = i;
            map<string, Bill> splitBills = bill.splitBill(splitIntoNBills, bill, order, customerIDs);
            for (auto it = splitBills.begin(); it != splitBills.end(); ++it)
            {
                it->second.payBill();
                cout << "Customer at table tipped waiter : R" << it->second.tipWaiter() << endl;
            }
        }

        else if (split == 2)
        {
            cout << "Bill will be paid by one customer at the table: ";
            Bill temp = Bill();
            Bill bill(tableOrderIDs[table->getTableNumber()], payingCustomer, tableTotalCosts[table->getTableNumber()], table->getTableNumber(), averageTableRating[table->getTableNumber()], temp.generateTabID("CID785K"), false);
            bill.payBill();
            cout << "Customers at table tipped waiter : R" << bill.tipWaiter() << endl;
        }

        else if (split == 3)
        {
            cout << "Bill will be added to a tab: " << endl;
            Tab tab;
            BillMemento memento(tableOrderIDs[table->getTableNumber()], payingCustomer, tableTotalCosts[table->getTableNumber()], table->getTableNumber(), averageTableRating[table->getTableNumber()], "TID149L", false);
            tab.addBill(memento, memento.getOrderID());
            cout << "Customers at table tipped waiter : R" << memento.tipWaiter() << endl;
        }
        order += 5;
        cout << endl;
    }

    cout << "\033[32m----------------------------------------------CUSTOMERS CHANGING THEIR MINDS-----------------------------------------------\n\033[0m" << endl;

    Customer newCustomer;
    string newCustomerID = newCustomer.getCustomerID();

    Bill originalBill("OID123", newCustomerID, 100.0, 10, 5, "TID987", false);

    cout << "This is the original Bill:" << endl;
    cout << originalBill.toString() << endl;
    
    BillMemento OGMemento(originalBill.getOrderID(), originalBill.getCustomerID(), originalBill.getTotalAmount(), originalBill.getTableNum(), originalBill.getRating(), originalBill.getTabID(), originalBill.isPaid());

    int splitIntoNBills = 3;
    map<string, Bill> splitBills = originalBill.splitBill(splitIntoNBills, originalBill, 1000, new string[3]{"Customer1", "Customer2", "Customer3"});

    bool setBill = true;
    cout << "\nCustomers decide to split the bill:" << endl;

    for (auto &entry : splitBills)
    {
        cout << entry.second.toString() << endl;
        if (setBill)
        {
            originalBill = entry.second;
            setBill = false;
        }
    }

    cout << "\nThis is the original bill that has been changed to the first split bill:" << endl;
    cout << originalBill.toString() << endl;

    originalBill.restoreFromMemento(OGMemento);

    cout << "\nRestored Original Bill:" << endl;

    cout << "\nPay the Original Bill:" << endl;
    originalBill.payBill();

    cout << originalBill.toString() << endl;

    cout << "\033[32m----------------------------------------------CUSTOMERS ARE READY TO LEAVE-----------------------------------------------\n\033[0m" << endl;

    for (auto &table : floor->getTables())
    {
        cout << "\033[93m Table " << table->getTableNumber() << ":\033[0m" << endl;

        for (auto &customer : table->getCustomers())
        {

            customer->change(); // state = leave
            if (table->getTableNumber() == 1)
            {
                customer->detach(waiter1);
            }
            if (table->getTableNumber() == 2)
            {
                customer->detach(waiter2);
            }
            if (table->getTableNumber() == 3)
            {
                customer->detach(waiter3);
            }
            if (table->getTableNumber() == 4)
            {
                customer->detach(waiter4);
            }
            if (table->getTableNumber() == 5)
            {
                customer->detach(waiter5);
            }
            delete customer;
        }
    }
    
    delete dish1;
    delete dish2;
    delete dish3;
    delete dish4;
    delete dish5;
    delete junior;
    delete vegetable;
    delete meat;
    delete sauce;
    delete head;
}

int main()
{
    //---------------------------------------------------UNIT TESTS-------------------------------------------------------------------
    // testBill();
    // testTab();
    // testCustomer();
    // testCustomerAndTab();
    // StateTest();
    // CommandChainSingletonTest();
    // StrategyTest();
    // DecoratorTest();
    // StateTest();
    // TableTest();
    // FloorTest();
    // IteratorTest();
    // newFloorTest();

    FinalMain();

    return 0;
}