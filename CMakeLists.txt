project(hackertyper)
cmake_minimum_required(VERSION 3.30)


set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES src/*.cpp)

add_executable(hackertyper ${SOURCES})
target_include_directories(hackertyper PRIVATE include)
