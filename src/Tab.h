/**
 * @file Tab.h
 * @brief Contains the declaration of the Tab class.
 */

#ifndef TAB_H
#define TAB_H

#include <string>
#include <map>

#include "BillMemento.h"
#include "Bill.h"

/**
 * @class Tab
 * @brief The Tab class represents the collection of bills and their mementos.
 */
class Tab {

private:
	map<string, BillMemento> mementobills;

public:
	/**
     * @brief Default constructor for the Tab class.
     */
	Tab();

	/**
     * @brief Add a bill memento to the tab.
     * @param bill A BillMemento representing the bill memento to be added.
     * @param OrderID A string representing the order ID associated with the bill.
     */
	void addBill(BillMemento bill, string OrderID);

	/**
     * @brief Set the bill memento for a specific order ID.
     * @param OrderID A string representing the order ID for which to set the bill memento.
     * @param billMemento A BillMemento representing the bill memento to be set.
     */
	void setBillMemento(string OrderID,BillMemento billMemento);

	/**
     * @brief Get the bill memento for a specific order ID.
     * @param OrderID A string representing the order ID for which to retrieve the bill memento.
     * @return A BillMemento representing the bill memento associated with the order ID.
     */
	BillMemento getBillMemento(string OrderID);

	/**
     * @brief Pay all bills.
     *
     * This method is used to initiate the payment process for all bills stored in the tab's collection.
     */
	void payAllBills();

	/**
     * @brief Destructor for the Tab class.
     */
	~Tab();
};

#endif
