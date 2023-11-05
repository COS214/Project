/**
 * @file Tab.cpp
 * @brief Contains the declaration of the Tab class functions.
 */

#include "Tab.h"

Tab::Tab() {
    mementobills = std::map<string, BillMemento>(); //make new map
}


/// @brief adds a bill to the map 
/// @param bill 
/// @param OrderID 
void Tab::addBill(BillMemento bill, string OrderID) {
    mementobills[OrderID] = bill;
    cout << "Bill succesffully added to a tab!" << endl;
}
/// @brief sets a specific BillMemento
/// @param OrderID 
/// @param billMemento 
void Tab::setBillMemento(string OrderID, BillMemento billMemento) {
	mementobills[OrderID] = billMemento;
}

/// @brief get a specific memento to use it to restore a Bill
/// @param OrderID 
/// @return 
BillMemento Tab::getBillMemento(string OrderID) {
    if (mementobills.find(OrderID) != mementobills.end()) {
        return mementobills[OrderID];
    } else {
        throw "BillMemento not found";
		return BillMemento();
    }
}

void Tab::payAllBills() {
    for (auto it = mementobills.begin(); it != mementobills.end(); ++it) {
        BillMemento memento = it->second;
        if (!memento.getPaid()) {
            ///first get the memento, then convert it to a bill and set the paid to true
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

Tab::~Tab(){}