CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(Leetcode VERSION 0.1.0)

INCLUDE(CTest)
ENABLE_TESTING()

ADD_EXECUTABLE(leveldb_test leveldb_test.cc)
target_link_libraries(leveldb_test leveldb)