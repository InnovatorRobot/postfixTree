cmake_minimum_required(VERSION 3.5)

project(postfixTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES main.cpp expressiontree.cpp)
set(HEADERS expressiontree.h)
add_executable(postfixTree ${SOURCES} ${HEADERS})
