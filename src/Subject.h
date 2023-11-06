/**
 * @file Subject.h
 * @brief Contains the declaration of the Subject class.
 */

#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <vector>
#include "Observer.h"

/**
 * @class Subject
 * @brief The Subject class represents the subject of the observer pattern.
 */
class Subject {

private:
	std::vector<Observer*> ObserverList;
	Observer* observer;

public:
	/**
     * @brief Attach an observer to the subject.
     * @param observer A pointer to the Observer to be attached.
     * @return True if the attachment is successful, otherwise false.
     */
	virtual bool attach(Observer* observer);

	/**
     * @brief Detach an observer from the subject.
     * @param observer A pointer to the Observer to be detached.
     * @return True if the detachment is successful, otherwise false.
     */
	virtual bool detach(Observer* observer);

	/**
     * @brief Notify all observers with a message.
     * @param message A string representing the notification message.
     */
	virtual void notify(std::string message);
};

#endif
