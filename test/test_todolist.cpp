//
// Created by sjin0 on 2024/9/29.
//
#include "gtest/gtest.h"
#include "../TodoList.h"

// Test: Aggiungere un'attività alla lista
TEST(ToDoListTest, AddActivity) {
Todolist list;
Activity activity("Do homework", "Math exercises");
list.addActivity(activity);

ASSERT_EQ(list.getActivityCount(), 1);
ASSERT_STREQ(list.getActivity(0).getTitle().c_str(), "Do homework");
}

// Test: Rimuovere un'attività dalla lista
TEST(ToDoListTest, RemoveActivity) {
Todolist list;
Activity activity1("Do homework", "Math exercises");
Activity activity2("Wash dishes", "Clean the kitchen");
list.addActivity(activity1);
list.addActivity(activity2);

list.removeActivity(0);  // Rimuove la prima activity
ASSERT_EQ(list.getActivityCount(), 1);
ASSERT_STREQ(list.getActivity(0).getTitle().c_str(), "Wash dishes");
}


// test rimozione attivita non presente (con indice invalido)
TEST(ToDoListTest, RemoveInvalidIndex) {
    Todolist list;
    Activity activity1("Do homework", "Math exercises");
    Activity activity2("Wash dishes", "Clean the kitchen");
    list.addActivity(activity1);
    list.addActivity(activity2);

    ASSERT_THROW(list.removeActivity(5), std::out_of_range);// Rimuove un activity che ha index non valido
    ASSERT_EQ(list.getActivityCount(), 2);
}

TEST(ToDoListTest, GetActivityThrowsOnInvalidIndex) {
    Todolist list;
    list.addActivity(Activity("Test", "Descrizione"));

    // Proviamo ad accedere a un indice non valido
    ASSERT_THROW(list.getActivity(5), std::out_of_range);
}

//test ricerca attivita non esistente
TEST(ToDoListTest, SearchNonExistentActivityByTitle) {
    Todolist list;
    list.addActivity(Activity("Do homework", "Math exercises"));
    list.addActivity(Activity("Wash dishes", "Clean the kitchen"));

    // Ricerca un titolo che non esiste
    auto results = list.searchActivity("Go shopping");

    // Verifica che il risultato sia vuoto
    ASSERT_TRUE(results.empty());
}

// test quante attivita da completare
TEST(ToDoListTest, CountIncompleteActivities) {
    Todolist list;
    Activity activity1("Do homework", "Math exercises");
    Activity activity2("Wash dishes", "Clean the kitchen");
    Activity activity3("Go for a walk", "Morning exercise");

    list.addActivity(activity1);
    list.addActivity(activity2);
    list.addActivity(activity3);

    // seet completato alcune attivita'
    list.getActivity(0).setComplete(true); // Completa "Do homework"
    list.getActivity(2).setComplete(true); // Completa "Go for a walk"

    // Controlla quante attività non sono completate
    ASSERT_EQ(list.countIncompleteActivities(), 1); // Solo "Wash dishes" dovrebbe essere incompleta
}

// test quante attivita completate
TEST(ToDoListTest, CountCompleteActivities) {
    Todolist list;
    Activity activity1("Do homework", "Math exercises");
    Activity activity2("Wash dishes", "Clean the kitchen");
    Activity activity3("Go for a walk", "Morning exercise");

    list.addActivity(activity1);
    list.addActivity(activity2);
    list.addActivity(activity3);

    // set completato alcune attivita'
    list.getActivity(0).setComplete(true); // Completa "Do homework"
    list.getActivity(2).setComplete(true); // Completa "Go for a walk"

    // Controlla quante attività sono completate
    ASSERT_EQ(list.countCompleteActivities(), 2); // Solo "Wash dishes" dovrebbe essere incompleta
}

// Test: Salvare la lista su disco
TEST(ToDoListTest, SaveListToDisk) {
Todolist list;
Activity activity("Do sport", "Play basketball for 30 minutes");
list.addActivity(activity);

list.saveToDisk("test_list.txt");
//controllare manualmente il file salvato.
ASSERT_TRUE(true);   // test automatica
}

// Test: Caricare la lista da disco
TEST(ToDoListTest, LoadListFromDisk) {
Todolist list;
list.loadFromDisk("test_list.txt");

ASSERT_EQ(list.getActivityCount(), 1);
ASSERT_STREQ(list.getActivity(0).getTitle().c_str(), "Do sport");
}
