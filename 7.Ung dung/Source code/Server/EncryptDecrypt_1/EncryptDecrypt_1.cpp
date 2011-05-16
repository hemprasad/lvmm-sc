// EncryptDecrypt_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StreamCipherProvider.h"
#include "BlockCipherProvider.h"
#include "iostream"
char cipher1[50],cipher2[50],cipher3[50];
char replaintext1[50],replaintext2[50],replaintext3[50];
int main(int argc, _TCHAR* argv[])
{

	
	
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

