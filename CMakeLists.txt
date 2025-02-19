cmake_minimum_required(VERSION 3.10)
project(AED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Add include directories
include_directories(include)

# Add source files for each test
add_executable(test_DLinkedList Lista/test_DLinkedList.cpp
        Lista/DLinkedList.h)
add_executable(test_ForwardList Lista/test_forward_list.cpp
        Lista/forward_list.h)
add_executable(test_CircularDLL Lista/test_CircularDLL.cpp
        Lista/CircularDLL.h)
add_executable(test_BinarySearchTree Arboles/BinarySearchTree.h
        Arboles/test_BynarySearchTree.cpp)
add_executable(test_HashTable_Set Tablas_hash/hashTable_Set.h
        Tablas_hash/test_HashTable_Set.cpp)
add_executable(test_HashTable_Map Tablas_hash/hashTable_Map.h
        Tablas_hash/test_HashTable_Map.cpp)
add_executable(test_SkipList Lista/SkipList.h
        Lista/test_SkipList.cpp)
add_executable(test_MatrizDispersa MatrizDispersa/test_MatrizDispersa.cpp
        MatrizDispersa/MatrizDispersa.h)


# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test and pthread
target_link_libraries(test_DLinkedList GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_ForwardList GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_CircularDLL GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_HashTable_Set GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_BinarySearchTree GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_HashTable_Map GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_SkipList GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_MatrizDispersa GTest::gtest GTest::gtest_main pthread)

# Include GoogleTest
include(GoogleTest)
gtest_discover_tests(test_DLinkedList)
gtest_discover_tests(test_ForwardList)
gtest_discover_tests(test_CircularDLL)
gtest_discover_tests(test_HashTable_Set)
gtest_discover_tests(test_BinarySearchTree)
gtest_discover_tests(test_HashTable_Map)
gtest_discover_tests(test_SkipList)
gtest_discover_tests(test_MatrizDispersa)
