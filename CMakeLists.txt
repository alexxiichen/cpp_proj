cmake_minimum_required(VERSION 3.0.0)
project(cpp_proj VERSION 0.1.0)

# enable_testing()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include_directories(
    .
    3rd/googletest/googlemock/include
    3rd/googletest/googletest/include
    3rd/grpc/include
    3rd/leveldb/include
    3rd/libco
    3rd/rocksdb/include
    3rd/snappy
    3rd/openssl/include
)

link_directories(
    3rd/googletest/build_dir/lib
    3rd/grpc/build_dir
    3rd/leveldb/build_dir
    3rd/libco/build_dir
    3rd/protobuf/cmake/build
    3rd/rocksdb/build_dir
    3rd/snappy/cmake
    3rd/openssl
    3rd/gperftools/.libs
)


add_subdirectory(test)
add_subdirectory(algorithm)
add_subdirectory(comm)