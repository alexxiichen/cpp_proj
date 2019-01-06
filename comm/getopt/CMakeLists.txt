CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(getopt VERSION 0.1.0)

add_library(getopt getopt.cc)

add_subdirectory(test)