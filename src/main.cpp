#include <iostream>
#include "Bill.h"
#include "Tab.h"
#include "Customer.h"

void testBill() {
    ///create a new bill
    Bill bill("123", "John", 50.0, 2, 4, "TAB001", false);

    ///expect a certain amount
    double expectedTotalAmount = 50.0;
    double actualTotalAmount = bill.getTotalAmount(); //check if you get the expected amount back
    if (expectedTotalAmount == actualTotalAmount) {
        std::cout << "getTotalAmount test passed" << std::endl;
    } else {
        std::cout << "getTotalAmount test failed" << std::endl;
    }

    
}

void testTab() {
    /// create a new tab
    Tab tab;
    BillMemento memento("123", "John", 50.0, 2, 4, "TAB001", false);

    ///add bill to tab
    tab.addBill(memento, "Order1");
    BillMemento retrievedMemento = tab.getBillMemento("Order1");

    ///use memento to test memento functionality
    if (retrievedMemento.getOrderID() == "123" && retrievedMemento.getCustomerID() == "John" && retrievedMemento.getTotalAmount() == 50.0) {
        std::cout << "addBill and getBillMemento test passed" << std::endl;
    } else {
        std::cout << "addBill and getBillMemento test failed" << std::endl;
    }
}

void testCustomer() {
    /// Create a customer
    Customer customer;

    /// check to see if the customer has received an id successfully
    std::string customerID = customer.getCustomerID();
    if (!customerID.empty()) {
        std::cout << "Customer creation and customer ID assignment test passed" << std::endl;
    } else {
        std::cout << "Customer creation and customer ID assignment test failed" << std::endl;
    }
}

void testCustomerAndTab() {
    /// Create a customer
    Customer customer;
    std::string customerID = customer.getCustomerID();

    /// make a new bill using the customerID
    Bill bill1(bill1.generateOrderID(), customerID, 50.0, 2, 4, bill1.generateTabID(customerID), false);

    /// Split the bill into 5 bills
    int splitIntoNBills = 5;
    std::map<std::string, BillMemento> splitBills;

    /// Create and add split bills to the map with unique order IDs
    for (int i = 0; i < splitIntoNBills; ++i) {
        BillMemento memento = bill1.createBillMemento(bill1.getOrderID(), bill1.getCustomerID(), bill1.getTotalAmount(), bill1.getTableNum(), bill1.getRating(), bill1.getTabID(), bill1.isPaid());
        splitBills[memento.getOrderID()] = memento;
    }

    /// Make a Tab where we add one of the splitbills
    Tab tab;
    tab.addBill(splitBills.begin()->second, splitBills.begin()->first);

    ///make a new customer
    Customer customer2;

    /// Add another bill to the same tab
    Bill bill2(bill2.generateOrderID(), customer2.getCustomerID(), 40.0, 2, 5, bill2.generateTabID(customerID), false);
    tab.addBill(bill2.createBillMemento(bill2.getOrderID(), bill2.getCustomerID(), bill2.getTotalAmount(), bill2.getTableNum(), bill2.getRating(), bill2.getTabID(), bill2.isPaid()), bill2.getOrderID());

    /// Fetch the tab
    BillMemento Tab = tab.getBillMemento(bill2.getOrderID());

    /// Calculate the total payment to pay from the tab
    double totalPayment = 0.0;
    auto it = splitBills.begin();
    while (it != splitBills.end()) {
        totalPayment += it->second.getTotalAmount();
        ++it;
    }

    /// Display what the customer needs to pay
    std::cout << "Customer with ID " << customerID << " needs to pay $" << totalPayment << " for their meals." << std::endl;

    ///make the customer pay a bill
    bill1.payBill();
}


int main() {
    ///run the tests
    testBill();
    testTab();
    testCustomer();
    testCustomerAndTab();

    return 0;
}
