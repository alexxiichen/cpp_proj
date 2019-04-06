# /bin/bash
cd googletest
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../..

cd grpc
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../..

cd leveldb
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../..

cd libco
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../..

cd protobuf/cmake
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../../..

cd snappy
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../..

cd rocksdb
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd ../..
