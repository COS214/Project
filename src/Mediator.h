/**
 * @file Mediator.h
 * @brief Contains the declaration of the Mediator class.
 */

#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

using namespace std;

class Chefs;

/**
 * @class Mediator
 * @brief Abstract base class for a mediator that handles communication between chefs.
 */
class Mediator {
public:
    /**
     * @brief Notify the mediator of an event.
     * @param sender The chef sending the notification.
     * @param event The event that occurred.
     */
    virtual void notify(Chefs* sender, std::string event) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~Mediator();
};

#endif
