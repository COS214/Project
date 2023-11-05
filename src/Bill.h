/**
 * @file Bill.h
 * @brief Contains the declaration of the Bill class.
 */

#ifndef BILL_H
#define BILL_H

#include <string>
#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Tab.h"

#include "BillMemento.h"

using namespace std;

/**
 * @class Bill
 * @brief The Bill class represents a bill for a customer's order in a restaurant.
 */
class Bill {

private:
	BillMemento billMemento;
	string orderID;
	string customerID;
	double totalAmount;
	int tableNum;
	int rating;
	string tabID;
	bool paid;

	public:
		/**
		 * @brief Constructs a Bill instance.
		 */
		Bill();
		
		/**
		 * @brief Constructs a Bill instance with the specified details.
		 * @param orderID The order ID associated with the bill.
		 * @param customerID The customer ID associated with the bill.
		 * @param totalAmount The total amount of the bill.
		 * @param tableNum The table number associated with the bill.
		 * @param rating The rating given by the customer.
		 * @param tabID The tab ID associated with the bill.
		 * @param paid A boolean indicating whether the bill is paid.
		 */	
		Bill(string orderID, string customerID, double totalAmount,int tableNum, int rating, string tabID, bool paid);

		/**
		 * @brief Creates a BillMemento object based on the bill's current state.
		 * @param orderID The order ID.
		 * @param customerID The customer ID.
		 * @param totalAmount The total amount.
		 * @param tableNum The table number.
		 * @param rating The customer's rating.
		 * @param tabID The tab ID.
		 * @param paid The payment status.
		 * @return A BillMemento object representing the bill's state.
		 */
		BillMemento createBillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid);

		/**
		 * @brief Sets the bill's state based on a BillMemento object.
		 * @param memento The BillMemento object to restore from.
		 */
		void setBillMemento(BillMemento memento);

		/**
		 * @brief Splits the bill into a specified number of bills.
		 * @param splitIntoNBills The number of bills to split into.
		 * @param bill The bill to split.
		 * @param order The order to split.
		 * @param customerIDs The customer IDs associated with the bill.
		 * @return A map of the split bills.
		 */
		map<string, Bill> splitBill(int splitIntoNBills, Bill bill, int order,std::string customerIDs[]);

		/**
		 * @brief Gets the total amount of the bill.
		 * @return The total amount.
		 */
		double getTotalAmount();
		
		/**
		 * @brief Gets the customer ID associated with the bill.
		 * @return The customer ID.
		 */
		string getCustomerID();

		/**
		 * @brief Gets the order ID associated with the bill.
		 * @return The order ID.
		 */
		string getOrderID();

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
		 * @brief Checks if the bill has been paid.
		 * @return `true` if the bill is paid, `false` if it's unpaid.
		 */
		bool isPaid();

		/**
		 * @brief Gets the tab ID associated with the bill.
		 * @return The tab ID.
		 */
		string getTabID();

		/**
		 * @brief Generates a unique tab ID for the bill based on the customer ID.
		 * @param customerID The customer's ID.
		 * @return The generated tab ID.
		 */
		string generateTabID(string customerID);

		/**
		 * @brief Generates a unique order ID for the bill.
		 * @return The generated order ID.
		 */
		string generateOrderID();

		/**
		 * @brief Marks the bill as paid.
		 */
		void pay();

		/**
		 * @brief Marks the bill as paid.
		 */
		void payBill();

		/**
		 * @brief Restores the bill's state from a BillMemento object.
		 *
		 * @param memento The BillMemento object to restore from.
		 */
		void restoreFromMemento(BillMemento memento);

		/**
		 * @brief Gets a string representation of the bill.
		 * @return The string representation.
		 */
		string toString();

		/**
		 * @brief Compares two bills to determine their order for sorting.
		 *
		 * @param other The other Bill object to compare.
		 * @return `true` if this bill is less than the other, `false` otherwise.
		 */
		bool operator<(const Bill& other) const;
};

#endif