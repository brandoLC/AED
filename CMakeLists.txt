cmake_minimum_required(VERSION 3.10)
project(AED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Add include directories
include_directories(include)

# Add source files for each test
add_executable(test_DLinkedList Lista/test_DLinkedList.cpp
        Lista/DLinkedList.h
        Lista/CircularDLL.h)
add_executable(test_ForwardList Lista/test_forward_list.cpp
        Lista/forward_list.h)
add_executable(test_CircularDLL Lista/test_CircularDLL.cpp
        Lista/CircularDLL.h)


# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test and pthread
target_link_libraries(test_DLinkedList GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_ForwardList GTest::gtest GTest::gtest_main pthread)
target_link_libraries(test_CircularDLL GTest::gtest GTest::gtest_main pthread)

# Include GoogleTest
include(GoogleTest)
gtest_discover_tests(test_DLinkedList)
gtest_discover_tests(test_ForwardList)
gtest_discover_tests(test_CircularDLL)