cmake_minimum_required(VERSION 3.30)
project(hackertyper)


set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES src/*.cpp)

add_executable(hackertyper ${SOURCES})
target_include_directories(hackertyper PRIVATE include)

install(TARGETS hackertyper RUNTIME DESTINATION bin LIBRARY DESTINATION lib)
