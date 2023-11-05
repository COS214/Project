/**
 * @file Subject.cpp
 * @brief Contains the declaration of the Subject class functions.
 */

#include "Subject.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"


bool Subject::attach(Observer* observer) {
	ObserverList.push_back(observer);
	//std::cout << "Waiter attached to customer" << endl;
	return true;
}

bool Subject::detach(Observer* observer) {
	auto it = find(ObserverList.begin(), ObserverList.end(), observer);
        if (it != ObserverList.end()) {
            ObserverList.erase(it);
            return true;
        }
        return false;
}

void Subject::notify(std::string message) {
	for (Observer* observer : ObserverList) {
		observer->update(message);
	}
}
