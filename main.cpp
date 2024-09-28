
/*Elaborato n. 10
 *  Classi che rappresentano attività da svolgere (es. per todolist).
 *  Deve essere possibile scrivere e leggere da disco l'elenco delle attività.*/

#include <iostream>
#include "Todolist.h"

int main() {
    Todolist list;

    //add activities
    list.addActivity(Activity("Fare la spesa", "comprare frutta e verdura"));
    list.addActivity(Activity("Studiare C++", "completare il capitolo sulla gestione dei file"));

    //save list on disco
    list.saveOnDisc("todolist.txt");

    //print list
    cout << "Activities list: " << endl;
    list.print();

    //load from disc and print
    cout << "\nLoading list from disc..." << endl;
    list.downloadFromDisc("todolist.txt");
    list.print();

    return 0;
}
