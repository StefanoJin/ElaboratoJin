//
// Created by sjin0 on 2024/9/25.
//

#ifndef ELABORATOJIN_ACTIVITY_H
#define ELABORATOJIN_ACTIVITY_H

#include <string>
using namespace std;

class Activity {
private:
    string title;
    string description;
    bool completed;

public:
    //constructor
    Activity(const string& t, const string& d, bool c = false);

    //getters
    const string &getTitle() const;
    const string &getDescription() const;
    bool isCompleted() const;

    //setters
    void setComplete(bool complete);

    //metodo per ottenere una rappresentazione stringa dell'attività
    string toString() const;

    //metodo per salvare l'attività in formato string
    string serialize() const;

    //metodo per caricare un'activity da una string serielizzata
    static Activity deserialize(const string& line);

    bool markCompleted();
};


#endif //ELABORATOJIN_ACTIVITY_H
