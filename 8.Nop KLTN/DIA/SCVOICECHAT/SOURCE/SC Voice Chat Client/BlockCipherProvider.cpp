#include "stdafx.h"
#include "BlockCipherProvider.h"
#include "iostream"
#include "stdlib.h"
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
	isBegin=true;
	return	true;
}
bool CBlockCipherProvider::Encrypt(char * data,int datLen,char *Cipher)
{
	//0 khoi tao va khai bao
	unsigned char datArray[16],cipArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupEncrypt(ck,key,128);
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
	return	true;
}
bool CBlockCipherProvider::Decrypt(char *cipher,int size,char *Data )
{
	//0 khoi tao va khai bao
	unsigned char cipherArray[16],dataArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupDecrypt(ck,key,128);
	int cipherLen = size;
	int dataLen ;
	cipherLen%16==0?dataLen=cipherLen/16:dataLen=cipherLen/16+1;
	//1 tach du lieu 
	int j;
	for (int i=0;i<cipherLen;i=i+16)
	{
		for (j=0;j<16;j++)
		{
				cipherArray[j]=(unsigned char)cipher[i+j];			
		}
	//2 ma hoa
		rijndaelDecrypt(ck,nROund,cipherArray,dataArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			Data[i+j]=(char)dataArray[j];
		}
	}
	return	true;
}
bool CBlockCipherProvider::CTRModeEncrypt(char *data,int datLen,char *Cipher )
{
	//0 khoi tao va khai bao
	unsigned char datArray[16],cipArray[16],ivArray[16];
	unsigned long ck [100];
	//if (isBegin)
	{
		Nonce=99999,iTemp=0;
		isBegin=false;
	}
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	
	int nROund=rijndaelSetupEncrypt(ck,key,128);
//	int cipLen ;
//	datLen%16==0?cipLen=datLen/16:cipLen=datLen/16+1;
//	int size = cipLen*16;
	int j;
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
	return	true;
}
bool CBlockCipherProvider::CTRModeDecrypt(char *cipher,int cipherLen,char *Data )
{
	//0 khoi tao va khai bao
	unsigned char cipherArray[16],dataArray[16],ivArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupEncrypt(ck,key,128);
//	if (isBegin)
	{
		Nonce=99999,iTemp=0;
		isBegin=false;
	}
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	//int dataLen;
	//cipherLen%16==0?dataLen=cipherLen/16:dataLen=cipherLen/16+1;

	int j;
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
	return true;
}
bool CBlockCipherProvider::CBCEncrypt(char * data,int datLen,char *Cipher)
{

	//0 khoi tao va khai bao
	unsigned char datArray[16],cipArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupEncrypt(ck,key,128);
	int cipLen ;
	int i,j;
	datLen%16==0?cipLen=datLen/16:cipLen=datLen/16+1;
	if (isBegin)
	{
		Nonce=99999,iTemp=0;
		isBegin=false;
	};iTemp++;
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	//0 khoi tao cipher dau
	for (j=0;j<16;j++)
		{
			if (j<8)
				cipArray[j] = buffN[j];
			else
				cipArray[j] = buffT[j-8];;
			//cout<<j + i  << " :1: " << (int)ivArray[j] << "\n" ;
		}
	//1 tach du lieu 
	for ( i=0;i<datLen;i=i+16)
	{
		for ( j=0;j<16;j++)
		{
			if (i+j < datLen)
				datArray[j]=(unsigned char)data[i+j] ^ cipArray[j];
			else
				datArray[j]=0^ cipArray[j];
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
	return	true;
}
bool CBlockCipherProvider::CBCDecrypt(char *cipher,int size,char *Data )
{
	
	//0 khoi tao va khai bao
	unsigned char cipherArray[16],dataArray[16],XorArray[16];
	unsigned long ck [100];
	int nROund=rijndaelSetupDecrypt(ck,key,128);
	int cipherLen = size;
	int dataLen ;
	int i,j;
	cipherLen%16==0?dataLen=cipherLen/16:dataLen=cipherLen/16+1;
	if (isBegin)
	{
		Nonce=99999,iTemp=0;
		isBegin=false;
	};iTemp++;
	char *buffN = (char*) &Nonce;
	char *buffT = (char*) &iTemp;
	//0 khoi tao cipher dau
	for (j=0;j<16;j++)
		{
			if (j<8)
				XorArray[j] = buffN[j];
			else
				XorArray[j] = buffT[j-8];;
			//cout<<j + i  << " :1: " << (int)ivArray[j] << "\n" ;
		}
	//1 tach du lieu
	for (i=0;i<cipherLen;i=i+16)
	{
		for (j=0;j<16;j++)
		{
				cipherArray[j]=(unsigned char)cipher[i+j];
		}
	//2 ma hoa
		rijndaelDecrypt(ck,nROund,cipherArray,dataArray);
	//3 gom file ket qua
		for (int j=0;j<16;j++)
		{
			Data[i+j]=(char)(dataArray[j] ^XorArray[j]) ;
			XorArray[j]=cipherArray[j];
		}
	}
	return	true;
}