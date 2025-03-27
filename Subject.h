//
// Created by StefanoJin on 2025/3/27.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"
#include <algorithm>

class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual ~Subject() = default;

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};



#endif //SUBJECT_H
