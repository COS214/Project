/**
 * @file BillMemento.cpp
 * @brief Contains the implementation of the BillMemento class.
 */

#include "BillMemento.h"

/**
 * @brief Constructor for the BillMemento class that takes orderID, customerID, totalAmount, tableNum, rating, tabID, and paid as parameters.
 *
 * @param orderID String representing the order ID.
 * @param customerID String representing the customer ID.
 * @param totalAmount Double representing the total amount.
 * @param tableNum Integer representing the table number.
 * @param rating Integer representing the rating.
 * @param tabID String representing the tab ID.
 * @param paid Boolean representing whether the bill is paid or not.
 */
BillMemento::BillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid) : orderID(orderID), customerID(customerID), totalAmount(totalAmount), tableNum(tableNum), rating(rating), tabID(tabID), paid(paid)
{
}

BillMemento::BillMemento()
{
	this->orderID = "";
	this->customerID = "";
	this->totalAmount = 0;
	this->tableNum = 0;
	this->rating = 0;
	this->tabID = "";
	this->paid = 0;
}
/**
 * @brief This method returns the order ID of the bill.
 *
 * @return String representing the order ID of the bill.
 */
string BillMemento::getOrderID()
{
	return this->orderID;
}
/**
 * @brief This method returns the customer ID of the bill.
 *
 * @return String representing the customer ID of the bill.
 */
string BillMemento::getCustomerID()
{
	return this->customerID;
}
/**
 * @brief This method returns the total amount of the bill.
 *
 * @return Double representing the total amount of the bill.
 */
double BillMemento::getTotalAmount()
{
	return this->totalAmount;
}
/**
 * @brief This method returns the table number of the bill.
 *
 * @return Integer representing the table number of the bill.
 */
int BillMemento::getTableNum()
{
	return this->tableNum;
}
/**
 * @brief This method returns the rating of the bill.
 *
 * @return Integer representing the rating of the bill.
 */
int BillMemento::getRating()
{
	return this->rating;
}
/**
 * @brief This method returns the tab ID of the bill.
 *
 * @return String representing the tab ID of the bill.
 */
string BillMemento::getTabID()
{
	return this->tabID;
}
/**
 * @brief This method returns whether the bill is paid or not.
 *
 * @return Boolean representing whether the bill is paid or not.
 */
bool BillMemento::getPaid()
{
	return this->paid;
}
/**
 * @brief Destructor for the BillMemento class.
 */
BillMemento::~BillMemento() {}