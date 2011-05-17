// EncryptDecrypt_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#define SIZE 200000
//char cipher1[50],cipher2[50],cipher3[50];
//char replaintext1[50],replaintext2[50],replaintext3[50];
int main(int argc, _TCHAR* argv[])
{

	u8 SBox[256];
	FILE *f = fopen("result.txt","wt");
	if (buildSbox("input.txt",SBox))
	{
		fprintf(f,"%d", test(SBox));
	}
	else
	{
		fprintf(f, "Wrong Input");
	}
	fclose(f);
	return 0;
}

