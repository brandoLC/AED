cmake_minimum_required(VERSION 3.10)
project(AED)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

# Añade tus archivos fuente aquí
add_executable(runTests Lista/test_forward_list.cpp)

# Linkea Google Test
find_package(GTest REQUIRED)
include(GoogleTest)
gtest_discover_tests(runTests)
