cmake_minimum_required(VERSION 3.10)
project(AED)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_executable(runTests Lista/test_forward_list.cpp)

find_package(GTest REQUIRED)
include(GoogleTest)
gtest_discover_tests(runTests)
