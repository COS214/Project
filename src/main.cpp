#include <iostream>
#include "Bill.h"
#include "Tab.h"
#include "Customer.h"

using namespace std;

void testBill() {

    cout << "Billtest =============================================" << endl;
    ///create a new bill
    Bill bill("OID234H", "CID785K", 50.0, 15, 2, bill.generateTabID("CID785K"), false);

    ///expect a certain amount
    double expectedTotalAmount = 50.0;
    double actualTotalAmount = bill.getTotalAmount(); //check if you get the expected amount back
    if (expectedTotalAmount == actualTotalAmount) {
        cout << "getTotalAmount test passed" << endl;
    } else {
        cout << "getTotalAmount test failed" << endl;
    }

    cout << "Billtest end ===================================================================" << endl;
    
}

void testTab() {
    cout << "Tab test ===================================================================" << endl;
    /// create a new tab
    Tab tab;
    BillMemento memento("OID354B", "CID934D", 42.1, 7, 2, "TID149L", false);

    ///add bill to tab
    tab.addBill(memento, memento.getOrderID());
    BillMemento retrievedMemento = tab.getBillMemento("OID354B");

    ///use memento to test memento functionality
    if (retrievedMemento.getOrderID() == "OID354B" && retrievedMemento.getCustomerID() == "CID934D" && retrievedMemento.getTotalAmount() == 42.1) {
        cout << "addBill and getBillMemento test passed" << endl;
    } else {
        cout << "addBill and getBillMemento test failed" << endl;
    }
    cout << "Tab test end ==============================================================" << endl;
}

void testCustomer() {
    cout << "Customer test  ===============================================================" << endl;
    /// Create a customer
    Customer customer;

    /// check to see if the customer has received an id successfully
    string customerID = customer.getCustomerID();
    if (!customerID.empty()) {
        cout << "Customer creation and customer ID assignment test passed" << endl;
    } else {
        cout << "Customer creation and customer ID assignment test failed" << endl;
    }
    cout << "Customer test end  ===============================================================" << endl;
}

void testCustomerAndTab() {
    cout << "Customer test and Tab test ==================================================================" << endl;
    /// Create a customer
    Customer customer;
    string customerID = customer.getCustomerID();

    /// make a new bill using the customerID
    Bill bill1(bill1.generateOrderID(), customerID, 402.4, 24, 3, bill1.generateTabID(customerID), false);

    /// Split the bill into 5 bills
    int splitIntoNBills = 5;
    map<string, BillMemento> splitBills;

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
    cout << "Customer with ID " << customerID << " needs to pay R" << totalPayment << " for their meals." << endl;

    // Add a bill to the tab
    tab.addBill(splitBills.begin()->second, splitBills.begin()->first);

    // Simulate paying all bills in the tab
    tab.payAllBills();

    // Display that all bills in the tab have been paid
    cout << "All bills in the current tab have been paid." << endl;

    ///make the customer pay a bill
    bill1.payBill();

    ///METHOD TO show the functionality of memento and restore
    Bill bill3("OID457P", "CID956M", 59.4, 15, 1, "TID347C", false);

    /// Save the current bill into memento
    BillMemento memento = bill3.createBillMemento(bill3.getOrderID(), bill3.getCustomerID(), bill3.getTotalAmount(), bill3.getTableNum(), bill3.getRating(), bill3.getTabID(), bill3.isPaid());

    /// Restore the bill from the memento 
    bill3.restoreFromMemento(memento);
    
    ///pay the restored bill
    bill3.payBill();
    
    cout << bill3.toString();

    cout << "Customer test and Tab test end ==================================================================" << endl;
}


int main() {
    ///run the tests
    testBill();
    testTab();
    testCustomer();
    testCustomerAndTab();

    return 0;
}
