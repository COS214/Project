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

		~Bill();

		BillMemento createBillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid);

		void setBillMemento(BillMemento memento);

		map<Bill, string> splitBill(int splitIntoNBills, Bill bill);

		double getTotalAmount();
		
		string getCustomerID();

		string getOrderID();

		int getTableNum();
		
		int getRating();

		bool isPaid();

		string getTabID();

		string generateTabID(string customerID);

		string generateOrderID();

		void pay();

		void payBill();
};

#endif
