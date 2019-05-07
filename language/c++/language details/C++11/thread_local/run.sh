g++ -std=c++11 -g3 dllexport.cc -fPIC -shared -o libdllexport.so
g++ -std=c++11 -g3 test.cc -ldl -pthread -o p
export LD_LIBRARY_PATH=${PWD}
./p
