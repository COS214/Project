#ifndef BILLMEMENTO_H
#define BILLMEMENTO_H

#include <string>

using namespace std; 

class BillMemento {
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
	BillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, boolean paid);
};

#endif
