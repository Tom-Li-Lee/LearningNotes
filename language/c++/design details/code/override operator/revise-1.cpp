/*
 * main.cpp
 *
 *  Created on: 2011-5-4
 *      Author: tli
 */

#include <fstream>
using namespace std;



class FileArray
{
	streampos filePtr;
	fstream fs;
public:
	FileArray(const char* ptr):
		fs(ptr, ios::in | ios::out) {}
	FileArray& operator[] (unsigned x);
	FileArray& operator = (char c);
	operator char();
};

FileArray& FileArray::operator[] (unsigned x)
{
	this->filePtr = (streampos)(x);
	return *this;
}

FileArray& FileArray::operator = (char c)
{
	fs.seekp(filePtr, ios::beg);
	fs.write(&c, 1);
	fs.flush();
	return *this;
}

FileArray::operator char()
{
	char buf;
	fs.seekg(filePtr, ios::beg);
	fs.read(&buf, 1);
	return buf;
}
char translate[10] = {'a','b', 'c', 'd', 'e', 'f', 'g','h','i','j'};
int main()
{
	FileArray source("input"), des("output");
	int i = 1;
	source.write((char*)(&i), sizeof(int));
	des[0] = source[2];
	return 0;
}
