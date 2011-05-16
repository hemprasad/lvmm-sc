#include "stdafx.h"
#include "BlockCipherProvider.h"
#include "iostream"
using namespace std;
CBlockCipherProvider::CBlockCipherProvider(void)
{
}

CBlockCipherProvider::~CBlockCipherProvider(void)
{
}
bool CBlockCipherProvider::Init(char* userkey)
{
	int len= strlen(userkey);
	for (int i=0;i<128;i++)
	{
		key[i] = (unsigned char)(userkey[i]);
	}
	Nonce=99999,iTemp=0;
	return	true;
}
char* CBlockCipherProvider::Encrypt(char * data,int &size)
{
	//0 khoi tao va khai bao
	unsigned char datArray[16],cipArray[16];
	unsigned long ck [100];
	unsigned long ulTemp;
	int nROund=rijndaelSetupEncrypt(ck,key,128);
	int datLen = strlen(data);
	int cipLen ;
	datLen%16==0?cipLen=datLen/16:cipLen=datLen/16+1;
	size = cipLen*16;
	char* Cipher= new char[size];
	//1 tach du lieu 
	for (int i=0;i<datLen;i=i+16)
	{
		for (int j=0;j<16;j++)
		{
			if (i+j < datLen)
				datArray[j]=(unsigned char)data[i+j];
			else
				datArray[j]=0;
		}
	//2 ma hoa
		
		rijndaelEncrypt(ck,nROund,datArray,cipArray);
		//rijndaelDecrypt(ck,nROund,cipArray,datArray);
	//3 gom file ket qua
		for (j=0;j<16;j++)
		{
			//Cipher[i+j]=(char)datArray[j];
			Cipher[i+j]=(char)cipArray[j];
		}
	}
	return	Cipher;
}
char* CBlockCipherProvider::Decrypt(char *cipher,int size )
{
	//0 khoi tao va khai bao
	unsigned char cipherArray[16],dataArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupDecrypt(ck,key,128);
	int cipherLen = size;
	int dataLen ;
	cipherLen%16==0?dataLen=cipherLen/16:dataLen=cipherLen/16+1;
	char* Data= new char[dataLen];
	//1 tach du lieu 
	int j;
	for (int i=0;i<cipherLen;i=i+16)
	{
		for (j=0;j<16;j++)
		{
			if (i+j < cipherLen)
				cipherArray[j]=(unsigned char)cipher[i+j];
			else
				cipherArray[j]=0;
		}
	//2 ma hoa
		rijndaelDecrypt(ck,nROund,cipherArray,dataArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			Data[i+j]=(char)dataArray[j];
		}
	}
	return	Data;
}
char* CBlockCipherProvider::CTRModeEncrypt(char * data,int &size)
{
	//0 khoi tao va khai bao
	unsigned char datArray[16],cipArray[16],ivArray[16];
	unsigned long ck [100];
	Nonce=99999,iTemp=0;
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	int nROund=rijndaelSetupEncrypt(ck,key,128);
	int datLen = strlen(data);
	int cipLen ;
	datLen%16==0?cipLen=datLen/16:cipLen=datLen/16+1;
	size = cipLen*16;
	char* Cipher= new char[size];int j;
	//1 tach du lieu 
	for (int i=0;i<datLen;i=i+16)
	{
		iTemp++;
		for (j=0;j<16;j++)
		{
			if (i+j < datLen)
				datArray[j]=(unsigned char)data[i+j];
			else
				datArray[j]=0;
			if (j<8)
				ivArray[j] = buffN[j];
			else
				ivArray[j] = buffT[j-8];;
			//cout<<j + i  << " :1: " << (int)ivArray[j] << "\n" ;
		}

	//2 ma hoa
		
		rijndaelEncrypt(ck,nROund,ivArray,cipArray);
		//rijndaelDecrypt(ck,nROund,cipArray,datArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			//Cipher[i+j]=(char)datArray[j];
			//cout<<j + i  << " :2: " << (int)cipArray[j] << "\n" ;
			Cipher[i+j]=(cipArray[j] ^ datArray[j]);
		}
	}
	return	Cipher;
}
char* CBlockCipherProvider::CTRModeDecrypt(char *cipher,int size )
{
	//0 khoi tao va khai bao
	unsigned char cipherArray[16],dataArray[16],ivArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupEncrypt(ck,key,128);
	Nonce=99999,iTemp=0;
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	int cipherLen = size;
	int dataLen ;
	cipherLen%16==0?dataLen=cipherLen/16:dataLen=cipherLen/16+1;
	char* Data= new char[dataLen];int j;
	//1 tach du lieu 
	for (int i=0;i<cipherLen;i=i+16)
	{
		iTemp++;
		for (j=0;j<16;j++)
		{
			if (i+j < cipherLen)
				cipherArray[j]=(unsigned char)cipher[i+j];
			else
				cipherArray[j]=0;
			if (j<8)
				ivArray[j] = buffN[j];
			else
				ivArray[j] = buffT[j-8];
			//cout<<j + i  << " :3: " << (int)ivArray[j] << "\n" ;
		}
	//2 ma hoa

		rijndaelEncrypt(ck,nROund,ivArray,dataArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			//cout<<j + i  << " :4: " << (int)dataArray[j] << "\n" ;
			Data[i+j]=(cipherArray[j] ^ dataArray[j]);
		}
	}
	return	Data;
}
char* CBlockCipherProvider::CTRModeEncryptNext(char * data,int &size)
{
	//0 khoi tao va khai bao
	unsigned char datArray[16],cipArray[16],ivArray[16];
	unsigned long ck [100];
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	int nROund=rijndaelSetupEncrypt(ck,key,128);
	int datLen = strlen(data);
	int cipLen ;
	datLen%16==0?cipLen=datLen/16:cipLen=datLen/16+1;
	size = cipLen*16;
	char* Cipher= new char[size];int j;
	//1 tach du lieu 
	for (int i=0;i<datLen;i=i+16)
	{
		iTemp++;
		for (j=0;j<16;j++)
		{
			if (i+j < datLen)
				datArray[j]=(unsigned char)data[i+j];
			else
				datArray[j]=0;
			if (j<8)
				ivArray[j] = buffN[j];
			else
				ivArray[j] = buffT[j-8];;
			//cout<<j + i  << " :1: " << (int)ivArray[j] << "\n" ;
		}

	//2 ma hoa
		
		rijndaelEncrypt(ck,nROund,ivArray,cipArray);
		//rijndaelDecrypt(ck,nROund,cipArray,datArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			//Cipher[i+j]=(char)datArray[j];
			//cout<<j + i  << " :2: " << (int)cipArray[j] << "\n" ;
			Cipher[i+j]=(cipArray[j] ^ datArray[j]);
		}
	}
	return	Cipher;
}
char* CBlockCipherProvider::CTRModeDecryptNext(char *cipher,int size )
{
	//0 khoi tao va khai bao
	unsigned char cipherArray[16],dataArray[16],ivArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupEncrypt(ck,key,128);
	
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	int cipherLen = size;
	int dataLen ;
	cipherLen%16==0?dataLen=cipherLen/16:dataLen=cipherLen/16+1;
	char* Data= new char[dataLen];int j;
	//1 tach du lieu 
	for (int i=0;i<cipherLen;i=i+16)
	{
		iTemp++;
		for (j=0;j<16;j++)
		{
			if (i+j < cipherLen)
				cipherArray[j]=(unsigned char)cipher[i+j];
			else
				cipherArray[j]=0;
			if (j<8)
				ivArray[j] = buffN[j];
			else
				ivArray[j] = buffT[j-8];
			//cout<<j + i  << " :3: " << (int)ivArray[j] << "\n" ;
		}
	//2 ma hoa

		rijndaelEncrypt(ck,nROund,ivArray,dataArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			//cout<<j + i  << " :4: " << (int)dataArray[j] << "\n" ;
			Data[i+j]=(cipherArray[j] ^ dataArray[j]);
		}
	}
	return	Data;
}