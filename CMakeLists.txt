cmake_minimum_required(VERSION 3.10)
project(AED)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Añade los directorios de inclusión
include_directories(include)

# Añade los archivos fuente
add_executable(runTests Lista/test_forward_list.cpp)

# Encuentra Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Vincula Google Test y pthread
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

include(GoogleTest)
gtest_discover_tests(runTests)