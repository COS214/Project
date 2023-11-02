#ifndef TAB_H
#define TAB_H

#include <string>
#include <map>

#include "BillMemento.h"
#include "Bill.h"

class Tab {

private:
	map<int, BillMemento> mementobills;

public:
	void addBill(Bill bill, int OrderID);

	void setBillMemento(BillMemento billMemento);

	BillMemento getBillMemento();
};

#endif
