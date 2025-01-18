//
// Created by brano on 17/01/2025.
//
//
// Created by brano on 17/01/2025.
//
#include "CircularDLL.h"
#include <gtest/gtest.h>

TEST(CircularDLLTest, PushFrontBackTest) {
    List<int> list;  // Cambio de CircularDLL<int> a List<int>
    list.push_front(1);
    list.push_back(2);
    list.push_front(0);
    list.push_back(3);

    EXPECT_EQ(list.front(), 0);
    EXPECT_EQ(list.back(), 3);
    EXPECT_EQ(list.size(), 4);
}

TEST(CircularDLLTest, PopFrontBackTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.pop_back(), 5);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.front(), 2);
    EXPECT_EQ(list.back(), 4);
}

TEST(CircularDLLTest, InsertRemoveTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.insertAt(2, 1); // Cambio de insert() a insertAt()
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list.size(), 3);

    list.remove(1); // Remove element at position 1
    EXPECT_EQ(list[1], 3);
    EXPECT_EQ(list.size(), 2);
}

TEST(CircularDLLTest, OperatorTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 4);
    EXPECT_EQ(list[4], 5);
}

TEST(CircularDLLTest, EmptySizeClearTest) {
    List<int> list;
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);

    list.push_back(1);
    list.push_back(2);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 2);

    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(CircularDLLTest, ReverseTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.reverse();

    // En lugar de usar índices, recorreremos la lista para validar el orden
    EXPECT_EQ(list.front(), 5);
    EXPECT_EQ(list.back(), 1);

    list.pop_front(); EXPECT_EQ(list.front(), 4);
    list.pop_front(); EXPECT_EQ(list.front(), 3);
    list.pop_front(); EXPECT_EQ(list.front(), 2);
    list.pop_front(); EXPECT_EQ(list.front(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
