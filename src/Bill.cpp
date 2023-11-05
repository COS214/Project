/**
 * @file Bill.cpp
 * @brief Contains the implementation of the Bill class.
 */

#include "Bill.h"
#include <sstream>
#include <map>
using namespace std;


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

map<string, Bill> Bill::splitBill(int splitIntoNBills, Bill bill, int order, std::string customerIDs[]) {
    // Calculate the new total amount for each split bill
    double newTotalAmount = bill.getTotalAmount(); // splitIntoNBills;

    // Create a map to store the split bills
    map<string, Bill> splitBills;
    
    
    // Generate and add split bills to the map
    for (int i = 1; i <= splitIntoNBills; ++i) {
    std::ostringstream idStream;
    idStream << "OID" << order;
    orderID = idStream.str();

        Bill splitBill(
            orderID, // You need a method to generate unique Order IDs
            customerIDs[i-1],
            newTotalAmount,
            bill.getTableNum(),
            bill.getRating(),
            generateTabID(bill.getCustomerID()), // Use the generateTabID method
            bill.isPaid()
        );

     

        splitBills[splitBill.getOrderID()] = splitBill;
        order++;
    }

    return splitBills;
}


string Bill::generateTabID(string customerID) {
    hash<string> hasher;
    srand(hasher(customerID) + time(0)); ///seed the random with the customerID

    int randomDigits = rand() % 1000; ///generates random digits

    char randomLetter = static_cast<char>(std::rand() % 26 + 65); ///here we generate a random capital letter

    string tabID = "TID" + to_string(randomDigits) + randomLetter; ///put the string together

    return tabID; ///return the newly created TabID
}

double Bill::getTotalAmount(){
	return this->totalAmount;
}

string Bill::generateOrderID(){
	hash<string> hasher;
    srand(time(0)); ///seed the random with the customerID

    int randomDigits = rand() % 1000; ///generates random digits

    char randomLetter = static_cast<char>(rand() % 26 + 65); ///here we generate a random capital letter

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

string Bill::getOrderID(){
    return this->orderID;
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
    if (this->isPaid()) { ///check if the bill has been paid
        std::cout << "This bill has already been paid by "<< this->getCustomerID() << std::endl;
    } else {
        this->pay(); ///pay the bill
        std::cout << "Bill with order ID " << this->getOrderID() << " has been paid by customer "<< this->getCustomerID() << std::endl;
    }
}

void Bill::restoreFromMemento(BillMemento memento) {
    this->orderID = memento.getOrderID();
    this->customerID = memento.getCustomerID();
    this->totalAmount = memento.getTotalAmount();
    this->tableNum = memento.getTableNum();
    this->rating = memento.getRating();
    this->tabID = memento.getTabID();
    this->paid = memento.getPaid();
}

string Bill::toString() {
    std::string stemp;
    stemp += "Order ID: " + this->orderID + "\n";
    stemp += "Customer ID: " + customerID + "\n";
    stemp += "Total Amount: R" + std::to_string(totalAmount) + "\n";
    stemp += "Table Number: " + std::to_string(tableNum) + "\n";
    stemp += "Rating: " + std::to_string(rating) + "\n";
    stemp += "Tab ID: " + tabID + "\n";
    if (paid == true)
    {
       stemp += "Paid: Yes\n";
    } else {
        stemp += "Paid: No\n";
    }
    
    return stemp;
}

bool Bill::operator<(const Bill& other) const {
    return this->orderID < other.orderID;
}

Bill::Bill() : orderID(""), customerID(""), totalAmount(0.0), tableNum(0), rating(0), tabID(""), paid(false) {}

