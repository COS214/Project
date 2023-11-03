#include <iostream>
#include "Customer.h"
#include "Arrived.h"

Customer::Customer()
{
    std::cout << "Customer has arrived!" << std::endl;
    state = new Arrived();

    std::string CID = GenerateCustomerID();
    setCustomerID(CID);
}

Customer::Customer(std::string name)
{
    this->name = name;
    std::cout << name << " has arrived!" << std::endl;
    state = new Arrived();
}
Customer::~Customer()
{
    std::cout << "Destructor called" << std::endl;
    delete state;
    state = 0;
}

void Customer::setState(State *state_)
{
    std::cout << "setState called" << std::endl;
    delete state;
    state = state_;
}

// ONLY EDITED HERE FOR OBSERVER FUNCTIONALITY
void Customer::change()
{
    state->handleChange(this);
    std::string message = "State changed to " + state->getState();
    notify(message);
}

std::string Customer::getState()
{
    return state->getState();
}

void Customer::setCustomerID(std::string CID)
{
    this->CustomerID = CID;
}

std::string Customer::GenerateCustomerID()
{
    std::hash<std::string> hasher;
    std::srand(std::time(0)); /// seed the random with the customerID

    int randomDigits = std::rand() % 1000; /// generates random digits

    char randomLetter = static_cast<char>(std::rand() % 26 + 65); /// here we generate a random capital letter

    std::string CID = "CID" + std::to_string(randomDigits) + randomLetter; /// put the string together

    return CID; /// return the newly created CustomerID
}

std::string Customer::getOrder()
{
    return this->order;
}

std::string Customer::getName()
{
    return this->name;
}

std::string Customer::getCustomerID()
{
    return this->customerID;
}

int Customer::getRating()
{
    return this->rating;
}

int Customer::getTableNumber()
{
    return this->tableNumber;
}

double Customer::getTotalAmount()
{
    return 0.0;
}
