cmake_minimum_required(VERSION 3.10)
project(AED)

set(CMAKE_CXX_STANDARD 11)

# Añade tus archivos fuente aquí
add_executable(runTests lista/test_forward_list.cpp)

# Linkea Google Test
find_package(GTest REQUIRED)
target_link_libraries(runTests GTest::GTest GTest::Main)
