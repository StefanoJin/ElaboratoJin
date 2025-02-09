//
// Created by sjin0 on 2024/9/25.
//

#ifndef ELABORATOJIN_TODOLIST_H
#define ELABORATOJIN_TODOLIST_H

    //Revisione elaborato prima volta
    //1.subject,observer conta quante volte viene chiamato
    //2.quante attivita sono ancora da completare
    //3.modifica attivita
    //4.cerca attivita per stringa

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
    Activity& getActivity(int index);

    //return number of activities
    int getActivityCount() const {
        return activity.size();
    }

    //return activity by string
    vector<Activity> searchActivity(const string& keyword) const;
};

#endif //ELABORATOJIN_TODOLIST_H
