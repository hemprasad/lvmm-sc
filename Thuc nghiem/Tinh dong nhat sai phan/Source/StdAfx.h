// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once


#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>
typedef unsigned char u8;
bool buildSbox(char *file,u8 *S);
int test(u8 *S);
// TODO: reference addit;ional headers your program requires here
