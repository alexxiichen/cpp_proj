# /bin/bash
workdir=$(cd $(dirname $0); pwd)

cd googletest
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd $workdir

cd grpc
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd $workdir

cd leveldb
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd $workdir

cd libco
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd $workdir

cd protobuf/cmake
mkdir build_dir
cd build_dir
cmake ..
make -j 24
make check
make install
cd $workdir

cd snappy
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd $workdir

cd rocksdb
mkdir build_dir
cd build_dir
cmake ..
make -j 24
cd $workdir

cd openssl
./Configure
./config
make -j 24
make check
make install
cd $workdir

cd gperftools
./configure
make -j 24
make check
make install
cd $workdir

