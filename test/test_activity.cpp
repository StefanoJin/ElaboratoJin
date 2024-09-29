//
// Created by sjin0 on 2024/9/29.
//

#include "gtest/gtest.h"
#include "../TodoList.h"  // Include la definizione della classe Attivita

// Test: Creazione dell'attività con titolo e descrizione
TEST(TodoList, CreateActivity) {
Activity activity("Buy groceries", "Buy milk and eggs");
ASSERT_STREQ(activity.getTitle(), "Buy groceries");
ASSERT_STREQ(activity.getDescription(), "Buy milk and eggs");
ASSERT_FALSE(activity.isCompleted());
}

// Test: Stato di completamento dell'attività
TEST(TodoList, MarkAsCompleted) {
Activity activity("Clean house", "Clean the living room");
activity.markCompleted();
ASSERT_TRUE(activity.isCompleted());
}

// Test: Verifica che la descrizione venga impostata correttamente
TEST(TodoList, CheckDescription) {
Activity activity("Go jogging", "Run for 30 minutes");
ASSERT_STREQ(activity.getDescription(), "Run for 30 minutes");
}

