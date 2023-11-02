#include "Subject.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"


bool Subject::attach(Observer* observer) {
	ObserverList.push_back(observer);
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
