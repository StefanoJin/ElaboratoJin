//
// Created by sjin0 on 2024/9/25.
//

#ifndef ELABORATOJIN_TODOLIST_H
#define ELABORATOJIN_TODOLIST_H

#include <vector>
#include <string>
#include "Activity.h"

class Todolist {
private:
    vector<Activity> activity;

public:
    //add a new activity
    void addActivity(const Activity& act);

    //remove activity by index
    void removeActivity(int index);

    //print all activities
    void print() const;

    //save todolist on disk
    void saveToDisk(const string& fileName) const;

    //download todolist from disk
    void loadFromDisk(const string& filename);

    // return activity by index
    const Activity& getActivity(int index);

    //return number of activities
    int getActivityCount() const {
        return activity.size();
    }
};

#endif //ELABORATOJIN_TODOLIST_H
