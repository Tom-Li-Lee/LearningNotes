/*
 * main.cpp
 *
 *  Created on: 2011-5-4
 *      Author: tli
 */

#include <fstream>
using namespace std;

class FileArray;
class Index
{
friend class FileArray;
	FileArray* fa;
	streampos filePtr;
	Index(FileArray *, int x);
public:
	Index& operator = (char c);
	operator char();
};

Index::Index(FileArray* fa_ptr, int x)
{
	fa = fa_ptr;
	filePtr = (streampos)x;
}
class FileArray
{
friend class Index;
	fstream fs;
public:
	FileArray(const char* ptr):
		fs(ptr, ios::in | ios::out) {}
	Index operator[] (unsigned x);
};

Index& Index::operator =(char c)
{
	fa->fs.seekp(filePtr, ios::beg);
	fa->fs.write(&c,1);
	fa->fs.flush();
	return *this;
}

Index::operator char()
{
	char buf;
	fa->fs.seekg(filePtr, ios::beg);
	fa->fs.read(&buf, 1);
	return buf;
}



Index FileArray::operator[] (unsigned x)
{
	return Index(this, x);
}

char translate[10] = {'a','b', 'c', 'd', 'e', 'f', 'g','h','i','j'};
int main()
{
	FileArray source("input"), des("output");
	source[0] = 0;
	source[1] = 1;
	source[2] = 2;
	des[0] = source[2];
	return 0;
}
