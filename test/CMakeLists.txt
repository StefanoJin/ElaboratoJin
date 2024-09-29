cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD 11)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES test_activity.cpp test_todolist.cpp runAllTest.cpp
        test_todoInterface.cpp)
add_executable(runElaboratoTests ${TEST_SOURCE_FILES})
target_link_libraries(runElaboratoTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)