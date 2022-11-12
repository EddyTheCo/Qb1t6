cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)


add_executable(tip5 tip5.cpp)
add_test(NAME tip5 COMMAND tip5)
target_link_libraries(tip5 PRIVATE qb1t6)
