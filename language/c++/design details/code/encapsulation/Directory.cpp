/*
 * main.cpp
 *
 *  Created on: 2011-5-5
 *      Author: tli
 */
#include <stdio.h>
#include <dirent.h>
#include <string.h>

class Directory
{
	DIR *dir;
public:
	Directory(const char*);
	~Directory();
	 char * name(char* ptr);
	long tell();
	void seek(long);
};
Directory::Directory(const char *path)
{
	dir = opendir(path);

}

Directory::~Directory()
{
	if(dir)
		closedir(dir);
}

 char*  Directory::name(char *ptr)
{
	dirent *d = readdir(dir);
	if(!d)
		return NULL;
	strcpy(ptr, d->d_name);
	return ptr;
}

long Directory::tell()
{
	return telldir(dir);
}

void Directory::seek(long loc)
{
	seekdir(dir, loc);
}
int main()
{
	Directory a("Debug");
	char name[3][sizeof(dirent::d_name)];
	printf("%s, %s, %s\n",a.name(name[0]), a.name(name[1]), a.name(name[2]));
	return 0;
}
