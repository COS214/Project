/**
 * @file concreteMediator.h
 * @brief Contains the declaration of the concreteMediator class.
 */

#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include <string>

#include "Mediator.h"
#include "Chefs.h"
#include "HeadChef.h"
#include "JuniorChef.h"
#include "MeatChef.h"
#include "SauceChef.h"
#include "VegetableChef.h"

using namespace std;

/**
 * @class concreteMediator
 * @brief Concrete mediator that handles communication between specific types of chefs.
 */
class concreteMediator : public Mediator {
public:
    /**
     * @brief Constructor.
     * @param headChef Pointer to the head chef.
     * @param junior Pointer to the junior chef.
     * @param meat Pointer to the meat chef.
     * @param sauce Pointer to the sauce chef.
     * @param veg Pointer to the vegetable chef.
     */
     concreteMediator(Chefs* headChef, Chefs* junior, Chefs* meat, Chefs* sauce, Chefs* veg) 
        : headChef_(headChef), juniorChef_(junior), meatChef_(meat), sauceChef_(sauce), vegChef_(veg) {}

    /**
     * @brief Notify the mediator of an event.
     * @param sender The chef sending the notification.
     * @param event The event that occurred.
     */
    void notify(Chefs* sender, std::string event) override;

    /**
     * @brief Destructor.
     */
    virtual ~concreteMediator();

private:
    Chefs* headChef_;
    Chefs* juniorChef_;
    Chefs* meatChef_;
    Chefs* sauceChef_;
    Chefs* vegChef_;
};

#endif
