//
// Created by brando on 1/13/25.
//
#include "DLinkedList.h"
#include <gtest/gtest.h>


TEST(DLinkedListTest,InitializerTest) {
    DLinkedList<int> list= {1,2,3,4,5};
    EXPECT_EQ(list.size(),5);
    EXPECT_EQ(list.front(),1);
    EXPECT_EQ(list.back(),5);

    list.pop_front();
    EXPECT_EQ(list.front(),2);
}

TEST(DLinkedListTest, IteratorTest) {
    DLinkedList<int> list = {1, 2, 3, 4, 5};

    // Test forward iteration
    auto it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(it, list.end());

    // Test backward iteration
    it = list.end();
    --it;
    EXPECT_EQ(*it, 5);
    --it;
    EXPECT_EQ(*it, 4);
    --it;
    EXPECT_EQ(*it, 3);
    --it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 1);
    EXPECT_THROW(--it, std::out_of_range);

    // Test dereferencing end iterator
    it = list.end();
    EXPECT_THROW(*it, std::out_of_range);
}

TEST(DLinkedListTest, ReverseTest) {
    DLinkedList<int> list = {1, 2, 3, 4, 5};
    list.reverse();
    EXPECT_EQ(list.size(), 5);
    EXPECT_EQ(list[0], 5);
    EXPECT_EQ(list[1], 4);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 2);
    EXPECT_EQ(list[4], 1);

    // Check next pointers
    auto it = list.begin();
    EXPECT_EQ(*it, 5);
    ++it;
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);

    // Check prev pointers
    it = list.end();
    --it;
    EXPECT_EQ(*it, 1);
    --it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 3);
    --it;
    EXPECT_EQ(*it, 4);
    --it;
    EXPECT_EQ(*it, 5);

    list.reverse();
    EXPECT_EQ(list.size(), 5);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 4);
    EXPECT_EQ(list[4], 5);

    // Check next pointers again
    it = list.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 4);
    ++it;
    EXPECT_EQ(*it, 5);

    // Check prev pointers again
    it = list.end();
    --it;
    EXPECT_EQ(*it, 5);
    --it;
    EXPECT_EQ(*it, 4);
    --it;
    EXPECT_EQ(*it, 3);
    --it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 1);
}

TEST(DLinkedListTest,PushFrontTest) {
    DLinkedList<int> list;
    list.push_front(1);
    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list.front(),1);
    list.push_front(2);
    EXPECT_EQ(list.size(),2);
    EXPECT_EQ(list.front(),2);
}

TEST(DLinkedListTest,PushBackTest) {
    DLinkedList<int> list;
    list.push_back(1);
    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list.back(),1);
    list.push_back(2);
    EXPECT_EQ(list.size(),2);
    EXPECT_EQ(list.back(),2);
}

TEST(DLinkedListTest,PopFrontTest) {
    DLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list.front(),1);
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

TEST(DLinkedListTest,PopBackTest) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.pop_back();
    EXPECT_EQ(list.size(),1);
    EXPECT_EQ(list.back(),1);
    list.pop_back();
    EXPECT_TRUE(list.empty());
}

TEST(DLinkedListTest,OperatorBracketsNonConstTest) {
    DLinkedList<int> list = {1,2,3,4,5};
    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],3);
    EXPECT_EQ(list[3],4);
    EXPECT_EQ(list[4],5);

    list[2]=10;
    EXPECT_EQ(list[2],10);

    list.pop_back();
    EXPECT_THROW(list[4],std::out_of_range);
}

TEST(DLinkedListTest,OperatorBracketsConstTest) {
    const DLinkedList<int> list = {1,2,3,4,5};
    EXPECT_EQ(list[0],1);
    EXPECT_EQ(list[1],2);
    EXPECT_EQ(list[2],3);
    EXPECT_EQ(list[3],4);
    EXPECT_EQ(list[4],5);

    EXPECT_THROW(list[5],std::out_of_range);
}

TEST(DLinkedListTest,SizeTest) {
    DLinkedList<int> list = {1,2,3};
    EXPECT_EQ(list.size(),3);

    list.push_front(0);
    EXPECT_EQ(list.size(),4);

    list.pop_front();
    EXPECT_EQ(list.size(),3);

    list.clear();
    EXPECT_EQ(list.size(),0);
}

TEST(DLinkedListTest,EmptyTest) {
    DLinkedList<int> list;
    EXPECT_TRUE(list.empty());
    list.push_front(1);
    EXPECT_FALSE(list.empty());
}

TEST(DLinkedListTest,FrontTest) {
    DLinkedList<int> list;
    DLinkedList<int> listEmpty;
    EXPECT_THROW(listEmpty.front(),std::logic_error);
    list.push_front(1);
    EXPECT_EQ(list.front(),1);
    list.push_front(2);
    EXPECT_EQ(list.front(),2);
}




