#ifndef BILL_H
#define BILL_H

#include <string>
#include <map>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "BillMemento.h"

using namespace std;

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
		Bill(string orderID, string customerID, double totalAmount,int tableNum, int rating, string tabID, bool paid);

		BillMemento createBillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid);

		void setBillMemento(BillMemento memento);

		map<Bill, string> splitBill(int splitIntoNBills, Bill bill);

		string generateTabID(string customerID);

		double getTotalAmount(Bill bill);

		string generateOrderID(Bill bill);

		string getCustomerID(Bill bill);

		int getTableNum(Bill bill);
		
		int getRating(Bill bill);

		bool isPaid(Bill bill);



};

#endif
