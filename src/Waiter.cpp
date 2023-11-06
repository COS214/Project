/**
 * @file Waiter.cpp
 * @brief Contains the declaration of the Waiter class functions.
 */

#include "Waiter.h"

void Waiter::placeOrder(Chefs *Chefs, Command *order, int cookStrategy)
{
    // std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
    std::cout << "\033[0;37m-------------------Waiter sends order to the kitchen: ";
    ;
    Chefs->prepareOrder(order, this, cookStrategy);
}

void Waiter::update(string message)
{
    if (message == "Arrived")
    {
        cout << "Waiter notices : Customer arrived. " << endl;
    }
    if (message == "Waiting")
    {
        cout << "Waiter notices : Customer waiting to be seated. " << endl;
    }
    if (message == "Seated")
    {
        cout << "Waiter has seated customer : ";
    }
    if (message == "Order")
    {
        cout << "Waiter notices Customer ready to order : ";
    }
    if (message == "Rate")
    {
        cout << "Waiter notices Customer would like to Rate experience : ";
    }
    if (message == "Pay")
    {
        cout << "Waiter notices Customer would like to pay the Bill. " << endl;
    }
    if (message == "Leave")
    {
        cout << "Waiter notices Customer ready to leave - allows them to do so." << endl;
    }
    // cout << "Customer has changed state: " << message << endl;
}

Waiter::Waiter(std::list<Table *> tables) : tables(tables)
{
    this->currentTable = tables.begin();                             // sets to the start of the table
    this->currentCustomer = (*currentTable)->getCustomers().begin(); // sets to the beginning of the customers
}

Customer *Waiter::first()
{
    // deprecated
    //  currentTable = tables.begin(); // set to the first table
    //  currentCustomer = (*currentTable)->getCustomers().begin();
    //  // first customer at the table

    return nullptr; // return the first customer at the table...
}

Customer *Waiter::next()
{
    // deprecated
    //  if (!isDone() && *currentTable != nullptr)
    //  {
    //      if ((*currentCustomer)++ != *(*currentTable)->getCustomers().end())
    //      {
    //          return *currentCustomer;
    //      }
    //  }

    return nullptr; // No more customers to serve
}

bool Waiter::isDone()
{
    return currentTable == tables.end();
}
/**
 * @brief This method allows the waiter to serve customers based on their current state.
 *
 * @param Chefs Pointer to the Chefs object.
 * @param order Pointer to the Command object representing the customer's order.
 */
void Waiter::serveCustomers(Chefs *Chefs, Command *order)
{
    std::list<Table *> myTables = this->tables;
    for (auto currTable = myTables.begin(); currTable != myTables.end(); ++currTable)
    {
        std::cout << "Table Nr: " << (*currTable)->getTableNumber() << "\n\n=========\n";
        std::list<Customer *> myCusts = (*currTable)->getCustomers();
        for (auto currCustomer = myCusts.begin(); currCustomer != myCusts.end(); ++currCustomer)
        {
            // Iterate over every customer
            std::cout << (*currCustomer)->getName() << "\n";

            if ((*currCustomer)->getState() == "Order")
            {
                // Forward the order to the kitchen using the placeOrder method.
                placeOrder(Chefs, order, 1);

                std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
            }
            else if ((*currCustomer)->getState() == "Pay")
            {
                // Create a new bill
                Bill temp = Bill();
                Bill newBill = Bill(
                    temp.generateOrderID(),
                    (*currCustomer)->getCustomerID(),
                    (*currCustomer)->getTotalAmount(),
                    (*currTable)->getTableNumber(),
                    (*currCustomer)->getRating(),
                    temp.generateTabID((*currCustomer)->getCustomerID()),
                    false);

                // Pay the bill
                newBill.pay();
                std::cout << "Bill paid in full"
                          << "\n";

                // Create a bill memento
                BillMemento billMemento(
                    newBill.getOrderID(),
                    newBill.getCustomerID(),
                    newBill.getTotalAmount(),
                    newBill.getTableNum(),
                    newBill.getRating(),
                    newBill.getTabID(),
                    newBill.isPaid());

                cout << newBill.toString();

                // Send the bill memento to a new tab
                Tab *newTab = new Tab();
                newTab->addBill(billMemento, newBill.getOrderID());
            }
            else if ((*currCustomer)->getState() == "Rate")
            {
                std::cout << "Customer: " << (*currCustomer)->getName() << " has rated the meal " << (*currCustomer)->getRating() << " out of 5." << std::endl;
            }
            else if ((*currCustomer)->getState() == "Leave")
            {
                std::cout << "Customer: " << (*currCustomer)->getName() << " is about to leave the restaurant." << std::endl;

                /// Remove the customer from the table
                currCustomer = myCusts.erase(currCustomer);
            }
        }
    }

    // // Get the state of the customer
    // if (currentCustomer->getState() == "Order")
    // {
    //     // Forward the order to the kitchen using the placeOrder method.
    //     placeOrder(Chefs, order);

    //     std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
    // }
    // else if (currentCustomer->getState() == "Pay")
    // {
    //     // create a new bill
    //     Bill newBill = Bill(
    //         newBill.generateOrderID(),
    //         currentCustomer->getCustomerID(),
    //         currentCustomer->getTotalAmount(),
    //         currentCustomer->getTableNumber(),
    //         currentCustomer->getRating(),
    //         newBill.generateTabID(currentCustomer->getCustomerID()),
    //         false);

    //     // Pay the bill
    //     newBill.pay();
    //     std::cout << "Bill paid in full"
    //               << "\n";

    //     // Create a bill memento
    //     BillMemento billMemento(
    //         newBill.getOrderID(),
    //         newBill.getCustomerID(),
    //         newBill.getTotalAmount(),
    //         newBill.getTableNum(),
    //         newBill.getRating(),
    //         newBill.getTabID(),
    //         newBill.isPaid());

    //     // Send the bill memento to a new tab
    //     Tab newtab;
    //     newtab.addBill(billMemento, newBill.getOrderID());
    // }
    // else if (currentCustomer->getState() == "Rate")
    // {
    //     std::cout << "Customer: " << currentCustomer->getName() << "has rated his meal a" << currentCustomer->getRating() << "out of 5." << std::endl;
    // }
    // else if (currentCustomer->getState() == "Leave")
    // {
    //     std::cout << "Customer: " << currentCustomer->getName() << "is about to leave the restaurant." << std::endl;
    // }

    // go to the next customer
}
/**
 * @brief Destructor
 *
 */
Waiter::~Waiter()
{
}

void Waiter::receiveOrder(Command *order)
{
    (void)order;
    cout << "\033[0;37m---------------------------------------------------Waiter received order---------------------------------------------------\033[0m" << endl
         << endl;
}
/**
 * @brief Default Constructor.
 *
 */
Waiter::Waiter()
{
    
}
