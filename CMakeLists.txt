cmake_minimum_required(VERSION 3.6)
project(Stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Stack.TestDriver.cpp Stack.h MyRPNCalculator.cpp)
add_executable(Stack ${SOURCE_FILES})