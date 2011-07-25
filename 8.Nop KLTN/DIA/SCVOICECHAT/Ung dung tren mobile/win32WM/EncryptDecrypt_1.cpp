// EncryptDecrypt_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StreamCipherProvider.h"
#include "BlockCipherProvider.h"
#include "iostream"
#define SIZE 200000
//char cipher1[50],cipher2[50],cipher3[50];
//char replaintext1[50],replaintext2[50],replaintext3[50];
int main(int argc, _TCHAR* argv[])
{
////////////DEMO STREAM CIPHER
/*	
	
	//ma hoa

	// hien thi van ban goc
	char *demo = "this is a demo";
	char *key = "key"; 
	std::cout << "Plaintext : \n\t";
	int i;
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)demo[i] << "\t";
	}
	// khoi tao trinh ma hoa
	CStreamCipherProvider scpTemp;
	scpTemp.Init(key);
	int len=strlen(demo)+1;
	// ma hoa va hien thi ket qua
	std::cout << "\nCiphertext 1 : \n\t";
	

	scpTemp.Encrypt(demo,len,cipher1);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher1[i] << "\t";
	}
	// ma hoa  lan 2 va hien thi ket qua
	std::cout << "\nCiphertext 2: \n\t";
	scpTemp.Encrypt(demo,len,cipher2);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher2[i] << "\t";
	}
	// ma hoa  lan 3 va hien thi ket qua
	std::cout << "\nCiphertext 3: \n\t";
	scpTemp.Encrypt(demo,len,cipher3);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher3[i] << "\t";
	}
	// giai ma
	CStreamCipherProvider scpTemp2;
	scpTemp2.Init(key);
	scpTemp2.Decrypt(cipher1,len,replaintext1);
	std::cout << "\nReplaintext : \n\t";
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext1[i] << "\t";
	}
	//Thu lai lan 2

	
	// giai ma lan 2
	scpTemp2.Decrypt(cipher2,len,replaintext2);
	std::cout << "\nReplaintext2: \n\t";
	
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext2[i] << "\t";
	}
	
	scpTemp2.Decrypt(cipher3,len,replaintext3);
	std::cout << "\nReplaintext2: \n\t";
	
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext3[i] << "\t";
	}
	std::cout<< replaintext3 <<"\n";
*/
/*

	//CZUC zuc;
	//std::cout << zuc.test();
////////////////DEMO BLOCK CIPHER////////////////////
	//b0 tao du lieu khoi tao
	char demo[SIZE];
	clock_t tBegin,tEnd;
	for(int i=0;i<SIZE;i++) 
		demo[i]=rand();
	char *key = "this is a demo for block cipher ,OK i will be repaired until to be right. Contact us :http://www.efgh.com/software/rijndael.htmfda "; 
	CBlockCipherProvider bcpTemp,bcpTemp2;
	CStreamCipherProvider scpTemp,scpTemp2;
	bcpTemp.Init(key);
	bcpTemp2.Init(key);
	scpTemp.Init(key);
	scpTemp2.Init(key);
	int size =SIZE;
	//b1 do thoi gian ma hoa
	int k = CLOCKS_PER_SEC;
	char cipher1[SIZE];
		//1.1 cua stream
	tBegin = clock();
		scpTemp.Encrypt(demo,size,cipher1);
		//1.2 cua block
	tEnd = clock();std::cout << tEnd-tBegin <<"\n";
	tBegin = clock();
		bcpTemp.CBCEncrypt(demo,size,cipher1);
	//b2 do thoi gian giai ma
		//1.1 cua stream
		tEnd = clock();std::cout << tEnd-tBegin <<"\n";
	tBegin = clock();
		scpTemp2.Decrypt(cipher1,size,demo );
		//1.2 cua block
	tEnd = clock();std::cout << tEnd-tBegin <<"\n";
	tBegin = clock();
		bcpTemp2.CBCDecrypt(cipher1,size,demo);
	tEnd = clock();std::cout << tEnd-tBegin <<"\n";
	tBegin = clock();
*/

  ///////////////////DEMO BLOCK CIPHER ///////////////////////////////////
/*
	 char demo[SIZE];
	for(int i=0;i<SIZE;i++) 
		demo[i]=rand();
	char *key = "this is a demo for block cipher ,OK i will be repaired until to be right. Contact us :http://www.efgh.com/software/rijndael.htmfda 3335265654642647846 "; 
	CBlockCipherProvider bcpTemp,bcpTemp2;
	CStreamCipherProvider scpTemp,scpTemp2;
	std::cout << "Plaintext : \n\t";
		int size=SIZE;
	for (i=0;i<size;i++)
	{
		std::cout << (int)demo[i] << "\t";
	}
	// khoi tao trinh ma hoa

	

	// ma hoa va hien thi ket qua
	std::cout << "\nCiphertext : \n\t";
	bcpTemp.Init(key);
	char cipher[100],replaintext[100],cipher2[100],replaintext2[100];
	//bcpTemp.CTRModeEncrypt(demo,size,cipher);
	bcpTemp.CBCEncrypt(demo,size,cipher);
	for (i=0;i<size;i++)
	{
		std::cout << (int)cipher[i] << "\t";
	}
	std::cout << "\nCiphertext 2 : \n\t";
	//bcpTemp.CTRModeEncrypt(demo,size,cipher2);
	bcpTemp.CBCEncrypt(demo,size,cipher2);
	for (i=0;i<size;i++)
	{
		std::cout << (int)cipher2[i] << "\t";
	}
	// giai ma
//	CBlockCipherProvider bcpTemp2;
	bcpTemp2.Init(key);

	//bcpTemp2.CTRModeEncrypt(cipher,size,replaintext );
	bcpTemp2.CBCDecrypt(cipher,size,replaintext );
	std::cout << "\nReplaintext : \n\t";
	for (i=0;i<size;i++)
	{
		std::cout << (int)replaintext[i] << "\t";
	}

	//bcpTemp2.CTRModeDecrypt(cipher2,size,replaintext2 );
	bcpTemp2.CBCDecrypt(cipher2,size,replaintext2 );
	std::cout << "\nReplaintext 2: \n\t";
	for (i=0;i<size;i++)
	{
		std::cout << (int)replaintext2[i] << "\t";
	}
	char a;
	std::cin>>a;*/	
////////////DEMO STREAM CIPHER CM mode 1.0 ///////////////////////////////////

	/*
	//ma hoa
	// hien thi van ban goc
	char *demo = "this is a demo";
	char *key = "key"; 
	std::cout << "Plaintext : \n\t";
	int i;
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)demo[i] << "\t";
	}
	// khoi tao trinh ma hoa
	CStreamCipherProvider scpTemp;
	scpTemp.CMInit(key);
	int len=strlen(demo)+1;
	// ma hoa va hien thi ket qua
	std::cout << "\nCiphertext 1 : \n\t";
	

	scpTemp.CMEncrypt(demo,len,cipher1);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher1[i] << "\t";
	}
	// ma hoa  lan 2 va hien thi ket qua
	std::cout << "\nCiphertext 2: \n\t";
	scpTemp.CMEncrypt(demo,len,cipher2);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher2[i] << "\t";
	}
	// ma hoa  lan 3 va hien thi ket qua
	std::cout << "\nCiphertext 3: \n\t";
	scpTemp.CMEncrypt(demo,len,cipher3);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher3[i] << "\t";
	}
	// giai ma
	CStreamCipherProvider scpTemp2;
	scpTemp2.CMInit(key);
	scpTemp2.CMDecrypt(cipher1,len,replaintext1);
	std::cout << "\nReplaintext : \n\t";
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext1[i] << "\t";
	}
	//Thu lai lan 2

	
	// giai ma lan 2
	scpTemp2.CMDecrypt(cipher2,len,replaintext2);
	std::cout << "\nReplaintext2: \n\t";
	
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext2[i] << "\t";
	}
	
	scpTemp2.CMDecrypt(cipher3,len,replaintext3);
	std::cout << "\nReplaintext2: \n\t";
	
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext3[i] << "\t";
	}
	std::cout<< replaintext3 <<"\n";
	return 0;
	*/
////////////DEMO STREAM CIPHER CM mode 1.1 ///////////////////////////////////
//b0 tao du lieu khoi tao
	char *demo			= new char [SIZE];
	char *replaintext1	= new char [SIZE];
	char *replaintext2	= new char [SIZE];
	char *cipher1		= new char [SIZE];
	char *cipher2		= new char [SIZE];
	clock_t tBegin,tEnd;
	for(int i=0;i<SIZE;i++) 
		demo[i]=rand();
	char *key = "this is a demo for block cipher ,OK i will be repaired until to be right. Contact us :http://www.efgh.com/software/rijndael.htmfda "; 
	CBlockCipherProvider bcpTemp,bcpTemp2;
	CStreamCipherProvider scpTemp,scpTemp2;
	bcpTemp.Init(key);
	bcpTemp2.Init(key);
	scpTemp.CMInit(key);
	scpTemp2.CMInit(key);
	int size =SIZE, iCount=0;
	int b1,b2,b3,b4;
	b1=b2=b3=b4=0;
	//b1 do thoi gian ma hoa
	int k = CLOCKS_PER_SEC;
//	for (int biendem=0;biendem<10000;biendem++)
	{

		//1.1 cua stream
	tBegin = clock();
		scpTemp.CMEncrypt(demo,size,cipher1);
		//1.2 cua block
	tEnd = clock();		b1= b1 +tEnd-tBegin ;
	tBegin = clock();
		bcpTemp.CBCEncrypt(demo,size,cipher2);
	//b2 do thoi gian giai ma
		//1.1 cua stream
	tEnd = clock();		b3= b3 +tEnd-tBegin ;
	tBegin = clock();
		scpTemp2.CMDecrypt(cipher1,size,replaintext1 );
		//1.2 cua block
	tEnd = clock();		b2= b2 +tEnd-tBegin ;
	tBegin = clock();
		bcpTemp2.CBCDecrypt(cipher2,size,replaintext2);
	tEnd = clock();		b4= b4 +tEnd-tBegin ;
	tBegin = clock();
	//3 kiem tra ket qua ma
	int iCount=0;
	for (i=0;i<SIZE;i++)
	{
		if (demo[i]!=replaintext1[i])
			iCount++;
	}
		/*for ( i=0;i<SIZE;i++)
		{
			std::cout << (int)demo[i] << "\t";
		}
		std::cout << "\n";
		for ( i=0;i<SIZE;i++)
		{
			std::cout << (int)replaintext1[i] << "\t";
		}*/
	}
	std::cout << b1 << "\t"<< b2 << "\t"<< b3 << "\t"<< b4 << "\t"<<iCount<<"\n";
	//std::cout << iCount <<"\n";
	return 0;

////////////KIEM TRA CAP PHAT ///////////////////////////////////
	/*char *a = new char [10000000];
	for (int i=0;i<10000000;i++)
		std::cout << (int)a[i] ;
	return 0;
	*/
}

