/**
 * @file Observer.h
 * @brief Contains the declaration of the Observer class.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>

/**
 * @class Observer
 * @brief The Observer class represents an observer in the observer pattern.
 */
class Observer {
public:
    /**
     * @brief Update the observer with a message.
     * @param message A string representing the update message.
     */
    virtual void update(std::string message) = 0;
};

#endif
