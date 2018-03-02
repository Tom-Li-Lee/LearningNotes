/*
 * main.cpp
 *
 *  Created on: 2011-5-3
 *      Author: tli
 */
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
int main()
{
    std::fstream fs;
    fs.open("d:\\trigger",std::ios::out | std::ios::in);
    int in = 123;
  //  fs << in;
    fs.write((char*)(&in), sizeof(int));
    fs.seekg(std::ios::beg);
    int out;
   // fs >> out;
    fs.read((char*)(&out), sizeof(int));
    cout << out;
    fs.close();
}
