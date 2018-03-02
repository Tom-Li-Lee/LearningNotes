/*
 * main.cpp
 *
 *  Created on: 2011-5-4
 *      Author: tli
 */

#include <fstream>
using namespace std;

class point
{
	int _x, _y;
public:
	int getX() {return _x;}
	int getY() {return _y;}
};

class FileArray :public fstream
{
	streampos filePtr;
public:
	FileArray(const char* ptr):
		fstream(ptr, ios::in | ios::out) {}
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
	seekp(filePtr, ios::beg);
	write(&c, 1);
	flush();
	return *this;
}

FileArray::operator char()
{
	char buf;
	seekg(filePtr, ios::beg);
	read(&buf, 1);
	return buf;
}
char translate[10] = {'a','b', 'c', 'd', 'e', 'f', 'g','h','i','j'};
int main()
{
	FileArray source("input"), des("output");
	int i = 1;
	source.write((char*)(&i), sizeof(int));
	des[0] = translate[1 << source[0]];
	return 0;
}
