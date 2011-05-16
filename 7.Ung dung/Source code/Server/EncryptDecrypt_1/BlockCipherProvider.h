#pragma once
#include "rijndael.h"
#include "string.h"
class CBlockCipherProvider
{
public:
	unsigned char key[128];
	bool Init(char* key);
	char* Encrypt(char * data,int &size );
	char* Decrypt(char *data,int size  );
	char* CTRModeEncrypt(char * data,int &size );;
	char* CTRModeDecrypt(char *data,int size  );
	CBlockCipherProvider(void);
	~CBlockCipherProvider(void);
	unsigned int Nonce,iTemp;
	char* CBlockCipherProvider::CTRModeEncryptNext(char * data,int &size);
	char* CBlockCipherProvider::CTRModeDecryptNext(char *cipher,int size );
};
