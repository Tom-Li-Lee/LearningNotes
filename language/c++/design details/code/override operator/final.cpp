/*
 * main.cpp
 *
 *  Created on: 2011-5-4
 *      Author: tli
 */

#include <fstream>
#include <iostream>
using namespace std;

char read_char(const fstream* fs, streampos index);

class FileArray;
class Index
{
friend class FileArray;

	FileArray* fa;
	streampos filePtr;
	Index(FileArray *, int x);
public:
	Index& operator = (char c);
	operator char()const;
	Index& operator = (const Index&);
};
Index& Index::operator =(const Index& index)
{
	if(this != &index) {
		char buf = index;
		this->operator =(buf);
	}
	return *this;
}

Index::Index(FileArray* fa_ptr, int x)
{
	fa = fa_ptr;
	filePtr = (streampos)x;
}

class const_Index
{
friend class FileArray;
	const FileArray* fa;
	streampos filePtr;
	const_Index(const FileArray *, int x);
	const_Index& operator = (char c);
	const_Index& operator = (const const_Index&);
public:
	operator char()const;
};

const_Index::const_Index(const FileArray* fa_ptr, int x)
{
	fa = fa_ptr;
	filePtr = (streampos)x;
}


char read_char(const fstream* fs, streampos index)
{
	char buf;
	fstream * ptr = const_cast<fstream*>(fs);
	ptr ->seekg(index, ios::beg);
	ptr ->read(&buf, 1);
	return buf;
}
class FileArray
{
friend class Index;
friend class const_Index;
	fstream fs;
	FileArray(const FileArray&);
	FileArray& operator = (const FileArray&);
public:
	FileArray(const char* ptr):
		fs(ptr, ios::in | ios::out) {}
   Index operator[] (unsigned x);
   const_Index operator[] (unsigned x)const;
};

Index& Index::operator =(char c)
{
	fa->fs.seekp(filePtr, ios::beg);
	fa->fs.write(&c,1);
	fa->fs.flush();
	return *this;
}

Index::operator char()const
{
	return read_char(&(fa->fs), filePtr);

}

const_Index::operator char()const
{
	return read_char(&(fa->fs), filePtr);
}

Index FileArray::operator[] (unsigned x)
{
	 return  Index(this, x);
}

char translate[10] = {'a','b', 'c', 'd', 'e', 'f', 'g','h','i','j'};
int main()
{
	FileArray source("input"), des("output");
	source[0] = 0;
	source[1] = 1;
	source[2] = 2;
	des[0]=des[0]=source[2];
	return 0;
}
