/**
 * @file Bill.cpp
 * @brief Contains the implementation of the Bill class.
 */

#include "Bill.h"
#include <sstream>
#include <map>
using namespace std;

/**
 * @brief Constructor for the Bill class that takes orderID, customerID, totalAmount, tableNum, rating, tabID, and paid as parameters.
 *
 * @param orderID String representing the order ID.
 * @param customerID String representing the customer ID.
 * @param totalAmount Double representing the total amount.
 * @param tableNum Integer representing the table number.
 * @param rating Integer representing the rating.
 * @param tabID String representing the tab ID.
 * @param paid Boolean representing whether the bill is paid or not.
 */
Bill::Bill(
    string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid) : orderID(orderID), customerID(customerID), totalAmount(totalAmount), tableNum(tableNum), rating(rating), tabID(tabID), paid(paid)
{
}
/**
 * @brief This method creates a memento of the bill.
 *
 * @param orderID String representing the order ID.
 * @param customerID String representing the customer ID.
 * @param totalAmount Double representing the total amount.
 * @param tableNum Integer representing the table number.
 * @param rating Integer representing the rating.
 * @param tabID String representing the tab ID.
 * @param paid Boolean representing whether the bill is paid or not.
 * @return BillMemento object representing the memento of the bill.
 */
BillMemento Bill::createBillMemento(string orderID, string customerID, double totalAmount, int tableNum, int rating, string tabID, bool paid)
{
    return BillMemento(orderID, customerID, totalAmount, tableNum, rating, tabID, paid);
}

/**
 * @brief This method sets the memento of the bill.
 *
 * @param memento BillMemento object representing the memento to be set.
 */
void Bill::setBillMemento(BillMemento memento)
{
    this->billMemento = memento;
}
/**
 * @brief  Splits a bill into multiple bills.
 * @param  splitIntoNBills The number of bills to split into.
 * @param  bill The original bill to split.
 * @param  order The order number.
 * @param  customerIDs The array of customer IDs.
 * @return A map of split bills.
 */
map<string, Bill> Bill::splitBill(int splitIntoNBills, Bill bill, int order, std::string customerIDs[])
{
    // Calculate the new total amount for each split bill
    double newTotalAmount = bill.getTotalAmount(); // splitIntoNBills;

    // Create a map to store the split bills
    map<string, Bill> splitBills;

    // Generate and add split bills to the map
    for (int i = 1; i <= splitIntoNBills; ++i)
    {
        std::ostringstream idStream;
        idStream << "OID" << order;
        orderID = idStream.str();

        Bill splitBill(
            orderID, // You need a method to generate unique Order IDs
            customerIDs[i - 1],
            newTotalAmount,
            bill.getTableNum(),
            bill.getRating(),
            generateTabID(bill.getCustomerID()), // Use the generateTabID method
            bill.isPaid());

        splitBills[splitBill.getOrderID()] = splitBill;
        order++;
    }

    return splitBills;
}
/**
 * @brief  Generates a unique Tab ID.
 * @param  customerID The customer's ID.
 * @return The newly created Tab ID.
 */
string Bill::generateTabID(string customerID)
{
    hash<string> hasher;
    srand(hasher(customerID) + time(0)); /// seed the random with the customerID

    int randomDigits = rand() % 1000; /// generates random digits

    char randomLetter = static_cast<char>(std::rand() % 26 + 65); /// here we generate a random capital letter

    string tabID = "TID" + to_string(randomDigits) + randomLetter; /// put the string together

    return tabID; /// return the newly created TabID
}
/**
 * @brief  Gets the total amount of the bill.
 * @return The total amount of the bill.
 */
double Bill::getTotalAmount()
{
    return this->totalAmount;
}
/**
 * @brief  Generates a unique Order ID.
 * @return The newly created Order ID.
 */
string Bill::generateOrderID()
{
    hash<string> hasher;
    srand(time(0)); /// seed the random with the customerID

    int randomDigits = rand() % 1000; /// generates random digits

    char randomLetter = static_cast<char>(rand() % 26 + 65); /// here we generate a random capital letter

    string OID = "OID" + to_string(randomDigits) + randomLetter; /// put the string together

    return OID; /// return the newly created OrderID
}

string Bill::getCustomerID()
{
    return this->customerID;
}

int Bill::getTableNum()
{
    return this->tableNum;
}

int Bill::getRating()
{
    return this->rating;
}

string Bill::getOrderID()
{
    return this->orderID;
}

bool Bill::isPaid()
{
    return this->paid;
}

string Bill::getTabID()
{
    return this->tabID;
}

void Bill::pay()
{
    this->paid = true;
}

void Bill::payBill()
{
    if (this->isPaid())
    { /// check if the bill has been paid
        std::cout << "This bill has already been paid by " << this->getCustomerID() << std::endl;
    }
    else
    {
        this->pay(); /// pay the bill
        std::cout << "Bill with order ID " << this->getOrderID() << " has been paid by customer " << this->getCustomerID() << std::endl;
    }
}
/**
 * @brief This method restores the bill from a memento.
 *
 * @param memento BillMemento object representing the memento from which the bill is to be restored.
 */
void Bill::restoreFromMemento(BillMemento memento)
{
    this->orderID = memento.getOrderID();
    this->customerID = memento.getCustomerID();
    this->totalAmount = memento.getTotalAmount();
    this->tableNum = memento.getTableNum();
    this->rating = memento.getRating();
    this->tabID = memento.getTabID();
    this->paid = memento.getPaid();
}
/**
 * @brief This method returns a string representation of the bill.
 *
 * @return String representing the bill.
 */
string Bill::toString()
{
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
    }
    else
    {
        stemp += "Paid: No\n";
    }

    return stemp;
}
/**
 * @brief This operator allows the comparison of two Bill objects based on their order IDs.
 *
 * @param other The Bill object to be compared with.
 * @return true if the order ID of the current Bill object is less than the order ID of the other Bill object, false otherwise.
 */
bool Bill::operator<(const Bill &other) const
{
    return this->orderID < other.orderID;
}

Bill::Bill() : orderID(""), customerID(""), totalAmount(0.0), tableNum(0), rating(0), tabID(""), paid(false) {}
