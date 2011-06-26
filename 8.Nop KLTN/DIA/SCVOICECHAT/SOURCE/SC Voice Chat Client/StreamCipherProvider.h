#pragma once
#include "ZUC.h"
#include "String.h"
#include "math.h"
#include "ctime"
#include "dos.h"
#define Buffer_Max   10000000
#define Max_Counter  15000000
class CZUCBuffer
{
public:
	u32 *data;
	int iFlag;
};
class CStreamCipherProvider
{
public:
	
	unsigned char key[128];
	//u32 buffer[(Buffer_Max/4)];
	int iFlag,iUsingCounter;
	CZUCBuffer *buffer1,*buffer2,*bufferIndex;
	int iCount;
	bool isNew;
	CZUC myZUC;
	CStreamCipherProvider(void);
	~CStreamCipherProvider(void);
	bool Init(char* key);
	bool Encrypt(char * data,int datalen,char *result);
	bool Decrypt(char *data ,int datalen,char *result);
	bool CMInit(char* key); //Circle Mode Init
	bool CMEncrypt(char * data,int datalen,char *result);//Circle Mode Encrypt
	bool CMDecrypt(char *data ,int datalen,char *result);//Circle Mode Decrypt
	bool EncryptNext(char * data,int datalen,char *result);
	bool DecryptNext(char *data ,int datalen,char *result);
	
};
