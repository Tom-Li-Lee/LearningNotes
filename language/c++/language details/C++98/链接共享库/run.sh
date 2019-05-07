g++ -std=c++11 -g3 test.cc -fPIC -shared -o libdllexport.so
g++ -std=c++11 -g3 main.cc -L. -ldllexport -o p
export LD_LIBRARY_PATH=${PWD}
./p
