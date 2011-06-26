#include "stdafx.h"
#include "StreamCipherProvider.h"

CStreamCipherProvider::CStreamCipherProvider(void)
{
	isNew=false;
	iFlag=0;
}

CStreamCipherProvider::~CStreamCipherProvider(void)
{

}

unsigned int Mess  [51] ;
unsigned int Cipher[51];
bool WordPadding(char * s)
{
	//B1 kiem tra du lieu
	if (s==NULL)
		return false;
	int i;
	int len=strlen(s);
	//B2 kiem tra kich thuoc trong 
	int iPad = len % 4;
	//B3 chen them cac phan tu vao
	if (iPad>0)
	{
		for ( i=0;i<iPad-1;i++)
		{
			s[len+i]=0;
		}
		s[len+i]=iPad;
		s[len+i+1]='\0';
	}
	return true;
}
bool WordUnpadding(char * s)
{
	//B1 kiem tra du lieu
	if (s==NULL)
		return false;
	int len=strlen(s);
	//B2 kiem tra so phan tu da pad
	int iPad =  s[len-1];
	int i;
	//B3 kiem tra xem co dung la pad khong
	if (iPad>0)
	{
		for (i=1;i<iPad;i++)
		{
			if (s[len-1-i]!=0)
				return true;
		}
	}
	//B4 hieu chinh lai du lieu
	s[len-iPad]='\0';
	return true;
}

void char2u32(char *x,int len,unsigned int *output)
{

	int size;
	len %4==0?size=len/4:size=len/4+1;
	char *buff = (char*)output;
	for (int i=0;i<len;i=i+4)
	{
		for (int j=0;j<4;j++)
		{
			if (i+j<size*4)
				buff[i+j]=x[i+j];
			else
				buff[i+j]=0;
		}
	}
	return ;
}
void u322char(unsigned int *x,int size,char* output)
{
	char *buff = (char*)x;
	for (int i=0;i<size*4;i++)
	{
		output[i]=buff[i];
		
	}
	return ;
}
bool CStreamCipherProvider::Init(char* sharekey)
{
	char userkey[200];
	strcpy(userkey,sharekey);
	if (strlen(userkey)<16)
		strcat (userkey,"1234567890101112113141516");

	
	for (int i=0;i<30;i++)
	{
		key[i] = (unsigned char)(userkey[i]);
	}
	return	true;
}
bool CStreamCipherProvider::Encrypt(char * data,int datalen,char *result)
{
	//khoi tao
	unsigned int Count=1,Bearer=1,Direction=1;
	
	/*unsigned int *Mess= new unsigned int (dataLen);
	unsigned int *Cipher= new unsigned int (dataLen);
	char* cipher= new char(dataLen);*/
	int size;
	datalen %4==0?size=datalen/4:size=datalen/4+1;
	char2u32(data,datalen,Mess);	
	//ma hoa
	if (!isNew)
	{
		myZUC.EEA3(key,Count,Bearer,Direction,size*32,Mess,Cipher);
		isNew=true;
	}
	else
		myZUC.EEA3Next(size*32,Mess,Cipher);
	//tra ve ket qua
	/*for (int i=0;i<dataLen;i++)
	{
		cipher[i] = (char)Cipher[i];
	}*/
	u322char(Cipher,size,result);
	return	true;

}
bool CStreamCipherProvider::Decrypt(char *data ,int datalen,char *result)
{
	//khoi tao
	unsigned int Count=1,Bearer=1,Direction=1;
	
	/*unsigned int *Mess= new unsigned int (dataLen);
	unsigned int *Cipher= new unsigned int (dataLen);
	char* cipher= new char(dataLen);*/
	int size;
	datalen %4==0?size=datalen/4:size=datalen/4+1;
	char2u32(data,datalen,Mess);;
	
	//ma hoa
	if (!isNew)
	{
		myZUC.EEA3(key,Count,Bearer,Direction,size*32,Mess,Cipher);
		isNew=true;
	}
	else
		myZUC.EEA3Next(size*32,Mess,Cipher);
	//tra ve ket qua
	/*for (int i=0;i<dataLen;i++)
	{
		cipher[i] = (char)Cipher[i];
	}*/
	u322char(Cipher,size,result);
	return	true;
}


bool CStreamCipherProvider::EncryptNext(char * data,int datalen,char *result)
{
	//khoi tao
	unsigned int Count=1,Bearer=1,Direction=1;
	
	/*unsigned int *Mess= new unsigned int (dataLen);
	unsigned int *Cipher= new unsigned int (dataLen);
	char* cipher= new char(dataLen);*/
	int size;
	datalen %4==0?size=datalen/4:size=datalen/4+1;
	char2u32(data,datalen,Mess);	
	//ma hoa
	myZUC.EEA3Next(size*32,Mess,Cipher);
	//tra ve ket qua
	/*for (int i=0;i<dataLen;i++)
	{
		cipher[i] = (char)Cipher[i];
	}*/
	u322char(Cipher,size,result);
	return	true;

}
bool CStreamCipherProvider::DecryptNext(char *data ,int datalen,char *result)
{
	//khoi tao
	unsigned int Count=1,Bearer=1,Direction=1;
	
	/*unsigned int *Mess= new unsigned int (dataLen);
	unsigned int *Cipher= new unsigned int (dataLen);
	char* cipher= new char(dataLen);*/
	int size;
	datalen %4==0?size=datalen/4:size=datalen/4+1;
	char2u32(data,datalen,Mess);;
	
	//ma hoa
	myZUC.EEA3Next(size*32,Mess,Cipher);
	//tra ve ket qua
	/*for (int i=0;i<dataLen;i++)
	{
		cipher[i] = (char)Cipher[i];
	}*/
	u322char(Cipher,size,result);
	return	true;
}

bool CStreamCipherProvider::CMInit(char* sharekey)
{
	char userkey[200];
	strcpy(userkey,sharekey);
	if (strlen(userkey)<16)
		strcat (userkey,"1234567890101112113141516");
	buffer1= new CZUCBuffer;
	buffer2= new CZUCBuffer;
	buffer1->data= new u32 [Buffer_Max/4];
	buffer2->data= new u32 [Buffer_Max/4];
	for (int i=0;i<30;i++)
	{
		key[i] = (unsigned char)(userkey[i]);
	}
	
	unsigned int Count=1,Bearer=1,Direction=1;
	myZUC.MakeKeystream(key,Count,Bearer,Direction,Buffer_Max*8,buffer1->data);
	myZUC.MakeNextKeystream(Buffer_Max*8,buffer2->data);
	bufferIndex = buffer1;
	iUsingCounter=0;
	return	true;
}
bool CStreamCipherProvider::CMEncrypt(char * data,int datalen,char *result)
{
	//B1: khoi tao

	int iCount=0;
	char *ByteBuffer = ( char *)bufferIndex->data;
	//B2: xet tung vong cho den khi het du lieu
	while (iCount<datalen)
	{
	//B3 lay byte tuong ung o streamcipher
		result[iCount]=data[iCount]^ByteBuffer[iFlag];
		iFlag++;	
		if (iFlag == Buffer_Max)
			iFlag=0;
		iCount++;
		iUsingCounter++;
		if (iUsingCounter==Max_Counter)
		{
			bufferIndex = buffer2;
			ByteBuffer = ( char *)bufferIndex->data ;
		}
	}
	return	true;

}
bool CStreamCipherProvider::CMDecrypt(char *data ,int datalen,char *result)
{
	//B1: khoi tao

	int iCount=0;
	char *ByteBuffer = ( char *)bufferIndex->data;
	//B2: xet tung vong cho den khi het du lieu
	while (iCount<datalen)
	{
	//B3 lay byte tuong ung o streamcipher
		result[iCount]=data[iCount]^ByteBuffer[iFlag];
		iFlag++;	
		if (iFlag == Buffer_Max)
			iFlag=0;
		iCount++;
		iUsingCounter++;
		if (iUsingCounter==Max_Counter)
		{
			bufferIndex = buffer2;
			ByteBuffer = ( char *)bufferIndex->data ;
		}
	}
	return	true;

}