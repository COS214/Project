#include "Waiter.h"

void Waiter::placeOrder(Chefs *Chefs, Command *order)
{
    //std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
    std::cout << "-Waiter sends order to the kitchen: ";;
    Chefs->prepareOrder(order, this);
}

void Waiter::update(string message)
{
    // name can be the name given to the waiter object observing a specific customer
    // can be changed to an id instead
    //cout << "Customer has changed state: " << message << endl;
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
                placeOrder(Chefs, order);

                std::cout << "Waiter takes the order and forwards it to the kitchen." << std::endl;
            }
            else if ((*currCustomer)->getState() == "Pay")
            {
                // Create a new bill
                Bill newBill = Bill(
                    newBill.generateOrderID(),
                    (*currCustomer)->getCustomerID(),
                    (*currCustomer)->getTotalAmount(),
                    (*currTable)->getTableNumber(),
                    (*currCustomer)->getRating(),
                    newBill.generateTabID((*currCustomer)->getCustomerID()),
                    false);

                // Pay the bill
                newBill.pay();
                std::cout << "Bill paid in full" << "\n";

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

Waiter::~Waiter()
{
}

void Waiter::receiveOrder(Command *order)
{
    cout << "----------------Waiter received order----------------" << endl;
}
// default constructor
Waiter::Waiter()
{
    this->tables;
    this->currentTable;
    this->currentCustomer;
}
