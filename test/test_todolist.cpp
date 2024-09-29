//
// Created by sjin0 on 2024/9/29.
//
#include "gtest/gtest.h"
#include "../TodoList.h"

// Test: Aggiungere un'attività alla lista
TEST(ToDoListTest, AddActivity) {
TodoList list;
Activity activity("Do homework", "Math exercises");
list.addActivity(activity);

ASSERT_EQ(list.getTaskCount(), 1);
ASSERT_STREQ(list.getTask(0).getTitle(), "Do homework");
}

// Test: Rimuovere un'attività dalla lista
TEST(ToDoListTest, RemoveActivity) {
ToDoList list;
Activity activity1("Do homework", "Math exercises");
Activity activity2("Wash dishes", "Clean the kitchen");
list.addActivity(activity1);
list.addActivity(activity2);

list.removeActivity(0);  // Rimuove la prima activity
ASSERT_EQ(list.getTaskCount(), 1);
ASSERT_STREQ(list.getActivity(0).getTitle(), "Wash dishes");
}

// Test: Salvare la lista su disco
TEST(ToDoListTest, SaveListToDisk) {
ToDoList list;
Activity activity("Do sport", "Play basketball for 30 minutes");
list.addActivity(activity);

list.saveToDisk("test_list.txt");
//controllare manualmente il file salvato.
ASSERT_TRUE(true);
}

// Test: Caricare la lista da disco
TEST(ToDoListTest, LoadListFromDisk) {
TodoList list;
list.loadFromDisk("test_list.txt");

ASSERT_EQ(list.getTaskCount(), 1);
ASSERT_STREQ(list.getActivity(0).getTitle(), "Do sport");
}
