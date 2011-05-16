#pragma once
#include "ZUC.h"
#include "String.h"
#include "math.h"
class CStreamCipherProvider
{
public:
	unsigned char key[80];
	bool isNew;
	CZUC myZUC;
	CStreamCipherProvider(void);
	~CStreamCipherProvider(void);
	bool Init(char* key);
	bool Encrypt(char * data,int datalen,char *result);
	bool Decrypt(char *data ,int datalen,char *result);
	bool EncryptNext(char * data,int datalen,char *result);
	bool DecryptNext(char *data ,int datalen,char *result);
};
