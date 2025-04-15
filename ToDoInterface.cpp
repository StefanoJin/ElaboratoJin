//
// Created by sjin0 on 2024/9/28.
//

#include "ToDoInterface.h"
#include <iostream>

//constructor
ToDoInterface::ToDoInterface(Todolist &list) : list(list) {}

//interface methods
void ToDoInterface::printMenu() const{
    cout << "\n=== TO-DO LIST MENU ===" << endl;
    cout << "1. Add activity" << endl;
    cout << "2. Remove activity" << endl;
    cout << "3. Show activities" << endl;
    cout << "4. Save list to disk" << endl;
    cout << "5. Load list from  " << endl;
    cout << "6. Change state of activity" << endl;
    cout << "7. Search activity" << endl;
    cout << "8. Show incomplete activities" << endl;
    cout << "9. Show number of all activities" << endl;
    cout << "10. Modify activity" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose an option: ";
}

void ToDoInterface::add(){
    string title, description;
    cout << "Enter the activity title: ";
    getline(std::cin, title);
    cout << "Enter the activity description: ";
    getline(std::cin, description);
    list.addActivity(Activity(title, description));
    cout << "Activity added successfully!" << endl;
}

void ToDoInterface::remove(){
    list.print();
    int index;
    cout << "Enter the activity number to remove: ";
    cin >> index;

    cin.ignore();  // per ignorare il newline rimasto nel buffer
    list.removeActivity(index - 1);  // Il numero mostrato è 1-based
    cout << "Activity removed successfully!" << std::endl;
}

void ToDoInterface::showActivity(){
    list.print();
    list.notifyObservers();
}

//Metodo per google test
/*void ToDoInterface::saveList(const std::string& fileName){
    list.saveToDisk(fileName);
    cout << "List saved successfully to " << fileName << endl;
}*/

void ToDoInterface::saveList(){
    string fileName;
    cout << "Enter the filename: ";
    getline(cin, fileName);
    list.saveToDisk(fileName);
    cout << "List saved successfully to " << fileName << endl;
}

void ToDoInterface::loadList(){
    string fileName;
    cout << "Enter the filename: ";
    getline(std::cin, fileName);
    list.loadFromDisk(fileName);
    cout << "List loaded successfully from " << fileName << std::endl;
}

void ToDoInterface::changeState(){
    list.print();
    int index;
    cout << "Enter the activity number to change state: ";
    cin >> index;

    // Controlla se l'indice è valido
    if (index-1 < 0 || index-1 >= list.getActivityCount()) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    list.getActivity(index-1).markCompleted();
    cout << "Activity state changed successfully!" << endl;
    list.notifyObservers();
}

//search activity by key word
void ToDoInterface::search() {
    string keyword;
    cout << "Enter a keyword to search: ";
    getline(cin, keyword);

    std::list<Activity> results = list.searchActivity(keyword);

    if (results.empty()) {
        cout << "No activities found matching: " << keyword << endl;
    } else {
        cout << "Activities found:" << endl;
        for (const auto& act : results) {
            cout << "- " << act.toString() << endl;
        }
    }
}

//count incompleted activities
void ToDoInterface::showIncompleteCount() {
    cout << "--- There are " << list.countIncompleteActivities() << " activities still incomplete. ---" << endl;
    list.printIncompleted();
}

//count all activities
void ToDoInterface::ActivityCount() {
    cout << "There are " << list.getActivityCount() << " activities in TODOLIST." << endl;
}

//modify activity
void ToDoInterface::Modify() {
    list.print();

    int activityNumber;
    cout << "Enter the number of the activity to modify: ";
    cin >> activityNumber;

    // Vefify index
    if (activityNumber < 1 || activityNumber > list.getActivityCount()) {
        cout << "Invalid activity number!" << endl;
        return;
    }

    // Get the activity to modify
    Activity& act = list.getActivity(activityNumber - 1);

    string newTitle, newDescription;
    cout << "Enter the new title: ";
    cin.ignore();
    getline(cin, newTitle);
    cout << "Enter the new description: ";
    getline(cin, newDescription);

    act.setTitle(newTitle);
    act.setDescription(newDescription);

    cout << "Activity modified successfully!" << endl;
    list.notifyObservers();
}

