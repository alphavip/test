cmake_minimum_required(VERSION 2.8)

project(test)

set(FILES pathfinder.cpp)

message(STATUS ${FILES})

set(CMAKE_CXX_FLAGS "$ENV{CMAKE_CXX_FLAGS} -std=c++11 -g -ggdb")

add_executable(test ${FILES})

install(TARGETS test RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/output/)