/**
 * @file BillMemento.h
 * @brief Contains the declaration of the BillMemento class.
 */

#ifndef BILLMEMENTO_H
#define BILLMEMENTO_H

#include <string>

using namespace std;

/**
 * @class BillMemento
 * @brief The BillMemento class represents a memento object that stores the state of a bill.
 */
class BillMemento {

private:
	BillMemento* billMemento;
	string orderID;
	string customerID;
	double totalAmount;
	int tableNum;
	int rating;
	string tabID;
	bool paid;

public:
	/**
	 * @brief Constructs a BillMemento instance.
	 */
	BillMemento();

	/**
	 * @brief Constructs a BillMemento instance with the specified details.
	 * @param orderID The order ID associated with the bill.
	 * @param customerID The customer ID associated with the bill.
	 * @param totalAmount The total amount of the bill.
	 * @param tableNum The table number associated with the bill.
	 * @param rating The rating given by the customer.
	 * @param tabID The tab ID associated with the bill.
	 * @param paid A boolean indicating whether the bill is paid.
	 */
	BillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid);


	/**
	 * @brief Destructor for the BillMemento instance.
	 */
	~BillMemento();


	/**
	 * @brief Gets the order ID associated with the bill.
	 * @return The order ID.
	 */
	string getOrderID();

	/**
	 * @brief Gets the customer ID associated with the bill.
	 * @return The customer ID.
	 */
	string getCustomerID();

	/**
	 * @brief Gets the total amount of the bill.
	 * @return The total amount.
	 */
	double getTotalAmount();

	/**
	 * @brief Gets the table number associated with the bill.
	 * @return The table number.
	 */
	int getTableNum();

	/**
	 * @brief Gets the rating given by the customer.
	 * @return The rating.
	 */
	int getRating();

	/**
	 * @brief Gets the tab ID associated with the bill.
	 * @return The tab ID.
	 */
	string getTabID();

	/**
	 * @brief Gets whether the bill is paid.
	 * @return A boolean indicating whether the bill is paid.
	 */
	bool getPaid();
};

#endif