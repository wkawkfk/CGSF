#include "StdAfx.h"
#include "SFCompressLzf.h"
#include <lzf.h>

SFCompressLzf::SFCompressLzf(void)
{
}

SFCompressLzf::~SFCompressLzf(void)
{
}

BOOL SFCompressLzf::Compress(BYTE* pDest, int& DestLen, BYTE* pSrc, int SrcLen)
{
	int Size = lzf_compress(pSrc, SrcLen, pDest, DestLen);
	DestLen = Size;
	//int Result = fastlz_compress_level(2, (pSrc, SrcLen, pDest, DestLen);		
		
	return Size > 0;
}

BOOL SFCompressLzf::Uncompress(BYTE* pDest, int& DestLen, BYTE* pSrc, int SrcLen)
{
	int Size = lzf_decompress(pSrc, SrcLen, pDest, DestLen); 
	DestLen = Size;
	//intfastlz_compress_level(int level, const void* input, int length, void* output);

	return Size > 0;
}