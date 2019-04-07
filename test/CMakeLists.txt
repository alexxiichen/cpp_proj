CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(Leetcode VERSION 0.1.0)

INCLUDE(CTest)
ENABLE_TESTING()

ADD_EXECUTABLE(leveldb_test leveldb_test.cc)
target_link_libraries(leveldb_test leveldb)

ADD_EXECUTABLE(rsa-encrypt_test rsa-encrypt_test.cc)
target_link_libraries(rsa-encrypt_test crypto)

ADD_EXECUTABLE(prime_test prime_test.cc)
target_link_libraries(prime_test profiler)
