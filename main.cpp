
/*Elaborato n. 10
 *  Classi che rappresentano attività da svolgere (es. per todolist).
 *  Deve essere possibile scrivere e leggere da disco l'elenco delle attività.*/

//Revisione elaborato prima volta
    //1.subject,observer conta quante volte viene chiamato
    //2.quante attivita sono ancora da completare
    //3.cerca attivita per stringa
    //4.sistemare googletest

//Seconda revisione elaborato
    //1.attivita in tutto presente ✓
    //2.Subject: uso lista invece di vector ✓
    //3.modifica attivita ✓
    //4.todolist usa lista invece di vector ✓
    //5.test rimozione attivita non presente ✓
    //5.test attivita non esistente
    //6.test quante attivita da completare
    //7.sistemare il test del load e save
//

#include <iostream>
#include "Todolist.h"
#include "ToDoInterface.h"

int main() {
    Todolist list;
    ToDoInterface interface(list);

    list.addObserver(&interface);

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
            case 7:
                interface.search();
            break;
            case 8:
                interface.showIncompleteCount();
            break;
            case 9:
                interface.ActivityCount();
            break;
            case 10:
                interface.Modify();
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
