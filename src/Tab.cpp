#include "Tab.h"

/// @brief adds a bill to the map 
/// @param bill 
/// @param OrderID 
void Tab::addBill(BillMemento bill, string OrderID) {
    mementobills[OrderID] = bill;
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