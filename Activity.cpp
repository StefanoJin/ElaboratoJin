//
// Created by sjin0 on 2024/9/25.
//

#include "Activity.h"
//constructor
Activity::Activity(const string& t, const string& d, bool c) : title(t), description(d), complete(c) {}

//getters
const string &Activity::getTitle() const {
    return title;
}

const string &Activity::getDescription() const {
    return description;
}

bool Activity::isComplete() const {
    return complete;
}

//setter
void Activity::setComplete(bool complete) {
    Activity::complete = complete;
}

//metodo per ottenere rappresentazione in stringa dell'attività
string Activity::toString() const{
    return title + " - " + description +(complete ? " [Completato]" : " [Non comlpetato]");
}

//metodo per salvare l'attività in formato string
string Activity::serialize() const{
    return title + ", " + description + ", " + (complete ? "1" : "0")+ "\n";
}

//metodo per caricare un'activity da una string serielizzata
Activity Activity::deserialize(const string& line){
    int pos1 = line.find(",");
    int pos2 = line.find(",", pos1 + 1);

    string title = line.substr(0, pos1);
    string description = line.substr(pos1 + 1, pos2 - pos1 -1);
    bool complete = line[pos2 +1 ] == '1';

    return Activity(title, description, complete);
}
