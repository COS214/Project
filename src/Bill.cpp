#include "Bill.h"

/// @brief Implementation for the Bill class
/// @param orderID 
/// @param customerID 
/// @param totalAmount 
/// @param tableNum 
/// @param rating 
/// @param tabID 
/// @param paid 

///  initialize the constructor for the bill, when you make the bill it makes a memento too
Bill::Bill(
    string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid): 
	orderID(orderID), customerID(customerID), totalAmount(totalAmount), tableNum(tableNum), rating(rating), tabID(tabID), paid(paid) {
}

BillMemento Bill::createBillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid) {
    return BillMemento(orderID, customerID, totalAmount, tableNum, rating, tabID, paid);
}

void Bill::setBillMemento(BillMemento memento) {
	this->billMemento = memento;
}

map<Bill, string> Bill::splitBill(int splitIntoNBills, Bill bill) {
    // Calculate the new total amount for each split bill
    double newTotalAmount = bill.getTotalAmount(bill) / splitIntoNBills;

    // Create a map to store the split bills
    map<Bill, string> splitBills;

    // Generate and add split bills to the map
    for (int i = 1; i <= splitIntoNBills; ++i) {
        Bill splitBill(
            generateOrderID(bill), // You need a method to generate unique Order IDs
            bill.getCustomerID(bill),
            newTotalAmount,
            bill.getTableNum(bill),
            bill.getRating(bill),
            generateTabID(bill.getCustomerID(bill)), // Use the generateTabID method
            bill.isPaid(bill)
        );

        splitBills[splitBill] = "Split Bill " + to_string(i);
    }

    return splitBills;
}


string generateRandomTabID(string customerID) {
    std::hash<string> hasher;
    std::srand(hasher(customerID) + std::time(0)); ///seed the random with the customerID

    int randomDigits = std::rand() % 1000; ///generates random digits

    char randomLetter = static_cast<char>(std::rand() % 26 + 65); ///here we generate a random capital letter

    string tabID = "TID" + to_string(randomDigits) + randomLetter; ///put the string together

    return tabID; ///return the newly created TabID
}

double Bill::getTotalAmount(Bill bill){
	return bill.totalAmount;
}

string Bill::generateOrderID(Bill bill){
	return bill.orderID;
}

string Bill::getCustomerID(Bill bill){
	return bill.customerID;
}

int Bill::getTableNum(Bill bill){
	return bill.tableNum;
}
		
int Bill::getRating(Bill bill){
	return bill.rating;
}

bool Bill::isPaid(Bill bill){
	return bill.paid;
}
