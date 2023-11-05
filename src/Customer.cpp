#include <iostream>
#include <sstream>
#include "Customer.h"
#include "Arrived.h"

Customer::Customer()
{
    // std::cout << "Customer has arrived!" << std::endl;
    state = new Arrived();
    std::string CID = generateCustomerID();
    setCustomerID(CID);
}
/**
 * @brief Constructor for the Customer class that takes a name and id as parameters.
 *
 * @param name String representing the name of the customer.
 * @param id Integer representing the id of the customer.
 */
Customer::Customer(std::string name, int id)
{
    this->name = name;
    std::ostringstream idStream;
    idStream << "CUST" << id;
    customerID = idStream.str();

    // std::string CID = generateCustomerID();
    // customerID=CID;

    // std::cout << name << " has arrived!" << std::endl;
    state = new Arrived();
}
Customer::~Customer()
{
    // std::cout << "Destructor called" << std::endl;
    delete state;
    state = 0;
}
/**
 * @brief This method sets the state of the customer.
 *
 * @param state_ Pointer to the State object to be set.
 */
void Customer::setState(State *state_)
{
    // std::cout << "setState called" << std::endl;
    if (state != nullptr)
    {
        delete state;
    }
    state = state_;
}
/**
 * @brief This method sets the rating of the customer.
 *
 * @param rating Integer representing the rating to be set.
 */
void Customer::setRating(int rating)
{
    this->rating = rating;
}

// ONLY EDITED HERE FOR OBSERVER FUNCTIONALITY
void Customer::change()
{
    state->handleChange(this);
    notify(getState());
}
/**
 * @brief This method returns the state of the customer.
 *
 * @return String representing the state of the customer.
 */
std::string Customer::getState()
{
    return state->getState();
}
/**
 * @brief This method sets the customer ID of the customer.
 *
 * @param cID String representing the customer ID to be set.
 */
void Customer::setCustomerID(std::string cID)
{
    this->CustomerID = cID;
}
/**
 * @brief This method generates a customer ID for the customer.
 *
 * @return String representing the generated customer ID.
 */
std::string Customer::generateCustomerID()
{
    std::hash<std::string> hasher;
    std::srand(std::time(0)); /// seed the random with the customerID

    int randomDigits = std::rand() % 1000; /// generates random digits

    char randomLetter = static_cast<char>(std::rand() % 26 + 65); /// here we generate a random capital letter

    std::string CID = "CID" + std::to_string(randomDigits) + randomLetter; /// put the string together

    return CID; /// return the newly created CustomerID
}
/**
 * @brief This method returns the order of the customer.
 *
 * @return String representing the order of the customer.
 */
std::string Customer::getOrder()
{
    return this->order;
}
/**
 * @brief This method returns the name of the customer.
 *
 * @return String representing the name of the customer.
 */
std::string Customer::getName()
{
    return this->name;
}
/**
 * @brief This method returns the customer ID of the customer.
 *
 * @return String representing the customer ID of the customer.
 */
std::string Customer::getCustomerID()
{
    std::string CID = generateCustomerID();
    setCustomerID(CID);
    return customerID;
}
/**
 * @brief This method returns the rating of the customer.
 *
 * @return Integer representing the rating of the customer.
 */
int Customer::getRating()
{
    return this->rating;
}

/**
 * @brief This method returns the total amount of the customer.
 *
 * @return Double representing the total amount of the customer.
 */
double Customer::getTotalAmount()
{
    return 0.0;
}
/**
 * @brief This method sets the dish of the customer.
 *
 * @param d Pointer to the Dish object to be set.
 */
void Customer::setDish(Dish *d)
{
    this->orderedDish = d;
}
/**
 * @brief This method returns the dish of the customer.
 *
 * @return Pointer to the Dish object of the customer.
 */
Dish *Customer::getDish()
{
    return this->orderedDish;
}
