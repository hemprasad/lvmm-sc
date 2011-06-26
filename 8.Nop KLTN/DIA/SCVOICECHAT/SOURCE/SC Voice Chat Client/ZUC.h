#pragma once

#ifndef H__ZUC
#define H__ZUC
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
typedef unsigned char u8;
typedef unsigned int u32;

class CZUC
{
public:
	/* the state registers of LFSR */
	~CZUC(void);
	CZUC(void);
	u32 LFSR_S0;
	u32 LFSR_S1;
	u32 LFSR_S2;
	u32 LFSR_S3;
	u32 LFSR_S4;
	u32 LFSR_S5;
	u32 LFSR_S6;
	u32 LFSR_S7;
	u32 LFSR_S8;
	u32 LFSR_S9;
	u32 LFSR_S10;
	u32 LFSR_S11;
	u32 LFSR_S12;
	u32 LFSR_S13;
	u32 LFSR_S14;
	u32 LFSR_S15;
	/* the registers of F */
	u32 F_R1;
	u32 F_R2;
	/* the outputs of BitReorganization */
	u32 BRC_X0;
	u32 BRC_X1;
	u32 BRC_X2;
	u32 BRC_X3;
	void EEA3Next(u32 LENGTH,u32* M,u32* C);
	void Initialization(u8* k, u8* iv);
	void GenerateKeystream(u32* pKeystream, int KeystreamLen);
	void EEA3(u8* CK,u32 COUNT,u32 BEARER,u32 DIRECTION,u32 LENGTH,u32* M,u32* C);
	void ZUC(u8* k, u8* iv, u32* ks, int len);
	void ZUCNext( u32* ks, int len);
	void LFSRWithInitialisationMode(u32 u);
	void LFSRWithWorkMode();
	void BitReorganization();
	u32 F();
	int test();
	void MakeKeystream(u8* CK,u32 COUNT,u32 BEARER,u32 DIRECTION,u32 LENGTH,u32* C);
	void MakeNextKeystream(u32 LENGTH,u32* Keystream);
};

#endif