cmake_minimum_required(VERSION 3.26)
project(ElaboratoJin)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Activity.cpp
        Activity.h
        Todolist.cpp
        Todolist.h)

add_executable(ElaboratoJin main.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)