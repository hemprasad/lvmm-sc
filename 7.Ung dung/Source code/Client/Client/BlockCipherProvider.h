#pragma once
#include "rijndael.h"
#include "string.h"
class CBlockCipherProvider
{
public:
	unsigned char key[128];
	bool Init(char* key);
	bool isBegin;
	char* Encrypt(char * data,int &size );
	char* Decrypt(char *data,int size  );
	bool CTRModeEncrypt(char *data,int datalen,char *output );
	bool CTRModeDecrypt(char *data,int cipherlen,char *output  );
	CBlockCipherProvider(void);
	~CBlockCipherProvider(void);
	double Nonce,iTemp;
	bool CBlockCipherProvider::CTRModeEncryptNext(char *data,int datalen,char *output );
	bool CBlockCipherProvider::CTRModeDecryptNext(char *data,int cipherlen,char *output  );
};
