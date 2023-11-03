#ifndef BILLMEMENTO_H
#define BILLMEMENTO_H

#include <string>

using namespace std;

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
	BillMemento();

	BillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid);

	~BillMemento();

	string getOrderID();

	string getCustomerID();

	double getTotalAmount();

	int getTableNum();

	int getRating();

	string getTabID();

	bool getPaid();
};

#endif
