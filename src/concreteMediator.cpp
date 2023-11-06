/**
 * @file concreteMediator.cpp
 * @brief Contains the implementation of the concreteMediator class.
 */

#include "concreteMediator.h"
/**
 * @brief This method allows the mediator to notify chefs about a specific event.
 *
 * @param sender Pointer to the Chefs object who is sending the notification.
 * @param event String representing the event that occurred.
 */
void concreteMediator::notify(Chefs *sender, std::string event)
{
    if (event == "cook")
    {
        if (sender == headChef_)
        {
            std::cout << "-Head chef notifies\t->   The dish is ready to be passed on   ->   ";
        }
        else if (sender == juniorChef_)
        {
            std::cout << "\033[0;90m-Junior chef notifies\t->   The dish is ready to be passed on   ->   ";
        }
        else if (sender == meatChef_)
        {
            std::cout << "-Meat chef notifies\t->   The dish is ready to be passed on   ->   ";
        }
        else if (sender == sauceChef_)
        {
            std::cout << "-Sauce chef notifies\t->   The dish is ready to be passed on   ->   ";
        }
        else if (sender == vegChef_)
        {
            std::cout << "-Vegetable chef notifies->   The dish is ready to be passed on   ->   ";
        }
    }
}

concreteMediator::~concreteMediator()
{
    delete headChef_;
    delete juniorChef_;
    delete meatChef_;
    delete sauceChef_;
    delete vegChef_;
};