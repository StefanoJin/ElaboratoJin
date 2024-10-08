//
// Created by sjin0 on 2024/9/25.
//

#include "Todolist.h"
#include <fstream>
#include <iostream>

//add a new activity
void Todolist::addActivity(const Activity& act){
    activity.push_back(act);
}

//remove activity by index
void Todolist::removeActivity(int index){
    if(index < activity.size())
        activity.erase(activity.begin() + index);
}

//print all activities
void Todolist::print() const{
    for(int i = 0; i < activity.size(); ++i)
        cout << i + 1 << ". " << activity[i].toString() << endl;
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
        cerr << "Error - cannot open the file." << endl;
}

Activity& Todolist::getActivity(int index){
    if (index < 0 || index >= activity.size()) {
        throw std::out_of_range("Invalid index");
    }
    return activity[index];
}
