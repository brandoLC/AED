/*
//
// Created by brando on 1/22/25.
//

#include "hashTable.h"
#include <gtest/gtest.h>
#include <string>

TEST(UniversalHashTableTest, InsertAndRetrieve) {
    UniversalHashTable<std::string, int> hashTable(10, 101); // Tamaño de tabla = 10, primo = 101

    hashTable.insert("clave1", 10);
    hashTable.insert("clave2", 20);
    hashTable.insert("clave3", 30);

    int value;
    EXPECT_TRUE(hashTable.search("clave1", value));
    EXPECT_EQ(value, 10);

    EXPECT_TRUE(hashTable.search("clave2", value));
    EXPECT_EQ(value, 20);

    EXPECT_TRUE(hashTable.search("clave3", value));
    EXPECT_EQ(value, 30);
}

// Test 2: Actualizar un valor existente
TEST(UniversalHashTableTest, UpdateValue) {
    UniversalHashTable<std::string, int> hashTable(10, 101);

    hashTable.insert("clave1", 10);
    hashTable.insert("clave1", 100); // Actualizamos el valor de "clave1"

    int value;
    EXPECT_TRUE(hashTable.search("clave1", value));
    EXPECT_EQ(value, 100);
}

// Test 3: Eliminar una clave
TEST(UniversalHashTableTest, RemoveKey) {
    UniversalHashTable<std::string, int> hashTable(10, 101);

    hashTable.insert("clave1", 10);
    hashTable.insert("clave2", 20);

    EXPECT_TRUE(hashTable.remove("clave2")); // Eliminamos "clave2"

    int value;
    EXPECT_FALSE(hashTable.search("clave2", value)); // "clave2" ya no debería existir
}

// Test 4: Buscar una clave inexistente
TEST(UniversalHashTableTest, SearchNonExistentKey) {
    UniversalHashTable<std::string, int> hashTable(10, 101);

    int value;
    EXPECT_FALSE(hashTable.search("claveNoExiste", value));
}

// Test 5: Insertar múltiples elementos y verificar colisiones
TEST(UniversalHashTableTest, InsertMultipleElements) {
    UniversalHashTable<std::string, int> hashTable(10, 101);

    for (int i = 1; i <= 20; ++i) {
        hashTable.insert("key" + std::to_string(i), i);
    }

    int value;
    for (int i = 1; i <= 20; ++i) {
        EXPECT_TRUE(hashTable.search("key" + std::to_string(i), value));
        EXPECT_EQ(value, i);
    }
}

// Test 6: Eliminar una clave que no existe
TEST(UniversalHashTableTest, RemoveNonExistentKey) {
    UniversalHashTable<std::string, int> hashTable(10, 101);

    EXPECT_FALSE(hashTable.remove("claveInexistente"));
}

// Test 7: Tabla vacía inicialmente
TEST(UniversalHashTableTest, EmptyTableBehavior) {
    UniversalHashTable<int, std::string> hashTable(5, 101); // Tabla hash vacía

    std::string value;
    EXPECT_FALSE(hashTable.search(1, value)); // No debería encontrar nada
    EXPECT_FALSE(hashTable.remove(1));        // No debería poder eliminar nada
}
*/
