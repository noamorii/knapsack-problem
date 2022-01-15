cmake_minimum_required(VERSION 3.20)
project(KnapsackProblem)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-release-1.11.0)
add_subdirectory(lib/jsoncpp-1.9.5)
include_directories(lib/googletest-release-1.11.0/googletest/include)
include_directories(lib/googletest-release-1.11.0/googlemock/include)
include_directories(lib/jsoncpp-1.9.5/include)

set(SOURCE_FILES main.cpp Tests/testClass.cpp Knapsack.h Knapsack.cpp)
add_executable(KnapsackProblem ${SOURCE_FILES} Tests/testClass.cpp)
target_link_libraries(KnapsackProblem gtest gtest_main)
target_link_libraries(KnapsackProblem jsoncpp_lib)