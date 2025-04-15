//
// Created by StefanoJin on 2025/3/27.
//

#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include "Observer.h"

class Subject {
protected:
    std::list<Observer*> observers;
public:
    virtual ~Subject() = default;

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.remove(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};



#endif //SUBJECT_H
