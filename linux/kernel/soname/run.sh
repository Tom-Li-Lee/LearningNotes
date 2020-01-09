set -e

g++ -std=c++11 -g3 -fPIC -shared  -Wl,-soname,libsum.so.1 -o libsum.so.1.1 sum.cc 
g++ -std=c++11 -g3 test.cc -L. libsum.so.1.1 -o p
ln -sf libsum.so.1.1  libsum.so.1
export LD_LIBRARY_PATH=${PWD}
./p
# p依赖的so是soname，即libsum.so.1

