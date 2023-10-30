#include "BillMemento.h"

/// @brief This is the MementoBill implementation
/// @param orderID 
/// @param customerID 
/// @param totalAmount 
/// @param tableNum 
/// @param rating 
/// @param tabID 
/// @param paid 

/// Set the constructor for the BillMemento
BillMemento::BillMemento(string orderID, string customerID, double totalAmount,int tableNum, int rating, string tabID, bool paid) : 
orderID(orderID), customerID(customerID), totalAmount(totalAmount), tableNum(tableNum), rating(rating), tabID(tabID), paid(paid) {
}
/// @brief Default constructor for the BillMemento class
BillMemento::BillMemento() {
    this->orderID = "";
	this->customerID = "";
	this->totalAmount = 0;
	this->tableNum = 0;
	this->rating = 0;
	this->tabID = "";
	this->paid = 0;
}

string BillMemento::getOrderID(){
	return this->orderID;
}

string BillMemento::getCustomerID(){
	return this->customerID;
}

double BillMemento::getTotalAmount(){
	return this->totalAmount;
}

int BillMemento::getTableNum(){
	return this->tableNum;
}

int BillMemento::getRating(){
	return this->rating;
}

string BillMemento::getTabID(){
	return this->tabID;
}

bool BillMemento::getPaid(){
	return this->paid;
}