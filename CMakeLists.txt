cmake_minimum_required(VERSION 3.0.0)
project(cpp_proj VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(~/include)
link_directories(~/lib)

add_subdirectory(Leetcode)
add_subdirectory(Test)

enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})