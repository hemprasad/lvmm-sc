// EncryptDecrypt_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StreamCipherProvider.h"
#include "BlockCipherProvider.h"
#include "iostream"


int main(int argc, _TCHAR* argv[])
{
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
	std::cout << "\nCiphertext : \n\t";
	int size,size2,size3;
	scpTemp.Encrypt(demo,len);
/*	char* cipher = scpTemp.Encrypt(demo,len);
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher[i] << "\t";
	}
	// ma hoa  lan 2 va hien thi ket qua
	std::cout << "\nCiphertext 2: \n\t";
	char *cipher2 = scpTemp.EncryptNext(demo,len);
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher2[i] << "\t";
	}
	// ma hoa  lan 3 va hien thi ket qua
	std::cout << "\nCiphertext 3: \n\t";
	char *cipher3 = scpTemp.EncryptNext(demo,len);
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)cipher3[i] << "\t";
	}
	// giai ma
	CStreamCipherProvider scpTemp2;
	scpTemp2.Init(key);
	char* replaintext = scpTemp2.Decrypt(cipher,len);
	std::cout << "\nReplaintext : \n\t";
	
	for (i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext[i] << "\t";
	}
	//Thu lai lan 2

	
	// giai ma lan 2
	char*	replaintext2= scpTemp2.DecryptNext(cipher2,len);
	std::cout << "\nReplaintext2: \n\t";
	
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext2[i] << "\t";
	}
	
	char*	replaintext3= scpTemp2.DecryptNext(cipher3,len);
	std::cout << "\nReplaintext2: \n\t";
	
	for ( i=0;i<strlen(demo);i++)
	{
		std::cout << (int)replaintext3[i] << "\t";
	}
	std::cout<< replaintext3 <<"\n";

	*/

	//char *demo = "this is a demo for block cipher , i will be repaired until to be right";
	//char *key = "this is a demo for block cipher ,OK i will be repaired until to be right. Contact us :http://www.efgh.com/software/rijndael.htm "; 
	//std::cout << "Plaintext : \n\t";
	//for (int i=0;i<strlen(demo);i++)
	//{
	//	std::cout << (int)demo[i] << "\t";
	//}
	//// khoi tao trinh ma hoa
	//CBlockCipherProvider bcpTemp;
	//bcpTemp.Init(key);
	//// ma hoa va hien thi ket qua
	//std::cout << "\nCiphertext : \n\t";
	//int size;

	//char* cipher = bcpTemp.CTRModeEncrypt(demo,size);
	//for (int i=0;i<strlen(demo);i++)
	//{
	//	std::cout << (int)cipher[i] << "\t";
	//}
	//// giai ma
	//char* replaintext = bcpTemp.CTRModeDecrypt(cipher,size);
	//std::cout << "\nReplaintext : \n\t";
	//for (int i=0;i<size;i++)
	//{
	//	std::cout << (int)replaintext[i] << "\t";
	//}
	//char a;
	//std::cin>>a;

	//delete cipher;
	//delete cipher2;
	//delete cipher3;
	//delete replaintext;
	//delete replaintext2;
	return 0;
}

