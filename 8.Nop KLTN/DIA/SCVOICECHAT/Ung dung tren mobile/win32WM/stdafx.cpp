// stdafx.cpp : source file that includes just the standard includes
// win32WM.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information



#include "stdafx.h"
#include "winbase.h"
#include "StreamCipherProvider.h"
#include "BlockCipherProvider.h"

#include "iostream"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
using namespace std;
int demo(int &v1,int &v2,int &v3, int &v4)
{
	int ncount=1;
	double b1,b2,b3,b4;
	char *demo			= new char [MYSIZE];
	char *demo2			= new char [MYSIZE+20];
	/*char *replaintext2	= new char [MYSIZE+20];
	char *cipher1		= new char [MYSIZE+20];
	char *cipher2		= new char [MYSIZE+20];*/
	for(int i=0;i<MYSIZE;i++) 
		demo[i]=rand();
	char *key = "this is a demo for block cipher ,OK i will be repaired until to be right. Contact us :http://www.efgh.com/software/rijndael.htmfda "; 
	CBlockCipherProvider bcpTemp,bcpTemp2;
	CStreamCipherProvider scpTemp,scpTemp2;
	bcpTemp.Init(key);
	bcpTemp2.Init(key);
	scpTemp.CMInit(key);
	scpTemp2.CMInit(key);
	int size =MYSIZE, iCount=0;
	//int b1,b2,b3,b4;
	b1=b2=b3=b4=0;
	//b1 do thoi gian ma hoa
	int k = CLOCKS_PER_SEC;
	LARGE_INTEGER tBegin,tEnd;
	for (int biendem=0;biendem<ncount;biendem++)
	{
		for(int i=0;i<MYSIZE;i++) 
			demo[i]=rand();
//		//1.1 cua stream
		//int a = timeGetTime();
		LARGE_INTEGER Frequency;	
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&tBegin);
			scpTemp.CMEncrypt(demo,size,demo2);	
		QueryPerformanceCounter(&tEnd);		b1= b1 +((double)(tEnd.QuadPart - tBegin.QuadPart) * 1000.0 / (double) Frequency.QuadPart) ;
		
		QueryPerformanceCounter(&tBegin);
			scpTemp2.CMDecrypt(demo2,size,demo );
		QueryPerformanceCounter(&tEnd);		b2= b2 +((double)(tEnd.QuadPart - tBegin.QuadPart) * 1000.0 / (double) Frequency.QuadPart) ;
		
		QueryPerformanceCounter(&tBegin);
			bcpTemp.CTRModeEncrypt(demo,size,demo2);;
		QueryPerformanceCounter(&tEnd);		b3= b3 +((double)(tEnd.QuadPart - tBegin.QuadPart) * 1000.0 / (double) Frequency.QuadPart);
		
		QueryPerformanceCounter(&tBegin);
			bcpTemp2.CTRModeDecrypt(demo2,size,demo);
		QueryPerformanceCounter(&tEnd);		b4= b4 +((double)(tEnd.QuadPart - tBegin.QuadPart) * 1000.0 / (double) Frequency.QuadPart) ;
		//QueryPerformanceCounter(&tBegin);
	}
	v1=b1/ncount;
	v2=b2/ncount;
	v3=b3/ncount;
	v4=b4/ncount;
	return  0;
}