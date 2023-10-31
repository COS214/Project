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
    double newTotalAmount = bill.getTotalAmount() / splitIntoNBills;

    // Create a map to store the split bills
    map<Bill, string> splitBills;

    // Generate and add split bills to the map
    for (int i = 1; i <= splitIntoNBills; ++i) {
        Bill splitBill(
            generateOrderID(), // You need a method to generate unique Order IDs
            bill.getCustomerID(),
            newTotalAmount,
            bill.getTableNum(),
            bill.getRating(),
            generateTabID(bill.getCustomerID()), // Use the generateTabID method
            bill.isPaid()
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

double Bill::getTotalAmount(){
	return this->totalAmount;
}

string Bill::generateOrderID(){
	std::hash<string> hasher;
    std::srand(std::time(0)); ///seed the random with the customerID

    int randomDigits = std::rand() % 1000; ///generates random digits

    char randomLetter = static_cast<char>(std::rand() % 26 + 65); ///here we generate a random capital letter

    string OID = "OID" + to_string(randomDigits) + randomLetter; ///put the string together

    return OID; ///return the newly created OrderID
}

string Bill::getCustomerID(){
	return this->customerID;
}

int Bill::getTableNum(){
	return this->tableNum;
}
		
int Bill::getRating(){
	return this->rating;
}

bool Bill::isPaid(){
	return this->paid;
}

string Bill::getTabID(){
    return this->tabID;
}

void Bill::pay() {
    this->paid = true;
}

void Bill::payBill() {
    if (this->isPaid()) {
        std::cout << "This bill has already been paid." << std::endl;
    } else {
        this->pay();
        std::cout << "Bill with order ID " << this->getOrderID() << " has been paid." << std::endl;
    }
}
