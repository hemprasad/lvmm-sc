#pragma once
#include "rijndael.h"
#include "string.h"
class CBlockCipherProvider
{
public:
	unsigned char key[128];char *mykey;
	bool Init(char* key);
	bool isBegin;int iCount;
	bool Encrypt(char * data,int size,char *output );
	bool Decrypt(char *data,int size ,char *output );
	bool CBCEncrypt(char * data,int size,char *output );
	bool CBCDecrypt(char *data,int size ,char *output );
	bool CTRModeEncrypt(char *data,int datalen,char *output );
	bool CTRModeDecrypt(char *data,int cipherlen,char *output  );
	CBlockCipherProvider(void);
	~CBlockCipherProvider(void);
	double Nonce,iTemp;
	bool CBlockCipherProvider::CTRModeEncryptNext(char *data,int datalen,char *output );
	bool CBlockCipherProvider::CTRModeDecryptNext(char *data,int cipherlen,char *output  );
	bool hashkey(unsigned char *hashedkey,char *key,int iCounter );
};
