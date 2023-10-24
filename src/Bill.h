#ifndef BILL_H
#define BILL_H

#include <string>
#include <map>


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
		BillMemento createBillMemento();

		void setBillMemento(BillMemento memento);

		map<Bill, string> splitBill(int splitIntoNBills, BillMemento bill);

		string generateTabID(string customerID);
};

#endif
