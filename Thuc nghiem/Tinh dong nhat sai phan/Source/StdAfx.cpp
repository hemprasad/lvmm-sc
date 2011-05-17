// stdafx.cpp : source file that includes just the standard includes
// EncryptDecrypt_1.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
u8 char2u8 (char x,char y)
{
	//doc du lieu tu x va y va luu vao gia tri
	u8 a,b;
	//B1 kiem tra phai la chu
	if (x>=65 && x<= 70)
		a=x-65+10;
	else if (x>=48&&x<=57)
		a=x-48;
	else
		return 0;
	if (y>=65 && y<= 70)
		b=y-65+10;
	else if (y>=48&&y<=57)
		b=y-48;
	else
		return 0;
	return 16*a+b;
	//B2 kiem tra phai la so

	//3 loi tra ve 0

	//B4 tra ve ket qua
}
bool buildSbox(char *file,u8 *S)
{
	//b0 khai bao
	FILE *f = fopen(file,"rt");
	if (f==NULL)
		return false;
	int wi,hi;
	char c1,c2;
	//b1 nhap sbox
	u8 SBox[16][16];
	for (int i=0;i<16;i++)
		for (int j=0;j<16;j++)
		{
			do{
			fscanf(f,"%c",&c1);
			}
			while (c1==9 ||c1==32 || c1==13 || c1==10);
			fscanf(f,"%c",&c2);
			SBox[i][j]=char2u8(c1,c2);
			int k=0;
		}
	//b2 tao thanh mang 256 phan tu
	for (int i=0;i<256;i++)
	{
		wi = i & 0x0F ;
		hi = (i>>4) & 0x0F ;
		S[i]= SBox[hi][wi];
	}
	fclose(f);
	return true;
}
int test(u8 *S0)
{
	//kiem tra tinh dong nhat sai phan cua sbox S0
	//khoi tao cac gia tri
	u8 a=1,b,max=0,count=0;
	int i,j,k,iTemp;
	for (i=1;i<255;i++)
	{
		b=0;
		for (j=0;j<255;j++)
		{
			for (k=0;k<255;k++)
			{
				u8 cTemp = a ^ k;
					//iTemp=(a+k)%256;
					char x1 =(char)S0[cTemp];
					char x2 = (char)S0[k];
					char x3 = (char)b;
					//if ((S0[iTemp]-S0[k])%256==b)
					if ((x1^x2)==x3)
					{	
						count++;	
					}
				
			}
			if (count > max)
				max = count;
			count=0;
			b++;
		}
		a++;
	}
	return max;
}