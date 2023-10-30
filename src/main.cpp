#include <iostream>
#include "Bill.h"
#include "Tab.h"

void testBill() {
    ///create a new bill
    Bill bill("123", "John", 50.0, 2, 4, "TAB001", false);

    ///expect a certain amount
    double expectedTotalAmount = 50.0;
    double actualTotalAmount = bill.getTotalAmount(bill); //check if you get the expected amount back
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

int main() {
    ///run the tests
    testBill();
    testTab();

    return 0;
}
