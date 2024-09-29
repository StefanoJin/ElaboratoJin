
/*Elaborato n. 10
 *  Classi che rappresentano attività da svolgere (es. per todolist).
 *  Deve essere possibile scrivere e leggere da disco l'elenco delle attività.*/

#include <iostream>
#include "Todolist.h"
#include "ToDoInterface.h"

int main() {
    Todolist list;
    ToDoInterface interface(list);

    bool exit = false;

    while (!exit) {
        interface.printMenu();
        int choice;
        cin >> choice;
        cin.ignore();  // Per eliminare il newline rimanente nel buffer di input

        switch (choice) {
            case 1:
                interface.add();
                break;
            case 2:
                interface.remove();
                break;
            case 3:
                interface.showActivity();
                break;
            case 4:
                interface.saveList();
                break;
            case 5:
                interface.loadList();
                break;
            case 6:
                interface.changeState();
                break;
            case 0:
                exit = true;
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}
