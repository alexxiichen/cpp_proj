cmake_minimum_required(VERSION 3.0.0)
project(cpp_proj VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(./)
link_directories(./)

add_subdirectory(comm)
# add_subdirectory(test)

enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})