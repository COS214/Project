#ifndef BILL_H
#define BILL_H

#include <string>
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
	boolean paid;

public:
	BillMemento createBillMemento();

	void setBillMemento(BillMemento memento);

	List<Bill, orderID> splitBill(intger splitintoNBills, BillMemento bill);

	string generateTabID(string customerID);
};

#endif
