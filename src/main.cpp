#include <iostream>
#include "Bill.h"
#include "Tab.h"

// Function to test the Bill class
void testBill() {
    // Create a Bill
    Bill bill("123", "John", 50.0, 2, 4, "TAB001", false);

    // Test getTotalAmount
    double expectedTotalAmount = 50.0;
    double actualTotalAmount = bill.getTotalAmount(bill);
    if (expectedTotalAmount == actualTotalAmount) {
        std::cout << "getTotalAmount test passed" << std::endl;
    } else {
        std::cout << "getTotalAmount test failed" << std::endl;
    }

    // Add more test cases for other Bill methods
}

// Function to test the Tab class
void testTab() {
    // Create a Tab
    Tab tab;
    BillMemento memento("123", "John", 50.0, 2, 4, "TAB001", false);

    // Test addBill and getBillMemento
    tab.addBill(memento, "Order1");
    BillMemento retrievedMemento = tab.getBillMemento("Order1");

    if (retrievedMemento.getOrderID() == "123" && retrievedMemento.getCustomerID() == "John" && retrievedMemento.getTotalAmount() == 50.0) {
        std::cout << "addBill and getBillMemento test passed" << std::endl;
    } else {
        std::cout << "addBill and getBillMemento test failed" << std::endl;
    }

    // Add more test cases for other Tab methods
}

int main() {
    // Run the tests
    testBill();
    testTab();

    return 0;
}
