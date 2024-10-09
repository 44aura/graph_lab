cmake_minimum_required(VERSION 3.8)
project(GraphVisualization LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

file(GLOB SOURCES
    header/*.h
    src/*.cpp)

add_executable(graph ${SOURCES})