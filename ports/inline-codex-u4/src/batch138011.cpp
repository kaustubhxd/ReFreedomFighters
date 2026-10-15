#include "ff.h"
static u8* THISCALL copySettings(u8* dst,u8* src){
 *(u32*)(dst+4)=*(u32*)(src+4);
 for(int i=8;i<0x48;++i)*(volatile u8*)(dst+i)=*(volatile u8*)(src+i);
 for(int i=0x48;i<0x50;++i)*(volatile u8*)(dst+i)=*(volatile u8*)(src+i);
 for(int i=0x50;i<0x64;i+=4)*(volatile u32*)(dst+i)=*(volatile u32*)(src+i);
 for(int i=0x64;i<0x6a;++i)*(volatile u8*)(dst+i)=*(volatile u8*)(src+i);
 for(int i=0x6a;i<0xbe;i+=4)*(volatile u32*)(dst+i)=*(volatile u32*)(src+i);
 for(int i=0xbe;i<0x15e;i+=16)_mm_storeu_si128((__m128i*)(dst+i),_mm_loadu_si128((const __m128i*)(src+i)));
 return dst;
}
PCREG(56eb60,copySettings);
