cmake_minimum_required(VERSION 3.0.0)
project(cpp_proj VERSION 0.1.0)

# enable_testing()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include_directories(.)
include_directories(3rd/googletest/googlemock/include)
include_directories(3rd/googletest/googletest/include)
include_directories(3rd/grpc/include)
include_directories(3rd/leveldb/include)
include_directories(3rd/libco)
include_directories(3rd/rocksdb/include)
include_directories(3rd/snappy)
include_directories(3rd/openssl/include)

link_directories(3rd/googletest/build_dir/lib)
link_directories(3rd/grpc/build_dir)
link_directories(3rd/leveldb/build_dir)
link_directories(3rd/libco/build_dir)
link_directories(3rd/protobuf/cmake/build)
link_directories(3rd/rocksdb/build_dir)
link_directories(3rd/snappy/cmake)
link_directories(3rd/openssl)


add_subdirectory(test)
add_subdirectory(algorithm)
add_subdirectory(comm)