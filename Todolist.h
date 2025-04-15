//
// Created by sjin0 on 2024/9/25.
//

#ifndef ELABORATOJIN_TODOLIST_H
#define ELABORATOJIN_TODOLIST_H

#include <list>
#include <string>
#include "Activity.h"
#include "Observer.h"
#include "Subject.h"


class Todolist : public Subject{
private:
    std::list<Activity> activity;

public:
    //add a new activity
    void addActivity(const Activity& act);

    //remove activity by index
    void removeActivity(int index);

    //print all activities
    void print() const;

    //print only incompleted
    void printIncompleted() const;

    //save todolist on disk
    void saveToDisk(const string& fileName) const;

    //download todolist from disk
    void loadFromDisk(const string& filename);

    // return activity by index
    Activity& getActivity(int index);

    //return number of activities
    int getActivityCount() const {
        return activity.size();
    }

    //return activity by string
    //usa lista
    list<Activity> searchActivity(const std::string& keyword) const;

    //count incompleted activities
    int countIncompleteActivities() const;

 /*   // add observer
    void addObserver(Observer* observer);

    // remove observer
    void removeObserver(Observer* observer);

    // notify observer
    void notifyObservers();*/
};

#endif //ELABORATOJIN_TODOLIST_H
