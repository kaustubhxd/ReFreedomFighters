#include "ff.h"
extern "C" void THISCALL ext_4e0d80(void*,float);
extern "C" void THISCALL ext_5ceed0(void*,void*,void*,void*,u32,u32,u32);
extern "C" long double FASTCALL ext_4e0870(void*,void*);
extern "C" void THISCALL ext_5cefc0(void*,void*,void*,float,u32);
static u8 THISCALL aim(u8* me,u32* output){
 float length=(float)(vcall<long double>(G(void*,me+0xb54),0xac)+(long double)G(float,0x6b4fc4));
 ext_4e0d80(me+0xa72,length);ext_5ceed0(me,me+0xa7e,me+0xcad,me+0xa72,0x10,1,0);
 float distance=(float)ext_4e0870(me+0xa7e,me+0xcad);if(distance>length-G(float,0x67cd40))return 0;
 for(int i=0;i<3;++i)G(u32,me+0xa8a+4*i)=G(u32,me+0xa7e +4*i);
 ext_5cefc0(me,me+0xa8a,me+0xa72,50.0f,2);
 for(int i=0;i<3;++i)output[i]=G(u32,me+0xa8a+4*i);return 1;
}
PCREG(5cfa00,aim);
