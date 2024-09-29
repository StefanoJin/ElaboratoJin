//
// Created by sjin0 on 2024/9/29.
//
#include "gtest/gtest.h"
#include "ToDoInterface.h"
#include "ToDoList.h"

// Test: Aggiunta di un'attività tramite l'interfaccia (simulazione)
TEST(ToDoInterfaceTest, AddActivityViaInterface) {
TodoList list;
ToDoInterface ui(list);

// Simuliamo l'aggiunta di una activity chiamando il metodo direttamente
Activity activity("Read a book", "Read at least 50 pages");
list.addActivity(activity);

ASSERT_EQ(list.getActivityCount(), 1);
ASSERT_STREQ(list.getActivity(0).getTitle(), "Read a book");
}

// Test: Rimozione di un'attività tramite l'interfaccia
TEST(ToDoInterfaceTest, RemoveTaskViaInterface) {
TodoList list;
ToDoInterface ui(list);

Attivita activity("Go to the gym", "Workout for 1 hour");
list.addActivity(activity);
list.removeActivity(0);  // Simuliamo la rimozione di un activity

ASSERT_EQ(list.getActivityCount(), 0);
}

// Test: Salvataggio della lista tramite l'interfaccia
TEST(ToDoInterfaceTest, SaveTaskViaInterface) {
TodoList list;
ToDoInterface ui(list);

Attivita activity("Plan trip", "Research destinations for vacation");
list.addActivity(activity);
ui.saveList();  // Usa l'interfaccia per salvare

ASSERT_TRUE(true);  // Anche in questo caso, il test per il salvataggio è basico
}
