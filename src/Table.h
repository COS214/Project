#ifndef TABLE_H
#define TABLE_H

#include <list>
#include "Customer.h"

class Table : public Customer
{
private:
    int tableNumber;
    std::list<Customer *> customers;

public:
    Table();
    Table(int tableNumber);
    ~Table();
    int getTableNumber() { return this->tableNumber; }
    void addCustomer(Customer *newCustomer);
    std::list<Customer *> getCustomers();
};

#endif
