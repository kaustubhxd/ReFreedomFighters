#include "ff.h"
extern "C" void THISCALL ext_56eb60(void*,void*);
extern "C" void THISCALL ext_56ed00(void*,void*);
static u8* THISCALL fn56e9d0(u8*s,u8*src){
 for(int i=0;i<0x86;i++)s[i]=src[i];
 for(int i=0x86;i<0x35a;i+=4)*(u32*)(s+i)=*(u32*)(src+i);
 ext_56eb60(s+0x35a,src+0x35a);ext_56ed00(s+0x4b8,src+0x4b8);
 for(int i=0xe1c;i<0xe84;i+=4)*(u32*)(s+i)=*(u32*)(src+i);
 *(u32*)(s+0xe88)=*(u32*)(src+0xe88);
 for(int i=0;i<19;i++){u32 off=0xe8c+i*0x12;_mm_storeu_si128((__m128i*)(s+off),_mm_loadu_si128((__m128i*)(src+off)));*(u16*)(s+off+16)=*(u16*)(src+off+16);}
 return s;
}
PCREG(56e9d0,fn56e9d0);
