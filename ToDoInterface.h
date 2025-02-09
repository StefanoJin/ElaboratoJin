//
// Created by sjin0 on 2024/9/28.
//

#ifndef ELABORATOJIN_TODOINTERFACE_H
#define ELABORATOJIN_TODOINTERFACE_H

#include "Todolist.h"
#include "Observer.h"

class ToDoInterface : public Observer {
private:
    Todolist& list;

public:
    //constructor
    ToDoInterface(Todolist &list);

    //method for interface
    void printMenu() const;
    void add();
    void remove();
    void showActivity();
    void saveList();
    void loadList();
    void changeState();
    void search();
    void showIncompleteCount();

    void update() override {
        // When notified, show the number of incomplete activities.
        cout << "Incomplete activities: " << list.countIncompleteActivities() << endl;
    }
};


#endif //ELABORATOJIN_TODOINTERFACE_H
