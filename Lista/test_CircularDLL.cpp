#include "CircularDLL.h"
#include <gtest/gtest.h>

TEST(CircularDLLTest, PushFrontTest) {
    List<int> list;
    list.push_front(1);
    list.push_front(0);
    EXPECT_EQ(list.front(), 0);
    EXPECT_EQ(list.size(), 2);
}

TEST(CircularDLLTest, PushBackTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.back(), 2);
    EXPECT_EQ(list.size(), 2);
}

TEST(CircularDLLTest, PopFrontTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 2);
}

TEST(CircularDLLTest, PopBackTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.back(), 1);
}

TEST(CircularDLLTest, InsertTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.insertAt(2, 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list.size(), 3);
}

TEST(CircularDLLTest, RemoveTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.remove(1);
    EXPECT_EQ(list[1], 3);
    EXPECT_EQ(list.size(), 2);
}

TEST(CircularDLLTest, OperatorTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

TEST(CircularDLLTest, EmptyTest) {
    List<int> list;
    EXPECT_TRUE(list.empty());
    list.push_back(1);
    EXPECT_FALSE(list.empty());
}

TEST(CircularDLLTest, SizeTest) {
    List<int> list;
    EXPECT_EQ(list.size(), 0);
    list.push_back(1);
    EXPECT_EQ(list.size(), 1);
}

TEST(CircularDLLTest, ClearTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST(CircularDLLTest, ReverseTest) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.reverse();
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}