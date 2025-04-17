//
// Created by sjin0 on 2024/9/25.
//

#include "Todolist.h"
#include <fstream>
#include <iostream>
#include <algorithm>  //std::remove

//add a new activity
void Todolist::addActivity(const Activity& act){
    activity.push_back(act);
    notifyObservers();
}

//remove activity by index
void Todolist::removeActivity(int index){
    if (index < 0 || index >= activity.size()) {
        throw std::out_of_range("Invalid index");
    }

    auto it = activity.begin();
    for (int i = 0; i < index; ++i) {
        ++it;
    }

    activity.erase(it);
    notifyObservers();
}

//print all activities
void Todolist::print() const{
    int index = 1;
    for (const auto& act : activity) {
        std::cout << index++ << ". " << act.toString() << std::endl;
    }
}

//print only incompleted
void Todolist::printIncompleted() const{
    int index = 1;
    for (const auto& act : activity) {
        if (!act.isCompleted()) {
            std::cout << index++ << ". " << act.toString() << std::endl;
        }
    }
}

//save todolist on disk
void Todolist::saveToDisk(const string& fileName) const{
    //file: write operation
    std::ofstream file(fileName);

    if(file.is_open()){
        for(const auto& act : activity)
            file << act.serialize();
        file.close();
    }else
        cerr << "Error - cannot open the file." << endl;
}

//download todolist from disk
void Todolist::loadFromDisk(const string& filename){
    activity.clear();

    //file: read operation
    ifstream file(filename);

    if(file.is_open()){
        activity.clear();
        string line;
        while(getline(file, line)){
            if(!line.empty())
                activity.push_back(Activity::deserialize(line));
        }
        file.close();
    }else
        cout << "Error - cannot open the file." << endl;
}

// return activity by index
Activity& Todolist::getActivity(int index){
    if (index < 0 || index >= activity.size()) {
        throw std::out_of_range("Indice non valido");
    }

    auto it = activity.begin();
    for (int i = 0; i < index; ++i) {
        ++it;
    }
    return *it;
}

//return activity by string
list<Activity> Todolist::searchActivity(const string& keyword) const {
    list<Activity> results;
    for (const auto& act : activity) {
        if (act.getTitle().find(keyword) != string::npos || act.getDescription().find(keyword) != string::npos) {
            results.push_back(act);
        }
    }
    return results;
}

//count incompleted activities
int Todolist::countIncompleteActivities() const {
    int count = 0;
    for (const auto& act : activity) {
        if (!act.isCompleted()) count++;
    }
    return count;
}

//count completed activities
int Todolist::countCompleteActivities() const {
    int count = 0;
    for (const auto& act : activity) {
        if (act.isCompleted()) count++;
    }
    return count;
}

//modify activity
bool Todolist::ModifyActivity(int index, const std::string& newTitle, const std::string& newDescription) {
    if (index < 0 || index >= activity.size()) {
        return false;
    }

    auto it = activity.begin();
    std::advance(it, index);  // Vai al giusto elemento

    it->setTitle(newTitle);
    it->setDescription(newDescription);

    notifyObservers();  // se serve
    return true;
}