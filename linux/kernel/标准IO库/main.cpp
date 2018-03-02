#include <stdio.h>

int main()
{
	FILE* ftr = fopen("tmp.txt","r+");
	fgetc(ftr);
	fgetc(ftr);
	long i = ftell(ftr);
	long k = fseek(ftr, 6, SEEK_SET);
	long j = ftell(ftr);
	fputs("KKKK", ftr);
	fclose(ftr);
}
