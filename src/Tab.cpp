/**
 * @file Tab.cpp
 * @brief Contains the declaration of the Tab class functions.
 */

#include "Tab.h"

Tab::Tab()
{
    mementobills = std::map<string, BillMemento>(); // make new map
}
/**
 * @brief This method allows a bill to be added to the tab.
 *
 * @param bill BillMemento object representing the bill to be added.
 * @param OrderID String representing the order ID of the bill.
 */

void Tab::addBill(BillMemento bill, string OrderID)
{
    mementobills[OrderID] = bill;
    cout << "Bill for order " << OrderID << " succesfully added to tab of customer " << bill.getCustomerID() << ". " << endl;
}
/**
 * @brief This method allows a bill memento to be set for a specific order ID.
 *
 * @param OrderID String representing the order ID of the bill.
 * @param billMemento BillMemento object representing the bill memento to be set.
 */
void Tab::setBillMemento(string OrderID, BillMemento billMemento)
{
    mementobills[OrderID] = billMemento;
}
/**
 * @brief This method returns a bill memento for a specific order ID.
 *
 * @param OrderID String representing the order ID of the bill.
 * @return BillMemento object representing the bill memento for the specified order ID.
 */
BillMemento Tab::getBillMemento(string OrderID)
{
    if (mementobills.find(OrderID) != mementobills.end())
    {
        return mementobills[OrderID];
    }
    else
    {
        throw "BillMemento not found";
        return BillMemento();
    }
}
/**
 * @brief This method allows all bills in the tab to be paid.
 */
void Tab::payAllBills()
{
    for (auto it = mementobills.begin(); it != mementobills.end(); ++it)
    {
        BillMemento memento = it->second;
        if (!memento.getPaid())
        {
            /// first get the memento, then convert it to a bill and set the paid to true
            Bill bill(memento.getOrderID(), memento.getCustomerID(), memento.getTotalAmount(), memento.getTableNum(), memento.getRating(), memento.getTabID(), true);

            /// update the memento that you used to make the bill
            memento = bill.createBillMemento(bill.getOrderID(), bill.getCustomerID(), bill.getTotalAmount(), bill.getTableNum(), bill.getRating(), bill.getTabID(), bill.isPaid());

            /// Update the memento that was in the map
            it->second = memento;

            /// print out the bill that has been paid
            cout << "Bill with order ID " << memento.getOrderID() << " has been paid." << endl;
            cout << bill.toString();
        }
    }
}

Tab::~Tab() {}