//
// Created by brano on 29/01/2025.
//
#include "SkipList.h"
#include <gtest/gtest.h>
#include <vector>

// Test: Inserción de elementos y búsqueda
TEST(SkipListTest, InsertAndSearch) {
    SkipList skiplist;

    skiplist.insert(10);
    skiplist.insert(5);
    skiplist.insert(15);
    skiplist.insert(3);
    skiplist.insert(7);

    EXPECT_TRUE(skiplist.search(10));
    EXPECT_TRUE(skiplist.search(5));
    EXPECT_TRUE(skiplist.search(15));
    EXPECT_TRUE(skiplist.search(3));
    EXPECT_TRUE(skiplist.search(7));
    EXPECT_FALSE(skiplist.search(20));
}

// Test: Eliminación de elementos
TEST(SkipListTest, RemoveElement) {
    SkipList skiplist;

    skiplist.insert(10);
    skiplist.insert(5);
    skiplist.insert(15);
    skiplist.insert(3);
    skiplist.insert(7);

    // Eliminar un nodo hoja
    skiplist.remove(3);
    EXPECT_FALSE(skiplist.search(3));

    // Eliminar un nodo con un solo hijo
    skiplist.remove(5);
    EXPECT_FALSE(skiplist.search(5));

    // Eliminar un nodo con dos hijos
    skiplist.remove(10);
    EXPECT_FALSE(skiplist.search(10));
}

// Test: Inserción de elementos duplicados
TEST(SkipListTest, InsertDuplicate) {
    SkipList skiplist;

    skiplist.insert(10);
    skiplist.insert(10);

    // Verificar que el elemento duplicado se ha insertado
    EXPECT_TRUE(skiplist.search(10));
}

// Test: Búsqueda en una lista vacía
TEST(SkipListTest, SearchEmptyList) {
    SkipList skiplist;

    EXPECT_FALSE(skiplist.search(10));
}

// Test: Eliminar de una lista vacía
TEST(SkipListTest, RemoveFromEmptyList) {
    SkipList skiplist;

    skiplist.remove(10);
    EXPECT_FALSE(skiplist.search(10));
}


