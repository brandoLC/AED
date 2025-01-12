#include "forward_list.h"
#include <gtest/gtest.h>

// Prueba para el inicializador de lista
TEST(ForwardListTest, InitializerList) {
    ForwardList<int> list = {1, 2, 3, 4, 5};

    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 5);

    list.pop_front();
    EXPECT_EQ(list.front(), 2);
}

// Prueba para push_front
TEST(ForwardListTest, PushFront) {
    ForwardList<int> list;
    list.push_front(1);
    EXPECT_EQ(list.front(), 1);
    list.push_front(2);
    EXPECT_EQ(list.front(), 2);
}

// Prueba para push_back
TEST(ForwardListTest, PushBack) {
    ForwardList<int> list;
    list.push_back(1);
    EXPECT_EQ(list.front(), 1);
    list.push_back(2);
    EXPECT_EQ(list.back(), 2);
    list.pop_front();
    EXPECT_EQ(list.front(), 2);
}

// Prueba para pop_front
TEST(ForwardListTest, PopFront) {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    EXPECT_EQ(list.front(), 1);
    list.pop_front();
    EXPECT_TRUE(list.empty());
}

// Prueba para pop_back
TEST(ForwardListTest, PopBack) {
    ForwardList<int> list_empty;
    ForwardList<int> list = {1, 2, 3, 4, 5};

    EXPECT_THROW(list_empty.pop_back(), std::out_of_range);

    list.pop_back();
    EXPECT_EQ(list.back(), 4);
}

// Prueba para front
TEST(ForwardListTest, Front) {
    ForwardList<int> list;
    list.push_front(1);
    EXPECT_EQ(list.front(), 1);
    list.push_front(2);
    EXPECT_EQ(list.front(), 2);
}

// Prueba para back
TEST(ForwardListTest, Back) {
    ForwardList<int> list = {1, 3, 5, 2, 4};
    EXPECT_EQ(list.back(), 4);
    list.push_back(5);
    EXPECT_EQ(list.back(), 5);
}

// Prueba para empty
TEST(ForwardListTest, Empty) {
    ForwardList<int> list;
    EXPECT_TRUE(list.empty());
    list.push_front(1);
    EXPECT_FALSE(list.empty());
}

// Prueba para clear
TEST(ForwardListTest, Clear) {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.clear();
    EXPECT_TRUE(list.empty());
}

// Prueba para el operador []
TEST(ForwardListTest, OperatorBracketsNonConst) {
    ForwardList<int> list = {1, 2, 3, 4, 5};

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 4);
    EXPECT_EQ(list[4], 5);

    list[2] = 10;
    EXPECT_EQ(list[2], 10);

    list.pop_back();

    EXPECT_THROW(list[4], std::out_of_range);
}

// Prueba para el operador [] en objetos const
TEST(ForwardListTest, OperatorBracketsConst) {
    const ForwardList<int> constList = {1, 2, 3, 4, 5};

    EXPECT_EQ(constList[0], 1);
    EXPECT_EQ(constList[1], 2);
    EXPECT_EQ(constList[2], 3);
    EXPECT_EQ(constList[3], 4);
    EXPECT_EQ(constList[4], 5);

    EXPECT_THROW(constList[5], std::out_of_range);

}

// Prueba para size
TEST(ForwardListTest, Size) {
    ForwardList<int> list = {1, 2, 3};
    EXPECT_EQ(list.size(), 3);

    list.push_front(0);
    EXPECT_EQ(list.size(), 4);

    list.pop_front();
    EXPECT_EQ(list.size(), 3);

    list.clear();
    EXPECT_EQ(list.size(), 0);

    // Prueba con un objeto constante
    const ForwardList<int> const_list = {4, 5, 6};
    EXPECT_EQ(const_list.size(), 3);
}

// Prueba para reverse
TEST(ForwardListTest, Reverse) {
    ForwardList<int> list = {1, 2, 3, 4, 5};
    list.reverse();
    EXPECT_EQ(list[0], 5);
    EXPECT_EQ(list[1], 4);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 2);
    EXPECT_EQ(list[4], 1);
}

// Prueba para insertionSort
TEST(ForwardListTest, InsertionSort) {
    ForwardList<int> list = {5, 2, 4, 3, 1};
    list.insertionSort();
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
    EXPECT_EQ(list[3], 4);
    EXPECT_EQ(list[4], 5);
}

// Prueba para mergeWith
TEST(ForwardListTest, MergeWith) {
    ForwardList<int> list1 = {1, 3, 5};
    ForwardList<int> list2 = {2, 4, 6};
    ForwardList<int> mergedList = list1.mergeWith(list2);
    EXPECT_EQ(mergedList[0], 1);
    EXPECT_EQ(mergedList[1], 2);
    EXPECT_EQ(mergedList[2], 3);
    EXPECT_EQ(mergedList[3], 4);
    EXPECT_EQ(mergedList[4], 5);
    EXPECT_EQ(mergedList[5], 6);
}

// Prueba para intersectionWith
TEST(ForwardListTest, IntersectionWith) {
    ForwardList<int> list1 = {1, 2, 3, 4, 5};
    ForwardList<int> list2 = {3, 4, 5, 6, 7};
    ForwardList<int> intersectionList = list1.intersectionWith(list2);
    EXPECT_EQ(intersectionList[0], 3);
    EXPECT_EQ(intersectionList[1], 4);
    EXPECT_EQ(intersectionList[2], 5);
}

// Prueba para isPalindromo
TEST(ForwardListTest, IsPalindromo) {
    ForwardList<int> list1 = {1, 2, 3, 2, 1};
    EXPECT_TRUE(list1.isPalindromo());
    EXPECT_EQ(list1[0], 1);
    EXPECT_EQ(list1[1], 2);
    EXPECT_EQ(list1[2], 3);
    EXPECT_EQ(list1[3], 2);
    EXPECT_EQ(list1[4], 1);

    ForwardList<int> list2 = {1, 2, 2, 1};
    EXPECT_TRUE(list2.isPalindromo());
    EXPECT_EQ(list2[0], 1);
    EXPECT_EQ(list2[1], 2);
    EXPECT_EQ(list2[2], 2);
    EXPECT_EQ(list2[3], 1);

    ForwardList<int> list3 = {1, 2, 3};
    EXPECT_FALSE(list3.isPalindromo());
    EXPECT_EQ(list3[0], 1);
    EXPECT_EQ(list3[1], 2);
    EXPECT_EQ(list3[2], 3);

    ForwardList<int> list4;
    EXPECT_TRUE(list4.isPalindromo());

    ForwardList<int> list5 = {1};
    EXPECT_TRUE(list5.isPalindromo());
    EXPECT_EQ(list5[0], 1);
}

// Función main para ejecutar todas las pruebas
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}