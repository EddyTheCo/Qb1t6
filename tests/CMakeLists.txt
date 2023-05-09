cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(testing VERSION 0.1 DESCRIPTION "diferent tests for the library" LANGUAGES CXX)

add_executable(tip5 tip5.cpp)
target_link_libraries(tip5 PRIVATE qb1t6)
add_test(NAME tip5 COMMAND tip5)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
        TARGET  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:tip5> $<TARGET_FILE_DIR:tip5>
        COMMAND_EXPAND_LISTS
    )
endif ()
