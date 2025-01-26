#include "hashTable_Set.h"
#include <gtest/gtest.h>
#include <string>

// Test: Inserción y búsqueda de elementos
TEST(HashSetTest, InsertAndFind) {
    HashSet<int> intSet;
    intSet.insert(10);
    intSet.insert(20);
    intSet.insert(30);

    EXPECT_TRUE(intSet.find(10));
    EXPECT_TRUE(intSet.find(20));
    EXPECT_TRUE(intSet.find(30));
    EXPECT_FALSE(intSet.find(40));

    HashSet<std::string> stringSet;
    stringSet.insert("apple");
    stringSet.insert("banana");
    stringSet.insert("cherry");

    EXPECT_TRUE(stringSet.find("apple"));
    EXPECT_TRUE(stringSet.find("banana"));
    EXPECT_TRUE(stringSet.find("cherry"));
    EXPECT_FALSE(stringSet.find("date"));

    HashSet<char> charSet;
    charSet.insert('a');
    charSet.insert('b');
    charSet.insert('c');

    EXPECT_TRUE(charSet.find('a'));
    EXPECT_TRUE(charSet.find('b'));
    EXPECT_TRUE(charSet.find('c'));
    EXPECT_FALSE(charSet.find('d'));
}

// Test: Eliminación de elementos
TEST(HashSetTest, RemoveElement) {
    HashSet<int> intSet;
    intSet.insert(10);
    intSet.insert(20);
    intSet.insert(30);

    intSet.remove(20);
    EXPECT_FALSE(intSet.find(20));
    EXPECT_TRUE(intSet.find(10));
    EXPECT_TRUE(intSet.find(30));

    HashSet<std::string> stringSet;
    stringSet.insert("apple");
    stringSet.insert("banana");
    stringSet.insert("cherry");

    stringSet.remove("banana");
    EXPECT_FALSE(stringSet.find("banana"));
    EXPECT_TRUE(stringSet.find("apple"));
    EXPECT_TRUE(stringSet.find("cherry"));

    HashSet<char> charSet;
    charSet.insert('a');
    charSet.insert('b');
    charSet.insert('c');

    charSet.remove('b');
    EXPECT_FALSE(charSet.find('b'));
    EXPECT_TRUE(charSet.find('a'));
    EXPECT_TRUE(charSet.find('c'));
}

// Test: Tamaño del conjunto
TEST(HashSetTest, GetSize) {
    HashSet<int> intSet;
    EXPECT_EQ(intSet.getSize(), 0);

    intSet.insert(10);
    intSet.insert(20);
    EXPECT_EQ(intSet.getSize(), 2);

    intSet.remove(10);
    EXPECT_EQ(intSet.getSize(), 1);

    HashSet<std::string> stringSet;
    EXPECT_EQ(stringSet.getSize(), 0);

    stringSet.insert("apple");
    stringSet.insert("banana");
    EXPECT_EQ(stringSet.getSize(), 2);

    stringSet.remove("apple");
    EXPECT_EQ(stringSet.getSize(), 1);
}

// Test: Imprimir la tabla hash
TEST(HashSetTest, PrintTable) {
    HashSet<int> intSet;
    intSet.insert(10);
    intSet.insert(20);
    intSet.insert(30);

    testing::internal::CaptureStdout();
    intSet.printTable();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty()); // Verifica que se haya impreso algo

    HashSet<std::string> stringSet;
    stringSet.insert("apple");
    stringSet.insert("banana");
    stringSet.insert("cherry");

    testing::internal::CaptureStdout();
    stringSet.printTable();
    output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty()); // Verifica que se haya impreso algo
}

