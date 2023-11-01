#ifndef TAB_H
#define TAB_H

#include <string>
#include <map>

#include "BillMemento.h"
#include "Bill.h"

class Tab {

private:
	map<string, BillMemento> mementobills;

public:
	void addBill(BillMemento bill, string OrderID);

	void setBillMemento(string OrderID,BillMemento billMemento);

	BillMemento getBillMemento(string OrderID);

	void payAllBills();

	~Tab();
};

#endif
