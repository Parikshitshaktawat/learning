# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(GTestExample)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests gtest.cpp ../Queue.cpp)
target_link_libraries(runTests GTest::GTest GTest::Main pthread)

add_executable(queue main.cpp Queue.cpp)

